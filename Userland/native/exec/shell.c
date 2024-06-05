#include "../include/shell.h"
#include "../include/syscalls.h"
#include "../include/command.h"
#include "../include/eliminator.h"
#include "../include/stdio.h"
#include "../include/stdlib.h"
#include "../include/string.h"

#define MAX_BUF 1024

// se podría cambiar la implementación para que se acepten parámetros (y no haya que hacer size 1, size 2...)
// pero en este caso no hace falta porque hay pocos parámetros
char * commands[] = {"clear", "dividebyzero", "help", "inforeg", "invalidopcode", "time", "eliminator",
                     "size 1", "size 2", "size 3", "size 4", "size 5"};
void (*commands_functions[])() = {clear,  divideByZero, print_help, inforeg, invalidOpcode, time, eliminator,
                                  changeSize_1, changeSize_2, changeSize_3, changeSize_4, changeSize_5};

void shell() {
    printHeader();
    char buf[MAX_BUF] = {0};



//    while (1) {
//        printf_color("user", 0xcdff00, 0x000000);
//        printf(":~$");
////        gets(buf, MAX_BUF);
//
//        char c;
////        do{
////            c = getchar();
////            putchar(c);
////        } while (c!='\n');
////        putchar('\n');
////        execute(buf);
//        sys_hlt();
//    }
}

void printHeader() {
    printf_color("Bienvenido a la Shell!\n", 0xcdff00, 0x000000);
    printf("Ejecuta 'help' para ver una lista de comandos.\n");
    return;
}

void execute(const char *inputBuffer) {
    for (int i = 0; i < 7 ; i++) //todo poner bien el tamaño
    {
        if (strcmp(inputBuffer, commands[i]) == 0)
        {
            commands_functions[i]();
            return;
        }
    }
    printf("Invalid command, try again.\n");
}