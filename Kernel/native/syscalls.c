#include <video.h>
#include <syscalls.h>

#define SYS_WRITE 4
#define SYS_READ 3
#define SYS_CLEAR_SCREEN 5

uint64_t int80Dispacher(uint64_t id, uint64_t param_1, char * param_2, uint64_t param_3) {
    if (id == SYS_WRITE) {
        sys_write(param_1, param_2, param_3);
        return 0;
    } else if (id == SYS_READ) {
        return sys_read(param_1, param_2, param_3);
    } else if (id == SYS_CLEAR_SCREEN) {
        sys_clearScreen();
        return 0;
    }
    return 0;
}