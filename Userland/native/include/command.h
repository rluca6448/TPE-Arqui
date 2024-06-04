#ifndef TPE_COMMAND_H
#define TPE_COMMAND_H

typedef struct {
    char * title;
    char * desc;
    void (*command)();
} command;

void print_time();
void print_help();

void eliminator();

void execute(const char * command);

#endif //TPE_COMMAND_H