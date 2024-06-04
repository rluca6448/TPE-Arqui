#include <shell.h>
#include <syscalls.h>
#include <command.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1024

static const char* commands[] = {"clear", "dividebyzero", "help", "inforeg", "invalidopcode", "time"};
static void (*commands_functions[])() = {clear,  divideByZero, help, inforeg, invalidOPCode, time};

void shell() {
    printHeader();
    char buf[MAX_BUF];

    while (1) {
        printf_color("user", 0xcdff00, 0x000000);
        printf(":~$");
        gets(buf, MAX_BUF);
        putchar('\n')
        execute(buf);
        sys_hlt();
    }
}

void printHeader() {
    printf_color("Bienvenido a la Shell!\n", 0xcdff00, 0x000000);
    printf("Ejecuta 'help' para ver una lista de comandos.\n");
    return;
}

int execute(char *inputBuffer) {
    for (int i = 0; i < sizeC; i++)
    {
        if (strcmp(args[0], commands[i].name))
        {
            commands_functions[i]();
            return 1;
        }
    }
    printf("Invalid command, try again.\n");
    return 0;
}
