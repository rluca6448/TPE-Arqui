#include "../include/syscalls.h"

#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_CLEAR_SCREEN 5
#define SYS_HLT 12

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

void putCharUser(char c){
    sys_write(1, &c, 1);
}

void printfUser(char* str){
    for(int i=0; str[i]; i++){
        putCharUser(str[i]);
    }
}

char getCharUser() {
    char c[1];
    while(sys_read(0, c, 1) <= 0);
    return c[0];
}