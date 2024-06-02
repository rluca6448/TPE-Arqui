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
        case 0x0A:  // es la tecla enter
            newLine(&x, &y);
            break;
        case 0x08:  // es la tecla backspace
            deleteCharAt(&x, &y, foreGround, backGround);
            break;
        case 0x09:  // es la tecla tab (4 espacios)
            for (int i = 0; i < 3; i++, putCharAt(' ', &x, &y, foreGround, backGround));
            break;
        default:    // corresponde a otro simbolo escribible
            putCharAt(c, &x, &y, foreGround, backGround);
            break;
    }
}


void printfCouloured(const char * fmt, uint64_t foreGround, uint64_t backGround) {
    return;
}

void printf(const char * fmt, ...) {
    printfCouloured(fmt, 0xFFFFFF, 0x000000);
}

int scanf(const char * fmt, ...) {
    return 0;
}

void setPosition(uint64_t * x, uint64_t * y) {
    return;
}

void clear() {
    return;
}






