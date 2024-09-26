// assets/music
#ifdef HUGEDRIVER_INCLUDED
#include "hUGEDriver.h"
extern const hUGESong_t introsong;

void initialize_sound(void)
{
    // LCDC_REG = 0xD1;
    // BGP_REG  = 0b11100100;
    NR52_REG = 0x80;
    NR51_REG = 0xFF;
    NR50_REG = 0x77;

    __critical
    {
        hUGE_init(&introsong);
        add_VBL(hUGE_dosound);
    }
}
#endif