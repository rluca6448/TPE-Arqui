#ifndef TPE_ARQUI_SYSCALLS_H
#define TPE_ARQUI_SYSCALLS_H

#include <stdint.h>

extern uint64_t syscall(uint64_t id, uint64_t par2, const char * par3, uint64_t par4);

int sys_read(int fd, char* buf, int count);
void sys_write(int fd, char* buf, int count);
void sys_clearScreen(void);

#endif //TPE_ARQUI_SYSCALLS_H
