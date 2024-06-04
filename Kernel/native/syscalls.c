#include <video.h>
#include <IO.h> // importante agregar todos los headers necesarios
#define SYS_WRITE 4
#define SYS_READ 3
#define SYS_CLEAR_SCREEN 5
#define SYS_PUT_PIXEL 6
#define SYS_TEXTMODE 7


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
            sys_putBigPixel(param_1, param_2, param_3);
            return;
        case SYS_TEXTMODE:
            sys_textmode(param_1, param_2);
            return;
    }
}