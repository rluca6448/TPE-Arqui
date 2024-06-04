#include <stdint.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <keyboard.h>
#include <IO.h>
#include <video.h>
#include <idtLoader.h>

extern void test_int_80h();

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void *const sampleCodeModuleAddress = (void *) 0x400000;
static void *const sampleDataModuleAddress = (void *) 0x500000;

typedef int (*EntryPoint)();

//int keyFlag[4] = {0,0};        // index 0: bloq-mayus ; index 1: {1=shift ; 2=CTRL ; 3=alt}

void clearBSS(void *bssAddress, uint64_t bssSize) {
    memset(bssAddress, 0, bssSize);
}

void *getStackBase() {
    return (void *) (
            (uint64_t) & endOfKernel
                         + PageSize * 8                //The size of the stack itself, 32KiB
                         - sizeof(uint64_t)            //Begin at the top of the stack
    );
}

void *initializeKernelBinary() {
    char buffer[10];

    void *moduleAddresses[] = {
            sampleCodeModuleAddress,
            sampleDataModuleAddress
    };

    loadModules(&endOfKernelBinary, moduleAddresses);

    clearBSS(&bss, &endOfKernel - &bss);

    return getStackBase();
}

int main() {
    load_idt();
    // putSquare(0x00ffffff, 0, 0, 5);

    // while(seconds_elapsed() < 2);
    // char* buf[2];
    // int charsRead = sys_read(0, buf, 2);
    // sys_write(1, buf, 2);
    // sys_write(1, "xd", 2);
    // test_int_80h();

    // for(int i=0; i<140; i++){
    //     sys_write(1, "0123456789", 10);
    // }
    sys_textmode(1, 2);
    while(seconds_elapsed() < 3){
        char* buf[1];
        char hasRead = sys_read(0, buf, 1);
        if (hasRead) sys_write(1, buf, 1);
    }
    sys_textmode(1, 4);

    while(seconds_elapsed() < 10){
        char* buf[1];
        char hasRead = sys_read(0, buf, 1);
        if (hasRead) sys_write(2, buf, 1);
    }
    // while(1);

//    char i = getKey();
//    char key;
//
//    while ((key = mapKey(i, keyFlag)) != '\x03') {
//        switch (i) {
//            case '\x3A':    // bloq-mayus
//                keyFlag[0] = !keyFlag[0];
//                break;
//            case '\x36':    // right-shift pressed
//            case '\x2A':    // left-shift pressed
//                keyFlag[0] = !keyFlag[0];
//                keyFlag[1] = 1;
//                break;
//            case '\xAA':    // left-shift released
//                keyFlag[0] = !keyFlag[0];
//                keyFlag[1] = 0;
//                break;
//            case '\x9D':    // left-ctrl released
//            case '\xB8':    // left-alt released
//            case '\xB6':    // right-shift released
//                keyFlag[1] = 0;
//                break;
//            case '\x1D':    // left-ctrl pressed
//                keyFlag[1] = 2;
//                break;
//            case '\x38':    // left-alt pressed
//                keyFlag[1] = 3;
//                break;
//            default:
//                if (key != '\0') {
//                    putChar(key);
//                    putIn(key);
//                }
//                break;
//        }
//        i = getKey();
//    }

     return 0;
}

