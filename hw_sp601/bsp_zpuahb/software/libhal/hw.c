#include "peripherie.h"

volatile uint32_t *debug_con0 = (uint32_t *)   0x80000000;
volatile uint32_t *reset_reg  = (uint32_t *)   0x80000004;
apbuart_t         *uart0      = (apbuart_t *)  0x80000100;
gptimer_t         *timer0     = (gptimer_t *)  0x80000200;
irqmp_t           *irqmp0     = (irqmp_t *)    0x80000300; // tbd
grgpio_t          *gpio0      = (grgpio_t *)   0x80000400;
greth_t           *ether0     = (greth_t *)    0x80000500;
apbvga_t          *vga0       = (apbvga_t *)   0x80000600;
i2cmst_t          *i2c_dvi    = (i2cmst_t *)   0x80000700; // not on sp601
i2cmst_t          *i2c_fmc    = (i2cmst_t *)   0x80000a00;
mctrl_t           *mctrl0     = (mctrl_t *)    0x80000f00;

char debug_putchar( char c)
{
    *debug_con0 = (uint32_t) c;
    return 0;
}

char (* putchar_fp) (char);// = debug_putchar;

