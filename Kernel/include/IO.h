#ifndef TPE_ARQUI_IO_H
#define TPE_ARQUI_IO_H

#include <stdint.h>

void putChar(char c);
void putCharColoured(char c, uint64_t foreGround, uint64_t backGround);
void printfColoured(const char * fmt, uint64_t foreGround, uint64_t backGround);

void print(char * str);

#endif //TPE_ARQUI_IO_H
