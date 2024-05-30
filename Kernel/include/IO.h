#ifndef TPE_ARQUI_IO_H
#define TPE_ARQUI_IO_H

#include <stdint.h>

void putChar(char c);
void putCharColoured(char c, uint64_t foreGround, uint64_t backGround);

void printf(const char * str, ...);

#endif //TPE_ARQUI_IO_H
