#include <IO.h>
#include <video.h>
#include <stdint.h>

uint64_t x = 0;
uint64_t y = 0;

void putChar(char c) {
    putCharColoured(c, 0xFFFFFF, 0x000000);
}

void print(char * str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putChar(str[i]);
    }
}

void printfColoured(const char * str, uint64_t foreGround, uint64_t backGround) {
    for (int i = 0; str[i] != '\0'; i++) {
        putCharColoured(str[i], foreGround, backGround);
    }
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

/*void printf(const char * str, ...) {
    va_list args;
    va_start(args, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\x5C' && str[i+1] != '\0') {
            switch (str[i+1]) {
                case '':
                    newLine()
            }
        } else if (str[i] == '\x25' && str[i+1] != '\0') {

            switch (str[i+1]) {
                case 'i':
                    int elem = va_arg(args, 1);


            }
        }
        putChar(str[i]);
    }
}*/