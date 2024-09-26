## hUGEDriver ROM_0 size

looks to take up ~19% of ROM_0

### before (included both hUGEdriver lib + 1 bar song)

```
ROM_0        0x0000 -> 0x3FFF    16384    12640    77%     3744    23%
ROM_1        0x4000 -> 0x7FFF    16384     4264    26%    12120    74%
ROM_2        0x4000 -> 0x7FFF    16384    10362    63%     6022    37%
ROM_3        0x4000 -> 0x7FFF    16384    15232    93%     1152     7%
ROM_4        0x4000 -> 0x7FFF    16384     5612    34%    10772    66%
ROM_5        0x4000 -> 0x7FFF    16384    14711    90%     1673    10%
ROM_6        0x4000 -> 0x7FFF    16384     9273    57%     7111    43%
ROM_7        0x4000 -> 0x7FFF    16384    15952    97%      432     3%
ROM_8        0x4000 -> 0x7FFF    16384    13963    85%     2421    15%
WRAM_LO      0xC000 -> 0xCFFF     4096      401    10%     3695    90%
```

### after (removed both hUGEdriver lib + 1 bar song)

```
ROM_0        0x0000 -> 0x3FFF    16384     9486    58%     6898    42%
ROM_1        0x4000 -> 0x7FFF    16384     4264    26%    12120    74%
ROM_2        0x4000 -> 0x7FFF    16384    10362    63%     6022    37%
ROM_3        0x4000 -> 0x7FFF    16384    15232    93%     1152     7%
ROM_4        0x4000 -> 0x7FFF    16384     5612    34%    10772    66%
ROM_5        0x4000 -> 0x7FFF    16384    14711    90%     1673    10%
ROM_6        0x4000 -> 0x7FFF    16384     9273    57%     7111    43%
ROM_7        0x4000 -> 0x7FFF    16384    15952    97%      432     3%
ROM_8        0x4000 -> 0x7FFF    16384    13963    85%     2421    15%
WRAM_LO      0xC000 -> 0xCFFF     4096      301     7%     3795    93%
```