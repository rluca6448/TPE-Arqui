#include <video.h>
#include <lib.h>
#include <syscalls.h>
#include <time.h>

/*
 * hlt = 0
 * read = 1
 * write = 2
 * time = 3
 * sleep = 4
 * sound = 5
 * clear = 6
 * */

#define SYS_HLT 0
#define SYS_READ 1
#define SYS_WRITE 2
#define SYS_TIME 3
#define SYS_SLEEP 4
#define SYS_SOUND 5
#define SYS_CLEAR 6

#define REGS_SIZE 19

static uint8_t regs_flag = 0;
static uint64_t regs[REGS_SIZE];

uint64_t int80Dispacher(uint64_t id, uint64_t param_1, void * param_2, uint64_t param_3) {
    switch (id) {
        case SYS_HLT:
            sys_hlt();
            return 1;
        case SYS_READ:
            return sys_read(param_1, param_2, param_3);
        case SYS_WRITE:
            sys_write(param_1, param_2, param_3);
            return 1;
        case SYS_TIME:
            return sys_time();
        case SYS_SLEEP:
            //sys_sleep(param_3);
            return 1;
        case SYS_SOUND:
            //sys_sound();
            return 1;
        case SYS_CLEAR:
            sys_clear();
            return 1;
    }
    return 0;
}

void sys_clear() {
    clearScreen(OUT_BACK_COLOR);
}

void sys_sleep(uint64_t millis) {
    sleep(millis);
}

char * sys_time() {
    return getTime();
}

void sys_sound(uint8_t freq, uint64_t duration) {
    return;
}

void sys_hlt() {
    _hlt();
}

void font_size(int size) {
    newFontSize(size);
}

void sys_registers() {
    //print_regs(regs_flag ? regs : 0);
    //regs_flag = 0;
}