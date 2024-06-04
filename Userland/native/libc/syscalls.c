#include <syscalls.h>


void sys_hlt() {
    syscall(SYS_HLT, 0, 0, 0);
}

int sys_read(int fd, char * buf, int count){
    return syscall(SYS_READ, fd, buf, count);
}

void sys_write(int fd, char * buf, int count){
    syscall(SYS_WRITE, fd, buf, count);
}

char * sys_time() {
    return syscall(SYS_TIME, 0, 0, 0);
}

void sys_sleep() {
    syscall(SYS_SLEEP, 0, 0, 0);
}

void sys_sound() {
    syscall(SYS_SOUND, 0, 0, 0);
}

void sys_clear(){
    syscall(SYS_CLEAR, 0, 0, 0);
}

void sys_putPixel(uint32_t hexColor, uint64_t x, uint64_t y){
    syscall(SYS_PUT_PIXEL, hexColor, x, y);
}

void ticks_elapsed() {
    return syscall(SYS_GET_ELAPSED_SECONDS, 0, 0, 0);
}