#ifndef TPE_ARQUI_IO_H
#define TPE_ARQUI_IO_H

#include <stdint.h>

void putChar(char c);
void putCharColoured(char c, uint64_t foreGround, uint64_t backGround);

void printfCouloured(const char * fmt, uint64_t foreGround, uint64_t backGround);
void printf(const char * fmt, ...);

int scanf(const char * fmt, ...);

void setPosition(uint64_t * x, uint64_t * y);
void clear();

#endif //TPE_ARQUI_IO_H
