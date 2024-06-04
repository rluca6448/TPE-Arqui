#include <time.h>
#include <lib.h>
#include <naiveConsole.h>

static unsigned long ticks = 0;

void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}

void sleep(uint64_t millis) {
    uint64_t start = ticks;
    while (ticks - start < millis / 51) {
        _hlt();
        ticks++;
    }
}