#include <time.h>
#include <lib.h>
#include <naiveConsole.h>
#include <syscalls.h>

static unsigned long ticks = 0;

// static char keys[200];
// static int key_amount = 0;

void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}

uint64_t getElapsedSeconds(){
    return TICKS_TO_SECONDS(ticks);
}

char * sys_getTime(){
    return RTC();
}

/*void sleep() {
    sys_sleep();
}

void hlt() {
    sys_hlt();
}*/