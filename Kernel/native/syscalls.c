#include "video.h"
#include "IO.h" // importante agregar todos los headers necesarios
#include "time.h"
#include "lib.h"
#include "interrupts.h"

#define SYS_HLT 0
#define SYS_SOUND 1
#define SYS_SLEEP 2
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_CLEAR_SCREEN 5
#define SYS_PUT_PIXEL 6
#define SYS_NEW_SIZE 7
#define SYS_GET_TIME 8
#define SYS_GET_ELAPSED_SECONDS 9

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
        case SYS_PUT_PIXEL:
            sys_putPixel(param_1, param_2, param_3);
            return;
        case SYS_NEW_SIZE:
            sys_new_size(param_1);
            return;
        case SYS_GET_TIME:
            return sys_getTime(param_1);
        case SYS_GET_ELAPSED_SECONDS:
            return sys_getElapsedSeconds();
        case SYS_HLT:
            _hlt();
            return;
        case SYS_SLEEP: // falta implementar
            return;
    }
}