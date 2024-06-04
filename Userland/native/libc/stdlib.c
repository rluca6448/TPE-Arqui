#include <stdlib.h>
#include <syscalls.h>

void putchar(char c) {
    putcharColoured(c, 0xFFFFFF, 0x000000);
}

void putcharColoured(char c, uint64_t foreground, uint64_t background) {
    char buf[1] = {c};
    sys_write(1, buf, 1);
}

uint64_t getchar() {
    char buf[1];
    sys_read(0, buf, 1);
    return buf[0];
}

uint64_t gets(char * buf, uint64_t length) {
    char c;
    int i = 0;
    do {
        c=getchar();
        if (c >= 0x20 && c <= 0x7F) {
            *buf = c;
            putchar(c);
        } else if (c == '\n') {
            *buf = '\0';
            putchar('\n');
            return i;
        }
        buf++;
    } while (i < length-1);
    *buf = '\0';
    return i;
}

uint64_t atoi(char * str) {
    return 1;
}

void itoa(uint64_t num, char * buf) {
    return;
}

int strcmp(char *s1, char *s2) {
    while (*s1 != 0 && *s2 != 0 && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return *s1 == 0 && *s2 == 0;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base) {
    char *p = buffer;
    char *p1, *p2;
    uint32_t digits = 0;

    //Calculate characters for each digit
    do
    {
        uint32_t remainder = value % base;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        digits++;
    }
    while (value /= base);

    // Terminate string in buffer.
    *p = 0;

    //Reverse string in buffer.
    p1 = buffer;
    p2 = p - 1;
    while (p1 < p2)
    {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }

    return digits;
}