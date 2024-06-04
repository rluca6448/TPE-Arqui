#ifndef TPE_ARQUI_IO_H
#define TPE_ARQUI_IO_H

#include <stdint.h>

void putChar(char c);
void putCharColoured(char c, uint64_t foreGround, uint64_t backGround);

void printf(char * str);


//antes estaban en video.h
void putOut(char c);
void putIn(char c);
void clearIn();
void clearOut();
void sys_write(int fd, const char* buf, int count);
int sys_read(int fd, char* buf, int count);

void putCharAt(uint8_t c, uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor);
void deleteCharAt(uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor);
void clearScreen(uint32_t hexColor);
void newLine(uint64_t * x, uint64_t * y);

void newFontSize(int newSize);


int xOutOfBounds(uint64_t * x);
int yOutOfBounds(uint64_t * y);



#endif //TPE_ARQUI_IO_H
