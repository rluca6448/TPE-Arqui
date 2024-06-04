#include <time.h>
#include <lib.h>
#include <naiveConsole.h>

static unsigned long ticks = 0;

// static char keys[200];
// static int key_amount = 0;

void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}

// void keyboard_handler() {

// 	char key = get_key();

// 	key = key_to_ascii(key);

// 	if(!key) return;
// 	if(key_amount > 10) return;

// 	keys[key_amount] = key;
// 	key_amount ++;

// 	ncPrintChar(key);
// }

// int size_keys(){
// 	return key_amount;
// } 
// char * all_keys(){
// 	return keys;
// }

// char key_to_ascii(char key) {
//     switch(key) {
//         case 0x01: return '1';
//         case 0x02: return '2';
//         case 0x03: return '3';
//         case 0x04: return '4';
//         case 0x05: return '5';
//         case 0x06: return '6';
//         case 0x07: return '7';
//         case 0x08: return '8';
//         case 0x09: return '9';
//         case 0x0A: return '0';
//         case 0x0B: return '-';
//         case 0x0C: return '=';
//         case 0x0D: return '\b';  // Backspace
//         case 0x0E: return '\t';  // Tab
//         case 0x0F: return 'q';
//         case 0x10: return 'w';
//         case 0x11: return 'e';
//         case 0x12: return 'r';
//         case 0x13: return 't';
//         case 0x14: return 'y';
//         case 0x15: return 'u';
//         case 0x16: return 'i';
//         case 0x17: return 'o';
//         case 0x18: return 'p';
//         case 0x19: return '[';
//         case 0x1A: return ']';
//         case 0x1B: return '\n'; // Newline
//         case 0x1C: return 0;     // Control
//         case 0x1D: return 0;     // Left Shift
//         case 0x1E: return 'a';
//         case 0x1F: return 's';
//         case 0x20: return 'd';
//         case 0x21: return 'f';
//         case 0x22: return 'g';
//         case 0x23: return 'h';
//         case 0x24: return 'j';
//         case 0x25: return 'k';
//         case 0x26: return 'l';
//         case 0x27: return ';';
//         case 0x28: return '\'';
//         case 0x29: return '`';
//         case 0x2A: return 0;     // Left Shift
//         case 0x2B: return '\\';
//         case 0x2C: return 'z';
//         case 0x2D: return 'x';
//         case 0x2E: return 'c';
//         case 0x2F: return 'v';
//         case 0x30: return 'b';
//         case 0x31: return 'n';
//         case 0x32: return 'm';
//         // Add more cases for other keys
//         default: return 0; // Return 0 for keys that don't have an ASCII representation
//     }
// }
