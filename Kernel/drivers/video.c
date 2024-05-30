#include <video.h>

// macros Alex:
#define SIZE_BUFFER 65536


struct vbe_mode_info_structure {
    uint16_t attributes;		// deprecated, only bit 7 should be of interest to you, and it indicates the mode supports a linear frame buffer.
    uint8_t window_a;			// deprecated
    uint8_t window_b;			// deprecated
    uint16_t granularity;		// deprecated; used while calculating bank numbers
    uint16_t window_size;
    uint16_t segment_a;
    uint16_t segment_b;
    uint32_t win_func_ptr;		// deprecated; used to switch banks from protected mode without returning to real mode
    uint16_t pitch;			// number of bytes per horizontal line
    uint16_t width;			// width in pixels
    uint16_t height;			// height in pixels
    uint8_t w_char;			// unused...
    uint8_t y_char;			// ...
    uint8_t planes;
    uint8_t bpp;			// bits per pixel in this mode
    uint8_t banks;			// deprecated; total number of banks in this mode
    uint8_t memory_model;
    uint8_t bank_size;		// deprecated; size of a bank, almost always 64 KB but may be 16 KB...
    uint8_t image_pages;
    uint8_t reserved0;

    uint8_t red_mask;
    uint8_t red_position;
    uint8_t green_mask;
    uint8_t green_position;
    uint8_t blue_mask;
    uint8_t blue_position;
    uint8_t reserved_mask;
    uint8_t reserved_position;
    uint8_t direct_color_attributes;

    uint32_t framebuffer;		// physical address of the linear frame buffer; write here to draw to the screen
    uint32_t off_screen_mem_off;
    uint16_t off_screen_mem_size;	// size of memory in the framebuffer but not being displayed on the screen
    uint8_t reserved1[206];
} __attribute__ ((packed));

typedef struct vbe_mode_info_structure * VBEInfoPtr;

VBEInfoPtr VBE_mode_info = (VBEInfoPtr) 0x0000000000005C00;

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y) {
    uint8_t * framebuffer = (uint8_t *) VBE_mode_info->framebuffer;
    uint64_t offset = (x * ((VBE_mode_info->bpp)/8)) + (y * VBE_mode_info->pitch);
    framebuffer[offset]     =  (hexColor) & 0xFF;
    framebuffer[offset+1]   =  (hexColor >> 8) & 0xFF;
    framebuffer[offset+2]   =  (hexColor >> 16) & 0xFF;
}


// Comandos Alex (a partir de acá)

static int charSize = 10;

static char stdoutArr[SIZE_BUFFER];
static int sizeOut = 0;
static int startsOut = 0;
static char stdinArr[SIZE_BUFFER];
static int sizeIn = 0;
static int startsIn = 0;
static char stderrArr[SIZE_BUFFER];
static int sizeErr = 0;
static int startsErr = 0;

int getSizeIn(){
	return sizeIn;
}

void putOut(char c){
    // mete c en el vector cíclico
    // TODO: falta manejar excepciones especialmente si sizeOut es demasiado grande

    int pos = (startsOut + sizeOut) % SIZE_BUFFER;
	stdoutArr[pos]=c;
    sizeOut++;
    if (sizeOut > SIZE_BUFFER) sizeOut -= SIZE_BUFFER;

    printOutInScreen(charSize);
}

void putErr(char c){
	// TODO: falta manejar excepciones
	stderrArr[sizeErr++ % SIZE_BUFFER]=c;
    printOutInScreen(charSize);
}

void putIn(char c){
    // caso especial donde se pasa del límite: no se pueden agregar caracteres
    // podríamos hacer que aparezca un mensaje o algo así
    if (sizeIn >= SIZE_BUFFER-1) return;

    // mete c en el vector cíclico
    int pos = (startsIn + sizeIn) % SIZE_BUFFER;

    switch (stdinArr[pos]){      //agregar quizás casos especiales
    default:
    	// TODO: falta manejar excepciones
        stdinArr[pos] = c;
        sizeIn++;

    }
}

void clearIn(){
    sizeIn = 0;
}

void clearOut(){
    sizeOut = 0;
}


static char videoModeOn = 0;

void disableTextScreen(){
    videoModeOn = 0;
}

void enableTextScreen(){
    videoModeOn = 1;
}

void sys_write(int fd, const char* buf, int count){
    if (fd==1){
        for(int i=0; i<count; i++){
            putOut(buf[i]);
        }
    }
    if (fd==2){
        for(int i=0; i<count; i++){
            putErr(buf[i]);
        }
    }
}

void sys_read(int fd, char* buf, int count){
    if (fd==0){
        for(int i=0; i<count && i<sizeIn; i++){
            buf[i] = stdinArr[i];
        }
    }
}

void sys_textmode(char enabled, int newSize){
    if (enabled) videoModeOn = 0;
    else videoModeOn = 1;
    // el size se cambia de todas formas si está en un valor en el rango;
    if (newSize > 1 && newSize < 50) {
        charSize = newSize;
    }
}

void sys_putPixel(uint32_t hexColor, uint64_t x, uint64_t y){
    if (!videoModeOn) return;
    putPixel(hexColor, x, y);
}



void printOutInScreen(int size){    // size AHORA es pixeles x letra. Esto lo tengo que cambiar
    if (videoModeOn==1) return;
    
	int perLine = 1024/size;
	int height = 768/size;
	int k = 0;
    int secondLine = 0;     //esto después se va a modificar
    while (k<sizeOut){
        for(int i=0; i<height && k<sizeOut; i++){
            if (i==1) {
                secondLine = (startsOut + k) % SIZE_BUFFER;
            }
		    for(int j=0; j<perLine && k<sizeOut; j++, k++) {
                int pos = (startsOut + k) % SIZE_BUFFER;

			    if (stdoutArr[pos]=='\n'){
				    break;
			    }
			    switch (stdoutArr[pos]){
			    	case '\t': j+=3; break;
                    default:
			    	printCharInScreen(stdoutArr[pos], j*size, i*size);
			    }
		    }
	    }
        if (k<sizeOut) {
            sizeOut -= (secondLine-startsOut) % SIZE_BUFFER;
            startsOut = secondLine;
            k = 0;
        }
    }
	
}



void printCharInScreen(char c, int x, int y){
    if (c == 'c'){
        // esto es para probar
        putPixel(0x00ffffff, x, y);
    }

}

//1024 width 768 height