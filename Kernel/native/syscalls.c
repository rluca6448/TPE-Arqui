#include <video.h>
#define SYS_WRITE 4
#define SYS_READ 69

void int80Dispacher(uint64_t id, uint64_t param_1, uint64_t param_2, uint64_t param_3){
    switch (id) {
        case SYS_WRITE:
            sys_write(param_1, param_2, param_3);
        case SYS_READ:
            sys_read(param_1, param_2, param_3);
    }
}