#ifndef TPE_ARQUI_VIDEO_H
#define TPE_ARQUI_VIDEO_H

#include <stdint.h>

// macros Alex:
#define SIZE_BUFFER 65536
#define OUT_FORE_COLOR 0x00ffffff
#define OUT_BACK_COLOR 0x00000000
#define ERR_FORE_COLOR 0x00ff0000
#define ERR_BACK_COLOR 0x00000000

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);

// Alex
void putOut(char c);
void putIn(char c);
void clearIn();
int getIn();
void clearOut();
void sys_write(int fd, const char* buf, int count);
int sys_read(int fd, char* buf, int count);
void sys_clearScreen();


void putCharAt(uint8_t c, uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor);
void deleteCharAt(uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor);
void clearScreen(uint32_t hexColor);
void newLine(uint64_t * x, uint64_t * y);
void simplePutCharAt(uint8_t c, uint64_t x, uint64_t y, uint64_t foreColor, uint64_t backgroundColor)

void newFontSize(int newSize);

int getWidth();
int getHeight();
int xOutOfBounds(uint64_t * x);
int yOutOfBounds(uint64_t * y);

void simplePutCharAt(uint8_t c, uint64_t x, uint64_t y, uint64_t foreColor, uint64_t backgroundColor);

#endif //TPE_ARQUI_VIDEO_H
