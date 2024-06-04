#ifndef TPE_SYSCALLS_H
#define TPE_SYSCALLS_H

uint64_t int80Dispacher(uint64_t id, uint64_t param_1, uint64_t param_2, uint64_t param_3);

void sys_write(int fd, const char * buf, int count);
int sys_read(int fd, const char * buf, int count);
void sys_clear();
void sys_sleep(uint64_t millis);
char * sys_time();
void sys_sound(uint8_t freq, uint64_t duration);
void sys_hlt();
void font_size(int size);
void sys_registers();

#endif //TPE_SYSCALLS_H