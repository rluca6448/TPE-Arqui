#ifndef TPE_ARQUI_VIDEO_H
#define TPE_ARQUI_VIDEO_H

#include <stdint.h>

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);

void putCharAt(uint8_t c, uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor);
void deleteCharAt(uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor);
void clearScreen(uint32_t hexColor);
void newLine(uint64_t * x, uint64_t * y);

void newFontSize(int newSize);

int getWidth();
int getHeight();

#endif //TPE_ARQUI_VIDEO_H
