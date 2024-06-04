#ifndef TPE_ARQUI_SYSCALLS_H
#define TPE_ARQUI_SYSCALLS_H

#include <stdint.h>

int sys_read(int fd, char* buf, int count);
void sys_write(int fd, const char* buf, int count);
void sys_clearScreen(void);

#endif //TPE_ARQUI_SYSCALLS_H
