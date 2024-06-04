#ifndef TPE_ARQUI_VIDEO_H
#define TPE_ARQUI_VIDEO_H

#include <stdint.h>

#define OUT_FORE_COLOR 0x00ffffff
#define ERR_FORE_COLOR 0x00ff0000
#define OUT_BACK_COLOR 0x00000000

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);
void putSquare(uint32_t hexColor, uint64_t x, uint64_t y, uint64_t size);
void sys_clearScreen();
int getWidth();
int getHeight();




#endif //TPE_ARQUI_VIDEO_H
