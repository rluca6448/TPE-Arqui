#include <IO.h>
#include <video.h>
#include <stdint.h>
#include <font.h>
#include <interrupts.h>


//defines Alex

#define SIZE_BUFFER 65536



uint64_t x = 0;
uint64_t y = 0;

void putChar(char c) {
    putCharColoured(c, 0xFFFFFF, 0x000000);
}

void printf(char * str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putChar(str[i]);
    }
}


void putCharColoured(char c, uint64_t foreGround, uint64_t backGround) {
    switch (c) {
        case 0x0A:
            newLine(&x, &y);
            break;
        case 0x08:
            deleteCharAt(&x, &y, foreGround, backGround);
            break;
        default:
            putCharAt(c, &x, &y, foreGround, backGround);
            break;
    }
}


/*void printf(const char * str, ...) {
    va_list args;
    va_start(args, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\x5C' && str[i+1] != '\0') {
            switch (str[i+1]) {
                case '':
                    newLine()
            }
        } else if (str[i] == '\x25' && str[i+1] != '\0') {

            switch (str[i+1]) {
                case 'i':
                    int elem = va_arg(args, 1);


            }
        }
        putChar(str[i]);
    }
}*/



// Comandos Alex (a partir de acá)



static char stdoutArr[SIZE_BUFFER];
static int sizeOut = 0;
static int startsOut = 0;
static char stdinArr[SIZE_BUFFER];
static int sizeIn = 0;
static int startsIn = 0;

int getSizeIn(){
	return sizeIn;
}

static char videoModeOn = 0;

void printCharInScreen(char c, int x, int y){
    if (c == 'c'){
        // esto es para probar
        putPixel(0x00ffffff, x, y);
    }

}


// 1. imprime en un color
void putOut(char c){
    // mete c en el vector cíclico
    // TODO: falta manejar excepciones especialmente si sizeOut es demasiado grande

    int pos = (startsOut + sizeOut) % SIZE_BUFFER;
	stdoutArr[pos]=c;
    sizeOut++;
    if (sizeOut > SIZE_BUFFER) sizeOut -= SIZE_BUFFER;
    putChar(c);

    // printOutInScreen(charSize);
}


void putErr(char c){
	// TODO: falta cambiar putChar por putColorChar o como se llame

	int pos = (startsOut + sizeOut) % SIZE_BUFFER;
	stdoutArr[pos]=c;
    sizeOut++;
    if (sizeOut > SIZE_BUFFER) sizeOut -= SIZE_BUFFER;
    putCharColoured(c, 0x00ff0000, 0x00000000);

}

void putIn(char c){
    // caso especial donde se pasa del límite: no se pueden agregar caracteres
    // podríamos hacer que aparezca un mensaje o algo así
    if (sizeIn >= SIZE_BUFFER-1) return;

    // mete c en el vector cíclico
    int pos = (startsIn + sizeIn) % SIZE_BUFFER;

    stdinArr[pos] = c;
    sizeIn++;
}

void clearIn(){
    sizeIn = 0;
}

void clearOut(){
    sizeOut = 0;
}

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

int sys_read(int fd, char* buf, int count){
    int i=0;
    if (fd==0){
        for(i=0; i<count && i<sizeIn; i++){
            buf[i] = stdinArr[(startsIn + i)%SIZE_BUFFER];

        }
        startsIn+=i;
        startsIn = startsIn%SIZE_BUFFER;
        sizeIn-=i;
    }
    return i;
}

uint8_t fontSize = 2;

void sys_textmode(char enabled, int newSize){
    if (enabled) videoModeOn = 0;
    else videoModeOn = 1;
    // el size se cambia de todas formas si está en un valor en el rango;
    newFontSize(newSize);
}


void putCharAt(uint8_t c, uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor) {

    if (xOutOfBounds(x)) {
        newLine(x, y);
    }

    if (yOutOfBounds(y)) {
        clearScreen(backgroundColor);
        *y = 0;
    }

    uint8_t charMap[FONT_HEIGHT][FONT_WIDTH];
    getCharMap(c, charMap);

    for (int i = 0; i < FONT_HEIGHT ; i++) {
        for (int j = 0; j < FONT_WIDTH ; j++) {
            uint8_t squareIsOn = charMap[i][j];
            putSquare(squareIsOn ? foreColor : backgroundColor, *x + j * fontSize, *y + i * fontSize, fontSize);
        }
    }
    *x += FONT_WIDTH * fontSize;
}


void deleteCharAt(uint64_t * x, uint64_t * y, uint64_t foreColor, uint64_t backgroundColor) {
    if (*x == 0 && *y == 0) return;         // no borra si no hay nada
    *x -= FONT_WIDTH * fontSize;
    if (xOutOfBounds(x)) {
        int lastX = ((getWidth() -1) / (FONT_WIDTH * fontSize) - 1 ) * (FONT_WIDTH * fontSize);  // esto hay que ponerlo en otro lado
        *x = lastX;
        *y -= FONT_HEIGHT * fontSize;
    }
    putCharAt(' ', x, y, foreColor, backgroundColor);
    *x -= FONT_WIDTH * fontSize;
}


// TODO: falta testear
void newFontSize(int newSize) {
    if (newSize < 1 || newSize > 5)
        return;
    fontSize = newSize;
    sys_clearScreen();
    x = 0;
    y = 0;
}

void newLine(uint64_t * x, uint64_t * y) {
    *x = 0;
    *y += FONT_HEIGHT * fontSize;
}



int xOutOfBounds(uint64_t * x) {
    return *x + FONT_WIDTH * fontSize >= getWidth() || (int)*x < 0;     // casteo a int para que me tome que existen los negativos
}

int yOutOfBounds(uint64_t * y) {
    return *y + FONT_HEIGHT * fontSize >= getHeight() || (int)*y < 0;
}
