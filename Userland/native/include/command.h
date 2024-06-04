#ifndef TPE_COMMAND_H
#define TPE_COMMAND_H

typedef struct {
    char * title;
    char * desc;
    void (*command)();
} command;

void print_time();
void print_help();

void clear();
void divideByZero();
void inforeg();
void invalidOPCode();
void time();

void eliminator();

#endif //TPE_COMMAND_H