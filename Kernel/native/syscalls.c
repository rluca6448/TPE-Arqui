#include <video.h>
#include <sound.h>
#define SYS_WRITE 4
#define SYS_READ 3
#define SYS_CLEAR_SCREEN 5
#define SYS_SOUND 6

uint64_t int80Dispacher(uint64_t id, uint64_t param_1, uint64_t param_2, uint64_t param_3){
    switch (id) {
        case SYS_WRITE:
            sys_write(param_1, param_2, param_3);
            return;
        case SYS_READ:
            return sys_read(param_1, param_2, param_3);
        case SYS_CLEAR_SCREEN:
            sys_clearScreen();
            return;
        case SYS_SOUND:
            sys_sound(param_1);
    }
}