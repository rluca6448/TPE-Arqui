#include "command.h"
#include "syscalls.h"
#include "stdio.h"
#include "stdlib.h"
#include "eliminator.h"

#define REG_SIZE 17

static command commands[] = {
        {"help", "Muestra la lista de comandos", print_help},
        {"time", "Muestra la hora", print_time},
        {"eliminator", "Ejecuta el juego eliminator.", eliminator}
};

void print_help() {
    printf("Comandos disponibles:\n");
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

void clear() {
    sys_clear();
}

void divideByZero() {
    runZeroDivisionException();
}

void invalidOPCode() {
    runInvalidOpcodeException();
}

void time() {
    printf("%s\n", sys_time());
}

void printRegisters(uint64_t *reg){
    char *regs[REG_SIZE] = {
            "RAX", "RBX", "RCX", "RDX", "RDI", "RSI","RBP", "RSP",
            "R08", "R09", "R10", "R11", "R12", "R13", "R14",
            "R15", "IP "};

    char toPrint[30];
    for (int i = 0; i < REG_SIZE; i++)
    {
        printf_color(regs[i], 0xFFEA00,0x000000);
        uintToBase(reg[i], toPrint, 16);
        printf(":");
        printf("%s", toPrint);
        putchar('\n');
    }
}