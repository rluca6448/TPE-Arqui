#ifndef _TIME_H_
#define _TIME_H_

#include <stdint.h>

#define TICKS_TO_SECONDS(x) ((x) * 5 / 91)

void timer_handler();
int ticks_elapsed();
int seconds_elapsed();
uint64_t sys_getElapsedSeconds();


#define SECONDS 00
#define MINUTES 02
#define HOURS 04
#define DAY_OF_THE_WEEK 06
#define DAY_OF_THE_MONTH 07
#define MONTH 08
#define YEAR 09
extern uint8_t getRTC(uint64_t descriptor);
uint8_t sys_getTime(int descriptor);

void keyboard_handler();
char* all_keys();
int size_keys();
char key_to_ascii(char key);

uint64_t sleep(uint64_t millis);
void sys_sleep(uint64_t millis);

#endif
