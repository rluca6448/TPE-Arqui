#include "../include/command.h"
#include "../include/syscalls.h"
#include "../include/stdio.h"
#include "../include/stdlib.h"
#include "../include/eliminator.h"

#define REG_SIZE 17
#define SECONDS 0
#define MINUTES 2
#define HOURS 4
#define DAY_OF_THE_WEEK 6
#define DAY_OF_THE_MONTH 7
#define MONTH 8
#define YEAR 9

static command commands[] = {
        {"help            :  ", "Muestra la lista de comandos.", print_help},
        {"time            :  ", "Muestra la hora.", time},
        {"eliminator      :  ", "Ejecuta el juego eliminator.", eliminator},
        {"size_<1-5>      :  ", "cambia tamanio de letra (entre 1 a 5).", changeSize_1},
        {"dividebyzero    :  ", "Muestra excepcion de divicion de 0.", changeSize_1},
        {"invalidopcode   :  ", "Muestra excepcion de codigo invalido.", changeSize_1},
        {"inforeg         :  ", "Muestra la informacion de los registros.", changeSize_1},
        {"clear           :  ", "Limpia toda la pantalla.", clear},
};

void print_help() {
    printf("Comandos disponibles:\n");
    for (int i = 0 ; i < sizeof(commands)/sizeof(command) ; i++) {
        printf(commands[i].title);
        printf(" : ");
        printf(commands[i].desc);
        printf("\n");
    }
}


void clear() {
    sys_clear();
}

void divideByZero() {
    runZeroDivisionException();
}

void invalidOpcode() {
    runInvalidOpcodeException();
}

void changeSize_1() {
    sys_new_size(1);
}
void changeSize_2() {
    sys_new_size(2);
}
void changeSize_3() {
    sys_new_size(3);
}
void changeSize_4() {
    sys_new_size(4);
}
void changeSize_5() {
    sys_new_size(5);
}



void time() {
    int minutes;
    printInt(sys_time(HOURS)+1);
    printf(":");
    if(minutes <10){
        printf('0');
    }
    printInt(sys_time(MINUTES));
    printf(", ");
    printInt(sys_time(DAY_OF_THE_MONTH));
    printf("/");
    printInt(sys_time(MONTH));
    printf("/");
    printInt(sys_time(YEAR) + 2000);
    printf("\n");
}

void printRegisters(uint64_t *reg){
    char *regs[REG_SIZE] = {
            "RAX", "RBX", "RCX", "RDX", "RDI", "RSI","RBP", "RSP",
            "R08", "R09", "R10", "R11", "R12", "R13", "R14",
            "R15", "IP "};

    char toPrint[18];
    for (int i = 0; i < REG_SIZE; i++)
    {
        printf_color(regs[i], 0xFFEA00,0x000000);
        int digits = uintToBase(reg[i], toPrint, 16);
        printf(" : 0x");
        int zeros = 15;
        while(zeros > digits){
            printf("0");
            zeros--;
        }
        printf(toPrint);
        putchar('\n');
    }
}

