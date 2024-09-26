# Elsie's Out Of Potions

A gameboy game build for [GB Jam 12](https://itch.io/jam/gbjam-12)

[Play the game here!](https://jeffzzq.itch.io/elsies-out-of-potions)

## License

Shield: [![CC BY-NC 4.0][cc-by-nc-shield]][cc-by-nc]

This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License][cc-by-nc].

[![CC BY-NC 4.0][cc-by-nc-image]][cc-by-nc]

[cc-by-nc]: https://creativecommons.org/licenses/by-nc/4.0/
[cc-by-nc-image]: https://licensebuttons.net/l/by-nc/4.0/88x31.png
[cc-by-nc-shield]: https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg

## dependencies

* `bazel` itself

Note: there are NOT managed by the build system

* optional: `npm` (for ibazel watcher)
* a shell that supports `cp`

Optional: (if you want to modify `png2asset_map.py` and create more efficient tile packing/mapping)

* `python` (with `pillow` package) (for building asset.c and asset.h)

WARNING: I noticed some shell commands were using msys included with devkitpro. you may also encounter problems if bazel ends up using powershell for some commands instead of a bash-like shell. 

## building

1.

Usually, one would properly create the http_archives / git_repo for dependencies (gbdk, hugedriver, and mgba in this case). I didn't do that, so you'll have to download on your own and fix the paths in a few places.

* anywhere with `C:/Users/jgens/...`
* `src/BUILD`: change `hugedriver_root` and `gbdk_root`, also change `executable_extension` if you aren't on Windows.

2.

you will need to generate pngs from the aseprite files (~50 of them).

* open file
* `Export` > `Export as`
* change extension to `png` (default is gif)
* export and accept the default frame sequencing (*1.png, *2.png, etc...)

sorry, I didn't want to commit these images to the repo, seemed like a waste of space.

3. 

to build only the rom assets:

```
bazel build //assets:my_assets_gameboy
```

to only build the rom (depends on assets):

```
bazel build //src:my_rom
```

to run the rom after building:

```
bazel run //src:mgba_my_rom
```

note: because this is a build system, using the run command will automatically build the dependencies (the rom in this case)

4. (optional: use ibazel watcher to watch and compile+relaunch the game in mgba when done compiling)

```
npm run watch-gb
```

(this will run `npx ibazel run //src:mgba_my_rom`. ibazel is installed via npm )

## notes

music (trip world): https://www.youtube.com/watch?v=qjeegy-jvGM&list=PL939FB4B1F1A6EE11p

font: https://www.dafont.com/daydream-3.font

color picker: https://rgbcolorpicker.com/565

## reference

* Metal Walker: good character portaits
* legend of the river king (good splash/start screen)
* Lufia: The Legend Returns (large text window + character name, cure char sprites)
* great greed: char portaits
* Bakukyuu Renpatsu


## Final ROM Usage

```
Bank         Range                Size     Used  Used%     Free  Free%
--------     ----------------  -------  -------  -----  -------  -----
ROM_0        0x0000 -> 0x3FFF    16384    13392    82%     2992    18%
ROM_1        0x4000 -> 0x7FFF    16384     6443    39%     9941    61%
ROM_2        0x4000 -> 0x7FFF    16384    10545    64%     5839    36%
ROM_3        0x4000 -> 0x7FFF    16384    15465    94%      919     6%
ROM_4        0x4000 -> 0x7FFF    16384    12652    77%     3732    23%
ROM_5        0x4000 -> 0x7FFF    16384    14222    87%     2162    13%
ROM_6        0x4000 -> 0x7FFF    16384    11069    68%     5315    32%
ROM_7        0x4000 -> 0x7FFF    16384    15471    94%      913     6%
ROM_8        0x4000 -> 0x7FFF    16384    14233    87%     2151    13%
ROM_9        0x4000 -> 0x7FFF    16384    11251    69%     5133    31%
ROM_10       0x4000 -> 0x7FFF    16384    13539    83%     2845    17%
ROM_11       0x4000 -> 0x7FFF    16384    11957    73%     4427    27%
ROM_12       0x4000 -> 0x7FFF    16384    11125    68%     5259    32%
ROM_13       0x4000 -> 0x7FFF    16384    12265    75%     4119    25%
ROM_14       0x4000 -> 0x7FFF    16384     5468    33%    10916    67%
WRAM_LO      0xC000 -> 0xCFFF     4096      264     6%     3832    94
```