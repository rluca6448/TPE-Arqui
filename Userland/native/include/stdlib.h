#ifndef TPE_STDLIB_H
#define TPE_STDLIB_H

#include <stdint.h>

#define MAX_BUF 1024

void putchar(char c);
void putcharColoured(char c, uint64_t foreground, uint64_t background);
uint64_t getchar();

uint64_t gets(char * buf, uint64_t length);

uint64_t atoi(char * str);
void itoa(uint64_t num, char * buf);
int strcmp(const char *s1,const char *s2);

#endif //TPE_STDLIB_H
