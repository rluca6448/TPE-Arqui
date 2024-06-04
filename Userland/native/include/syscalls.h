#ifndef TPE_ARQUI_SYSCALLS_H
#define TPE_ARQUI_SYSCALLS_H

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
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_TIME 8
#define SYS_SLEEP 4
#define SYS_SOUND 5
#define SYS_CLEAR 5

#define SYS_PUT_PIXEL 6
#define SYS_TEXTMODE 7
#define SYS_GET_ELAPSED_SECONDS 9

#include <stdint.h>

extern uint64_t syscall(uint64_t id, uint64_t par2, void * par3, uint64_t par4);

void sys_hlt();

int sys_read(int fd, char * buf, int count);
void sys_write(int fd, char* buf, int count);

char * sys_time();

void sys_sleep();

void sys_sound();
void sys_clear();

void print_help();
void test_int_80h();

#endif //TPE_ARQUI_SYSCALLS_H
