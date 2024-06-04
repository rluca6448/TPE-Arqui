#include <shell.h>
#include <syscalls.h>
#include <command.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024
#define REG_SIZE 17

char * commands[] = {"clear", "dividebyzero", "help", "inforeg", "invalidopcode", "time", "eliminator"};
void (*commands_functions[])() = {clear,  divideByZero, print_help, inforeg, invalidOPCode, print_time, eliminator};

void shell() {
    printHeader();
    char buf[MAX_BUF];

    while (1) {
        printf_color("user", 0xcdff00, 0x000000);
        printf(":~$");
        gets(buf, MAX_BUF);
        putchar('\n');
        execute(buf);
        sys_hlt();
    }
}

void printHeader() {
    printf_color("Bienvenido a la Shell!\n", 0xcdff00, 0x000000);
    printf("Ejecuta 'help' para ver una lista de comandos.\n");
    return;
}

void execute(char *inputBuffer) {
    for (int i = 0; i < sizeof(commands) ; i++)
    {
        if (strcmp(inputBuffer, commands[i]))
        {
            commands_functions[i]();
            return;
        }
    }
    printf("Invalid command, try again.\n");
}