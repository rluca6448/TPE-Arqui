#include <command.h>
#include <syscalls.h>
#include <stdio.h>

static command commands[] = {
        {"help", "Muestra la lista de comandos", print_help},
        {"time", "Muestra la hora", print_time},
        {"eliminator", "Ejecuta el juego eliminator.", eliminator}
};

void execute(const char * command) {
    for (int i = 0; i < sizeof(commands)/sizeof(command) ; i++) {
        if (commands[i].title == command) {
            commands[i].command();
            return;
        }
    }
}

void print_help() {
    //prinf("Comandos disponibles:\n");
    for (int i = 0 ; i < sizeof(commands)/sizeof(command) ; i++) {
        printf("%s : %s\n", commands[i].title, commands[i].desc);
    }
}

void print_time() {
    printf("%s\n", sys_time());
}

void eliminator() {
    return;
}