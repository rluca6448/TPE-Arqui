#ifndef TPE_ARQUI_SYSCALLS_H
#define TPE_ARQUI_SYSCALLS_H

#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_CLEAR_SCREEN 5
#define SYS_HLT 12

#include <stdint.h>

int sys_read(int fd, char* buf, int count);
void print_help();
void sys_hlt();
char * getTime();
void sys_write(int fd, const char* buf, int count);
void sys_clearScreen(void);

extern uint64_t syscall(uint64_t id, uint64_t par2, void * par3, uint64_t par4);

void test_int_80h();

#endif //TPE_ARQUI_SYSCALLS_H
