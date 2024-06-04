#include <shell.h>
#include <syscalls.h>
#include <command.h>

#define MAX_BUF 1024

void shell() {
    printHeader();
    char buf[MAX_BUF];

    while (1) {
        //printf_color("user", );
        //printf_color(":", );
        //printf_color("~$ ", )
        //gets(buff, MAX_BUF);
        execute(buf);
        sys_hlt();
    }
}

void printHeader() {
    //printf_color("Bienvenido a la Shell!\n", 0xcdff00, 0x000000);
    //printf("Ejecuta 'help' para ver una lista de comandos.\n");
    return;
}
