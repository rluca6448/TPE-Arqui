#ifndef _TIME_H_
#define _TIME_H_

void timer_handler();
int ticks_elapsed();
int seconds_elapsed();

void keyboard_handler();
char* all_keys();
int size_keys();
char key_to_ascii(char key);

#endif
