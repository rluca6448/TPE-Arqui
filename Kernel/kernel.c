#include <stdint.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <keyboard.h>
#include <video.h>

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

int keyFlag[4] = {0,0};        // index 0: bloq-mayus ; index 1: {1=shift ; 2=CTRL ; 3=alt}

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

    ncPrint("[x64BareBones]");
    ncNewline();

    ncPrint("CPU Vendor:");
    ncPrint(cpuVendor(buffer));
    ncNewline();

    ncPrint("[Loading modules]");
    ncNewline();
    void *moduleAddresses[] = {
            sampleCodeModuleAddress,
            sampleDataModuleAddress
    };

    loadModules(&endOfKernelBinary, moduleAddresses);
    ncPrint("[Done]");
    ncNewline();
    ncNewline();

    ncPrint("[Initializing kernel's binary]");
    ncNewline();

    clearBSS(&bss, &endOfKernel - &bss);

    ncPrint("  text: 0x");
    ncPrintHex((uint64_t) & text);
    ncNewline();
    ncPrint("  rodata: 0x");
    ncPrintHex((uint64_t) & rodata);
    ncNewline();
    ncPrint("  data: 0x");
    ncPrintHex((uint64_t) & data);
    ncNewline();
    ncPrint("  bss: 0x");
    ncPrintHex((uint64_t) & bss);
    ncNewline();

    ncPrint("[Done]");
    ncNewline();
    ncNewline();
    return getStackBase();
}

int main() {
    for (int i = 0 ; i < 100 ; i++)
        for (int j = 0 ; j < 100 ; j++)
            putPixel(0x00FF0000, i, j);

    /*
    writeStr("[Kernel Main]", 0x7, 0x0);
    ncNewline();
    ncPrint("  Sample code module at 0x");
    ncPrintHex((uint64_t) sampleCodeModuleAddress);
    ncNewline();
    ncPrint("  Calling the sample code module returned: ");
    ncPrintHex(((EntryPoint) sampleCodeModuleAddress)());
    ncNewline();
    ncNewline();

    ncPrint("  Sample data module at 0x");
    ncPrintHex((uint64_t) sampleDataModuleAddress);
    ncNewline();
    ncPrint("  Sample data module contents: ");
    ncPrint((char *) sampleDataModuleAddress);
    ncNewline();

    writeStr("[Finished]", 0x7, 0x0);

    ncClear();

    writeStr("Arquitectura de Computadoras", 0xF, 0x2);
    ncNewline();

    writeStr(RTC(), 0xF, 0x0);
    ncNewline();

    writeStr("Ahora podes escribir...", 0xF, 0x0);
    ncNewline();*/

    /*char i = getKey();
    char key;

    while ((key = mapKey(i, keyFlag)) != '\x03') {
        switch (i) {
            case '\x3A':    // bloq-mayus
                keyFlag[0] = !keyFlag[0];
                break;
            case '\x36':    // right-shift pressed
            case '\x2A':    // left-shift pressed
                keyFlag[0] = !keyFlag[0];
                keyFlag[1] = 1;
                break;
            case '\xAA':    // left-shift released
                keyFlag[0] = !keyFlag[0];
                keyFlag[1] = 0;
                break;
            case '\x9D':    // left-ctrl released
            case '\xB8':    // left-alt released
            case '\xB6':    // right-shift released
                keyFlag[1] = 0;
                break;
            case '\x1D':    // left-ctrl pressed
                keyFlag[1] = 2;
                break;
            case '\x38':    // left-alt pressed
                keyFlag[1] = 3;
                break;
            default:
                if (key != '\0') {
                    writeCharacter(key, 0xF, 0x0);
                }
                break;
        }
        i = getKey();
    }

    ncNewline();
    writeStr("Terminado!", 0xF, 0x0);*/
    return 0;
}

