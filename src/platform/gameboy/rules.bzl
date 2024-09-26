def _gameboy_rom_impl(ctx):
    rom_file = ctx.actions.declare_file(ctx.label.name + ".gb")
    map_file = ctx.actions.declare_file(ctx.label.name + ".map")
    lcc = "lcc"
    romusage = "romusage"
    if ctx.attr.gbdk_bin:
        lcc = ctx.attr.gbdk_bin + "/" + lcc
        romusage = ctx.attr.gbdk_bin + "/" + romusage
    lcc += ctx.attr.executable_extension
    romusage += ctx.attr.executable_extension
    asset_include = ""
    asset_sources = []
    for asset in ctx.attr.assets.files.to_list():
        if asset.path.endswith(".c"):
            asset_sources.append(asset.path)
        else:
            if asset.path.endswith(".h"):
                asset_include += " -I" + asset.dirname + " "
            else:
                asset_sources.append(asset.path + "/*.c")
                asset_include += " -I" + asset.path + " "
    # asset_dir = ctx.attr.assets.files.to_list()[0]
    color_args = "-Wa-l -Wl-m -Wm-yc"
    # Note: -Wi-e does not error out if rom banks span from one to another
    # TODO: maybe add -Wf--Werror
    # InsideGadgets sells a cart with the following:
    # ROM: 2MB Flash (I assume this is ~128 15kb banks, 64 to be safe)
    # FRAM: 32KB (FM18W08) (I assume this is 2 15kb banks, 1 to be safe)
    bank_args = "-Wm-yo{rom_banks} -Wm-ya{ram_banks} -Wm-yt0x1A".format(rom_banks=64, ram_banks=1)
    hugedriver_args = ""
    hugedriver_lib = ""
    hugedriver_include = ""
    if ctx.attr.enable_hugedriver:
        hugedriver_args = "-DHUGEDRIVER_INCLUDED=1"
        hugedriver_lib = "{hugedriver_root}/gbdk/hUGEDriver.lib".format(ctx.attr.hugedriver_root)
        hugedriver_include = "-I{hugedriver_root}/include".format(ctx.attr.hugedriver_root)
    ctx.actions.run_shell(
        inputs=ctx.files.srcs + ctx.files.includes + ctx.attr.assets.files.to_list(),
        outputs=[rom_file, map_file],
        use_default_shell_env=True,
        command="{lcc} {color_args} {bank_args} {hugedriver_args} -v -o {rom_file} {hugedriver_include} {asset_include} {hugedriver_lib} {srcs} {asset_sources} && {romusage} {map_file} -R".format(
            lcc=lcc,
            color_args=color_args,
            bank_args=bank_args,
            rom_file=rom_file.path,
            hugedriver_args=hugedriver_args,
            hugedriver_include=hugedriver_include,
            hugedriver_lib=hugedriver_lib,
            asset_include=asset_include,
            asset_sources=" ".join(asset_sources),
            srcs=" ".join([f.path for f in ctx.files.srcs]),
            romusage=romusage,
            map_file=map_file.path,
        ),
    )
    return [DefaultInfo(
        files=depset([rom_file])
    )]

gameboy_rom = rule(
    implementation = _gameboy_rom_impl,
    attrs = {
        "srcs": attr.label_list(allow_files=True),
        "includes": attr.label_list(allow_files=True),
        "assets": attr.label(allow_files=True),
        "gbdk_bin": attr.string(default=""),
        "enable_hugedriver": attr.bool(default=False),
        "hugedriver_root": attr.string(default=""),
        "executable_extension": attr.string(default=""),
    }
)

# seems that -spr8x16 is ignored when using -map
PNG2ASSET_COMMAND = "{png2asset} {in_file} {bank_args} -map -keep_palette_order -bpp 2 -max_palettes 1 -pack_mode gb -o {c_file}"
PNG2ASSET_MV_COMMAND = "mv {h_file} {include_dir}"

def _gameboy_assets_impl(ctx):
    png2asset = "png2asset"
    if ctx.attr.gbdk_bin:
        png2asset = ctx.attr.gbdk_bin + "/" + "png2asset"
    png2asset += ctx.attr.executable_extension
    include_dir_name = "gameboy_include"
    include_dir = ctx.actions.declare_directory(include_dir_name)
    gen_and_mv_cmds = []
    for file in ctx.files.srcs:
        bank_args = ""
        if file.path.endswith(".c") or file.path.endswith(".h"):
            gen_and_mv_cmds.append("cp {file} {include_dir}".format(
                file=file.path,
                include_dir=include_dir.path,
            ))
            continue
        if not file.path.endswith(".png"):
            continue
        file_root = file.basename.strip("." + file.extension)
        for bank in range(1,256):
            if "_bo{}_".format(bank) in file.basename or "_bo{}.".format(bank) in file.basename:
                bank_args = " -b {} ".format(bank)
        gen_and_mv_cmds.append(
            PNG2ASSET_COMMAND.format(
                png2asset=png2asset,
                in_file=file.path,
                bank_args=bank_args,
                c_file=include_dir.path + "/" + file_root + ".c",
            )
            + " && " + 
            PNG2ASSET_MV_COMMAND.format(
                h_file=include_dir.path + "/" + file_root + ".h",
                include_dir=include_dir.path,
            )
        )
    ctx.actions.run_shell(
        inputs=ctx.files.srcs,
        outputs=[include_dir],
        use_default_shell_env=True,
        command="""
        mkdir -p {include_dir} &&
        {gen_and_mv_cmds} 
        """.format(
            include_dir=include_dir.path,
            gen_and_mv_cmds=" && ".join(gen_and_mv_cmds),
        ),
    )
    return [DefaultInfo(
        files=depset([include_dir])
    )]

gameboy_assets = rule(
    implementation = _gameboy_assets_impl,
    attrs = {
        "srcs": attr.label_list(allow_files=True),
        "gbdk_bin": attr.string(default=""),
        "executable_extension": attr.string(default=""),
    }
)