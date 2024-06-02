#ifndef _TIME_H_
#define _TIME_H_

#define TICKS_TO_SECONDS(x) ((x) * 5 / 91)

void timer_handler();
int ticks_elapsed();
int seconds_elapsed();

extern char* RTC();
void keyboard_handler();
char* all_keys();
int size_keys();
char key_to_ascii(char key);

#endif
