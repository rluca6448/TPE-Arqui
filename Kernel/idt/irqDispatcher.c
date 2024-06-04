#include <time.h>
#include <stdint.h>
#include <naiveConsole.h>
#include <keyboard.h>

static void int_20();
static void int_21();
static int offset_stdout = 0;

void irqDispatcher(uint64_t irq) {
	switch (irq) {
		case 0:
			int_20();
			break;
        case 1:
		 	int_21();
		 	break;
	}
	return;
}

void int_20() {
	timer_handler();
}

 void int_21() {
 	keyboard_handler();
 }

// void int80_write(uint64_t rax, int rbx, char* rcx, uint64_t rdx){
// 	char toWrite[rdx] ;
// 	for (int i=0; i<rdx; i++){
// 			toWrite[i] = rcx[i];
// 		}
// 		toWrite[rdx] = 0;
// 	if (rbx==1) {
// 		print_text_mode(toWrite, offset_stdout, 0x0F);
// 		offset_stdout += rdx;
// 	}
// 	else if (rbx==2) {
// 		print_text_mode(toWrite, offset_stdout, 0x0C);
// 		offset_stdout += rdx;
// 	}
	
// }

// void print_text_mode(char * text, int offset, char color) {
// 	for (int i=0; text[i]; i++){
// 		char * v = (char*)0xB8000 + (i+offset) * 2;
// 		*v = text[i];
// 		*(v+1) = color;
// 	}
// }
