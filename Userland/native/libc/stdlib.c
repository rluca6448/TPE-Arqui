#include <stdlib.h>
#include <syscalls.h>

void putchar(char c) {
    putcharColoured(c, 0xFFFFFF, 0x000000);
}

void putcharColoured(char c, uint64_t foreground, uint64_t background) {
    sys_write(SYS_WRITE, &c, 1);
}

uint64_t getchar() {
    return 1;
}

uint64_t gets(char * buf, uint64_t length) {
    return 1;
}

uint64_t atoi(char * str) {
    return 1;
}

void itoa(uint64_t num, char * buf) {

}