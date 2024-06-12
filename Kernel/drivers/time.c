#include "time.h"
#include "lib.h"
#include "naiveConsole.h"
#include "interrupts.h"

static unsigned long ticks = 0;

// static char keys[200];
// static int key_amount = 0;

void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int sys_getTicks(){
    return ticks_elapsed();
}

int seconds_elapsed() {
	return ticks / 18;
}

uint64_t sys_getElapsedSeconds(){
    return TICKS_TO_SECONDS(ticks);
}

uint8_t getFormat(uint8_t num) {
    int dec = num & 240;
    dec = dec >> 4;
    int units = num & 15;
    return dec * 10 + units;
}

uint8_t sys_getTime(int descriptor) {
    uint8_t toReturn = getRTC(descriptor);
    return getFormat(toReturn);
}