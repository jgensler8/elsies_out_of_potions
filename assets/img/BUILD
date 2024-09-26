filegroup(
    name = "backgrounds_and_sprites",
    srcs = [
        # unbanked
        # "font.png",
    ]
    + glob(["bg_title_bo1.png", "bg_end_screen_bo1.png", "sp_cursor_bo1.png", "sp_start_bo1.png"])
    + glob(["bg_intro_cutscene_bo2_*.png"])
    + glob(["bg_intro_cutscene_cont_bo3_*.png"])
    + glob(["bg_elsie_bo4.png", "sp_elsie_*_bo4_*.png"])
    + glob(["sp_icon_*_bo5_*.png"])
    + ["bg_headings_bo5_{}.png".format(i) for i in range(1,10+1)]
    + glob(["bg_search_result_text_bo6_*.png", "bg_potion_headers_bo6_*.png", "bg_potion_completed_bo6_*.png", "sp_icon_*_bo6_*.png"])
    + ["bg_items_screen_text_bo7_{}.png".format(i) for i in range(1,5+1)]
    + ["bg_potion_names_bo7_{}.png".format(i) for i in range(1,6+1)]
    + ["bg_quest_screen_text_bo7_{}.png".format(i) for i in range(1,3+1)]
    + ["bg_resource_names_bo7_{}.png".format(i) for i in range(1,10+1)]
    + ["bg_resource_numbers_bo7_{}.png".format(i) for i in range(1,4+1)]
    + glob(["bg_orchard_text_bo8_*.png"])
    + glob(["bg_orchard_delivery_2_text_bo9_*.png"])
    + glob(["bg_orchard_delivery_3_text_bo10_*.png"])
    + glob(["bg_river_delivery_1_text_bo11_*.png"])
    + glob(["bg_river_delivery_2_text_bo12_*.png"])
    + glob(["bg_graveyard_delivery_1_text_bo13_*.png"])
    + glob(["bg_witch_*_bo14.png"])
     ,
    visibility = ["//assets:__pkg__"],
)