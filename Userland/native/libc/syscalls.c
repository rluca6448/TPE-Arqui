#include <syscalls.h>

int sys_read(int fd, char* buf, int count){
    return syscall(SYS_READ, fd, buf, count);
}

void sys_hlt() {
    syscall(SYS_HLT, 0, 0, 0);
}

void sys_write(int fd, const char* buf, int count){
    syscall(SYS_WRITE, fd, buf, count);
}

void sys_clearScreen(){
    syscall(SYS_CLEAR_SCREEN, 0, 0, 0);
}

char getCharUser() {
    char c[1];
    while(sys_read(0, c, 1) <= 0);
    return c[0];
}