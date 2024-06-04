#ifndef TPE_ARQUI_SYSCALLS_H
#define TPE_ARQUI_SYSCALLS_H

#include <stdint.h>

int sys_read(int fd, char* buf, int count);
void print_help();
void sys_hlt();
char * getTime();
void sys_write(int fd, const char* buf, int count);
void sys_clearScreen(void);
extern uint64_t syscall(uint64_t id, uint64_t par2, uint64_t par3, uint64_t par4);

#endif //TPE_ARQUI_SYSCALLS_H
