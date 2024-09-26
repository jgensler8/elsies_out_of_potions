load("//src/platform/gameboy:rules.bzl", "gameboy_rom")

gameboy_rom(
    name = "my_rom",
    srcs = [
        # "sound.c",
        # "text.c",
        "scene.c",
        "scene_title_bo1.c",
        "scene_intro_cutscene_bo2.c",
        "scene_intro_cutscene_cont_bo3.c",
        "scene_elsie_bo4.c",
        "scene_navigation_menus_bo5.c",
        "scene_navigation_menus_bo6.c",
        "scene_navigation_menus_bo7.c",
        "scene_orchard_bo8.c",
        "scene_orchard_bo9.c",
        "scene_orchard_bo10.c",
        "scene_river_bo11.c",
        "scene_river_bo12.c",
        "scene_graveyard_bo13.c",
        "scene_witch_bo14.c",
        "state.c",
        "gb.c",
    ],
    includes = [
        "types.h",
        "state.h",
        "scene.h",
        "scene_title_bo1.h",
        "scene_intro_cutscene_bo2.h",
        "scene_intro_cutscene_cont_bo3.h",
        "scene_elsie_bo4.h",
        "scene_navigation_menus_bo5.h",
        "scene_navigation_menus_bo6.h",
        "scene_navigation_menus_bo7.h",
        "scene_orchard_bo8.h",
        "scene_orchard_bo9.h",
        "scene_orchard_bo10.h",
        "scene_river_bo11.h",
        "scene_river_bo12.h",
        "scene_graveyard_bo13.h",
        "scene_witch_bo14.h",
    ],
    assets = "//assets:my_assets_gameboy",
    # assets = "//assets:combined_gb_assets",
    gbdk_bin = "/home/jgens/Downloads/gbdk/bin",
    enable_hugedriver = False,
    hugedriver_root ="/home/jgens/Downloads/hUGEDriver-6.1.3",
    executable_extension=".exe",
)

sh_binary(
    name = "mgba_my_rom",
    srcs = ["run_mgba.sh"],  # Path to the script
    args = ["C:/Users/jgens/Downloads/bazel-gba-example/source/c-clang/bazel-bin/$(location :my_rom)"],  # Pass the ROM file as an argument
    data = [":my_rom"],  # Ensure the ROM is available
)