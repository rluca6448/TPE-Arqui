//
// Created by hwapy on 6/4/2024.
//

#include <sound.h>

//sacados de la libreria de SYS/IO.h
static void outb (unsigned char __value, unsigned short int __port)
{
    __asm__ __volatile__ ("outb %b0,%w1": :"a" (__value), "Nd" (__port));
}

static unsigned char inb (unsigned short int __port)
{
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

    tmp = inb(0x60);
    if (tmp != (tmp | 3))
    {
        outb(0x61, tmp | 3);
    }
}

void sys_sound(uint64_t frec)
{
    play_sound((uint32_t)frec);
    return 0;
}
