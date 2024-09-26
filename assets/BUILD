load("//src/platform/gameboy:rules.bzl", "gameboy_assets")

gameboy_assets(
    name = "my_assets_gameboy",
    srcs = [
        "//assets/img:backgrounds_and_sprites",
        # "//assets/music:hUGETracker",
    ],
    gbdk_bin = "/home/jgens/Downloads/gbdk/bin",
    executable_extension=".exe",
    visibility = ["//visibility:public"],
)

# genrule(
#     name = "png2asset_map_test",
#     srcs = [
#         "//assets/img:temp_small_sprites",
#     ],
#     outs = [
#         "bg_title_0.c",
#         "bg_title_0.h",
#     ],
#     cmd = "python src/platform/gameboy/png2asset_map.py --out_dir $(GENDIR)/assets --inputs $(SRCS)",
#     tools = [
#         "//src/platform/gameboy:png2asset",
#     ],
# )

# filegroup(
#     name = "combined_gb_assets",
#     srcs = [
#         # ":my_assets_gameboy",
#         ":png2asset_map_test",
#     ],
#     visibility = ["//visibility:public"],
# )