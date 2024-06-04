#ifndef TPE_COMMAND_H
#define TPE_COMMAND_H

typedef struct {
    char * title;
    char * desc;
    int (*command)();
} command;

void print_time();
void print_help();

#endif //TPE_COMMAND_H
