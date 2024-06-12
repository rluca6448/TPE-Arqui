#include <sound.h>
#include <time.h>
//
////sacados de la libreria de SYS/IO.h
static void outb (unsigned char __value, unsigned short int __port) {
    __asm__ __volatile__ ("outb %b0,%w1": :"a" (__value), "Nd" (__port));
}

static unsigned char inb (unsigned short int __port) {
    unsigned char _v;
    __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (__port));
    return _v;
}

void play_sound(uint32_t nFrequence)
{
    uint32_t Div;
    uint32_t tmp;

    Div = 1193180/nFrequence;
    outb(0x43, 0xb6);
    outb(0x42, (uint8_t)(Div));
    outb(0x42, (uint8_t)(Div >> 8));

    tmp = inb(0x61);
    if (tmp != (tmp | 3))
    {
        outb(0x61, tmp | 3);
    }
}

void nosound() {
    uint8_t tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

void beep() {
    play_sound(1000);
    nosound();
}

void sys_sound(uint32_t frec) {
    play_sound(frec);
    int start = seconds_elapsed();
    while (seconds_elapsed()-start < 1);
    nosound();
}