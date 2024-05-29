#ifndef TPE_ARQUI_KEYBOARD_H
#define TPE_ARQUI_KEYBOARD_H

typedef struct {
    int character;
    int make_code;
    int break_code;
    int specialFlag; // 0 for normally-accessed, 1 for shift-accessed, 2 for ctrl-accessed, 3 for alt-accessed
} AsciiMap;

char mapKey(char character, int flags[4]);
extern char getKey();

#endif
