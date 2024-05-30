#ifndef TPE_ARQUI_VIDEO_H
#define TPE_ARQUI_VIDEO_H

#include <stdint.h>

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);

// Alex
void putOut(char c);
void putIn(char c);
void clearIn();
void clearOut();
void sys_write(int fd, const char* buf, int count);
void sys_read(int fd, char* buf, int count);


#endif //TPE_ARQUI_VIDEO_H
