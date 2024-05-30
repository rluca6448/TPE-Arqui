#include <IO.h>
#include <video.h>
#include <stdint.h>

uint64_t x = 0;
uint64_t y = 0;

void putChar(char c) {
    putCharColoured(c, 0xFFFFFF, 0x000000);
}

void putCharColoured(char c, uint64_t foreGround, uint64_t backGround) {
    switch (c) {
        case 0x0A:
            newLine(&x, &y);
            break;
        case 0x08:
            deleteCharAt(&x, &y, foreGround, backGround);
            break;
        default:
            putCharAt(c, &x, &y, foreGround, backGround);
            break;
    }
}

void printf(const char * str, ...) {
    for (int i = 0; str[i] != '\0'; i++) {
        putChar(str[i]);
    }
}