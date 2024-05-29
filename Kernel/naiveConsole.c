#include <naiveConsole.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;
static const uint32_t width = 80;
static const uint32_t height = 25 ;

typedef struct {
    char character;
    int make_code;
    int break_code;
    char isLower;
} AsciiMap;

const AsciiMap map[256] = {
        {'\x0',  0x0, 0x0, 0},
        {'\x1',  0x0, 0x0, 0},
        {'\x2',  0x0, 0x0, 0},
        {'\x3',  0x0, 0x0, 0},
        {'\x4',  0x0, 0x0, 0},
        {'\x5',  0x0, 0x0, 0},
        {'\x6',  0x0, 0x0, 0},
        {'\x7',  0x0, 0x0, 0},
        {'\x8',  0x0, 0x0, 0},
        {'\x9',  0x0, 0x0, 0},
        {'\xa',  0x0, 0x0, 0},
        {'\xb',  0x0, 0x0, 0},
        {'\xc',  0x0, 0x0, 0},
        {'\xd',  0x0, 0x0, 0},
        {'\xe',  0x0, 0x0, 0},
        {'\xf',  0x0, 0x0, 0},
        {'\x10', 0x0, 0x0, 0},
        {'\x11', 0x0, 0x0, 0},
        {'\x12', 0x0, 0x0, 0},
        {'\x13', 0x0, 0x0, 0},
        {'\x14', 0x0, 0x0, 0},
        {'\x15', 0x0, 0x0, 0},
        {'\x16', 0x0, 0x0, 0},
        {'\x17', 0x0, 0x0, 0},
        {'\x18', 0x0, 0x0, 0},
        {'\x19', 0x0, 0x0, 0},
        {'\x1a', 0x0, 0x0, 0},
        {'\x1b', 0x0, 0x0, 0},
        {'\x1c', 0x0, 0x0, 0},
        {'\x1d', 0x0, 0x0, 0},
        {'\x1e', 0x0, 0x0, 0},
        {'\x1f', 0x0, 0x0, 0},
        {'\x20', 0x39, 0xB9, 0},
        {'\x21', 0x28, 0xA8, 0},
        {'\x22', 0x0, 0x0, 0},
        {'\x23', 0x0, 0x0, 0},
        {'\x24', 0x0, 0x0, 0},
        {'\x25', 0x0, 0x0, 0},
        {'\x26', 0x0, 0x0, 0},
        {'\x27', 0x0, 0x0, 0},
        {'\x28', 0x0, 0x0, 0},
        {'\x29', 0x0, 0x0, 0},
        {'\x2a', 0x0, 0x0, 0},
        {'\x2b', 0x0, 0x0, 0},
        {'\x2c', 0x33, 0xB3, 0},
        {'\x2d', 0x0C, 0x8C, 0},
        {'\x2e', 0x34, 0xB4, 0},
        {'\x2f', 0x35, 0xB5, 0},
        {'\x30', 0x0B, 0x8B, 0},
        {'\x31', 0x02, 0x82, 0},
        {'\x32', 0x03, 0x83, 0},
        {'\x33', 0x04, 0x84, 0},
        {'\x34', 0x05, 0x85, 0},
        {'\x35', 0x06, 0x86, 0},
        {'\x36', 0x07, 0x87, 0},
        {'\x37', 0x08, 0x88, 0},
        {'\x38', 0x09, 0x89, 0},
        {'\x39', 0x0A, 0x8A, 0},
        {'\x3a', 0x0, 0x0, 0},
        {'\x3b', 0x27, 0xA7, 0},
        {'\x3c', 0x0, 0x0, 0},
        {'\x3d', 0x0D, 0x8D, 0},
        {'\x3e', 0x0, 0x0, 0},
        {'\x3f', 0x0, 0x0, 0},
        {'\x40', 0x0, 0x0, 0},
        {'\x41', 0x1E, 0x9E, 0},
        {'\x42', 0x30, 0xB0, 0},
        {'\x43', 0x2E, 0xAE, 0},
        {'\x44', 0x20, 0xA0, 0},
        {'\x45', 0x12, 0x92, 0},
        {'\x46', 0x21, 0xA1, 0},
        {'\x47', 0x22, 0xA2, 0},
        {'\x48', 0x23, 0xA3, 0},
        {'\x49', 0x17, 0x97, 0},
        {'\x4a', 0x24, 0xA4, 0},
        {'\x4b', 0x25, 0xA5, 0},
        {'\x4c', 0x26, 0xA6, 0},
        {'\x4d', 0x32, 0xB2, 0},
        {'\x4e', 0x31, 0xB1, 0},
        {'\x4f', 0x18, 0x98, 0},
        {'\x50', 0x19, 0x99, 0},
        {'\x51', 0x10, 0x90, 0},
        {'\x52', 0x13, 0x93, 0},
        {'\x53', 0x1F, 0x9F, 0},
        {'\x54', 0x14, 0x94, 0},
        {'\x55', 0x16, 0x96, 0},
        {'\x56', 0x2F, 0xAF, 0},
        {'\x57', 0x11, 0x91, 0},
        {'\x58', 0x2D, 0xAD, 0},
        {'\x59', 0x15, 0x95, 0},
        {'\x5a', 0x2C, 0xAC, 0},
        {'\x5b', 0x1A, 0x9A, 0},
        {'\x5c', 0x2B, 0xAB, 0},
        {'\x5d', 0x1B, 0x9B, 0},
        {'\x5e', 0x0, 0x0, 0},
        {'\x5f', 0x0, 0x0, 0},
        {'\x60', 0x29, 0xA9, 0},
        {'\x61', 0x1E, 0x9E, 1},  // 'a'
        {'\x62', 0x30, 0xB0, 1},  // 'b'
        {'\x63', 0x2E, 0xAE, 1},  // 'c'
        {'\x64', 0x20, 0xA0, 1},  // 'd'
        {'\x65', 0x12, 0x92, 1},  // 'e'
        {'\x66', 0x21, 0xA1, 1},  // 'f'
        {'\x67', 0x22, 0xA2, 1},  // 'g'
        {'\x68', 0x23, 0xA3, 1},  // 'h'
        {'\x69', 0x17, 0x97, 1},  // 'i'
        {'\x6A', 0x24, 0xA4, 1},  // 'j'
        {'\x6B', 0x25, 0xA5, 1},  // 'k'
        {'\x6C', 0x26, 0xA6, 1},  // 'l'
        {'\x6D', 0x32, 0xB2, 1},  // 'm'
        {'\x6E', 0x31, 0xB1, 1},  // 'n'
        {'\x6F', 0x18, 0x98, 1},  // 'o'
        {'\x70', 0x19, 0x99, 1},  // 'p'
        {'\x71', 0x10, 0x90, 1},  // 'q'
        {'\x72', 0x13, 0x93, 1},  // 'r'
        {'\x73', 0x1F, 0x9F, 1},  // 's'
        {'\x74', 0x14, 0x94, 1},  // 't'
        {'\x75', 0x16, 0x96, 1},  // 'u'
        {'\x76', 0x2F, 0xAF, 1},  // 'v'
        {'\x77', 0x11, 0x91, 1},  // 'w'
        {'\x78', 0x2D, 0xAD, 1},  // 'x'
        {'\x79', 0x15, 0x95, 1},  // 'y'
        {'\x7A', 0x2C, 0xAC, 1},  // 'z'
        {'\x7b', 0x0, 0x0, 0},
        {'\x7c', 0x0, 0x0, 0},
        {'\x7d', 0x0, 0x0, 0},
        {'\x7e', 0x0, 0x0, 0},
        {'\x7f', 0x0, 0x0, 0},
        {'\x80', 0x0, 0x0, 0},
        {'\x81', 0x0, 0x0, 0},
        {'\x82', 0x0, 0x0, 0},
        {'\x83', 0x0, 0x0, 0},
        {'\x84', 0x0, 0x0, 0},
        {'\x85', 0x0, 0x0, 0},
        {'\x86', 0x0, 0x0, 0},
        {'\x87', 0x0, 0x0, 0},
        {'\x88', 0x0, 0x0, 0},
        {'\x89', 0x0, 0x0, 0},
        {'\x8a', 0x0, 0x0, 0},
        {'\x8b', 0x0, 0x0, 0},
        {'\x8c', 0x0, 0x0, 0},
        {'\x8d', 0x0, 0x0, 0},
        {'\x8e', 0x0, 0x0, 0},
        {'\x8f', 0x0, 0x0, 0},
        {'\x90', 0x0, 0x0, 0},
        {'\x91', 0x0, 0x0, 0},
        {'\x92', 0x0, 0x0, 0},
        {'\x93', 0x0, 0x0, 0},
        {'\x94', 0x0, 0x0, 0},
        {'\x95', 0x0, 0x0, 0},
        {'\x96', 0x0, 0x0, 0},
        {'\x97', 0x0, 0x0, 0},
        {'\x98', 0x0, 0x0, 0},
        {'\x99', 0x0, 0x0, 0},
        {'\x9a', 0x0, 0x0, 0},
        {'\x9b', 0x0, 0x0, 0},
        {'\x9c', 0x0, 0x0, 0},
        {'\x9d', 0x0, 0x0, 0},
        {'\x9e', 0x0, 0x0, 0},
        {'\x9f', 0x0, 0x0, 0},
        {'\xa0', 0x0, 0x0, 0},
        {'\xa1', 0x0, 0x0, 0},
        {'\xa2', 0x0, 0x0, 0},
        {'\xa3', 0x0, 0x0, 0},
        {'\xa4', 0x0, 0x0, 0},
        {'\xa5', 0x0, 0x0, 0},
        {'\xa6', 0x0, 0x0, 0},
        {'\xa7', 0x0, 0x0, 0},
        {'\xa8', 0x0, 0x0, 0},
        {'\xa9', 0x0, 0x0, 0},
        {'\xaa', 0x0, 0x0, 0},
        {'\xab', 0x0, 0x0, 0},
        {'\xac', 0x0, 0x0, 0},
        {'\xad', 0x0, 0x0, 0},
        {'\xae', 0x0, 0x0, 0},
        {'\xaf', 0x0, 0x0, 0},
        {'\xb0', 0x0, 0x0, 0},
        {'\xb1', 0x0, 0x0, 0},
        {'\xb2', 0x0, 0x0, 0},
        {'\xb3', 0x0, 0x0, 0},
        {'\xb4', 0x0, 0x0, 0},
        {'\xb5', 0x0, 0x0, 0},
        {'\xb6', 0x0, 0x0, 0},
        {'\xb7', 0x0, 0x0, 0},
        {'\xb8', 0x0, 0x0, 0},
        {'\xb9', 0x0, 0x0, 0},
        {'\xba', 0x0, 0x0, 0},
        {'\xbb', 0x0, 0x0, 0},
        {'\xbc', 0x0, 0x0, 0},
        {'\xbd', 0x0, 0x0, 0},
        {'\xbe', 0x0, 0x0, 0},
        {'\xbf', 0x0, 0x0, 0},
        {'\xc0', 0x0, 0x0, 0},
        {'\xc1', 0x0, 0x0, 0},
        {'\xc2', 0x0, 0x0, 0},
        {'\xc3', 0x0, 0x0, 0},
        {'\xc4', 0x0, 0x0, 0},
        {'\xc5', 0x0, 0x0, 0},
        {'\xc6', 0x0, 0x0, 0},
        {'\xc7', 0x0, 0x0, 0},
        {'\xc8', 0x0, 0x0, 0},
        {'\xc9', 0x0, 0x0, 0},
        {'\xca', 0x0, 0x0, 0},
        {'\xcb', 0x0, 0x0, 0},
        {'\xcc', 0x0, 0x0, 0},
        {'\xcd', 0x0, 0x0, 0},
        {'\xce', 0x0, 0x0, 0},
        {'\xcf', 0x0, 0x0, 0},
        {'\xd0', 0x0, 0x0, 0},
        {'\xd1', 0x0, 0x0, 0},
        {'\xd2', 0x0, 0x0, 0},
        {'\xd3', 0x0, 0x0, 0},
        {'\xd4', 0x0, 0x0, 0},
        {'\xd5', 0x0, 0x0, 0},
        {'\xd6', 0x0, 0x0, 0},
        {'\xd7', 0x0, 0x0, 0},
        {'\xd8', 0x0, 0x0, 0},
        {'\xd9', 0x0, 0x0, 0},
        {'\xda', 0x0, 0x0, 0},
        {'\xdb', 0x0, 0x0, 0},
        {'\xdc', 0x0, 0x0, 0},
        {'\xdd', 0x0, 0x0, 0},
        {'\xde', 0x0, 0x0, 0},
        {'\xdf', 0x0, 0x0, 0},
        {'\xe0', 0x0, 0x0, 0},
        {'\xe1', 0x0, 0x0, 0},
        {'\xe2', 0x0, 0x0, 0},
        {'\xe3', 0x0, 0x0, 0},
        {'\xe4', 0x0, 0x0, 0},
        {'\xe5', 0x0, 0x0, 0},
        {'\xe6', 0x0, 0x0, 0},
        {'\xe7', 0x0, 0x0, 0},
        {'\xe8', 0x0, 0x0, 0},
        {'\xe9', 0x0, 0x0, 0},
        {'\xea', 0x0, 0x0, 0},
        {'\xeb', 0x0, 0x0, 0},
        {'\xec', 0x0, 0x0, 0},
        {'\xed', 0x0, 0x0, 0},
        {'\xee', 0x0, 0x0, 0},
        {'\xef', 0x0, 0x0, 0},
        {'\xf0', 0x0, 0x0, 0},
        {'\xf1', 0x0, 0x0, 0},
        {'\xf2', 0x0, 0x0, 0},
        {'\xf3', 0x0, 0x0, 0},
        {'\xf4', 0x0, 0x0, 0},
        {'\xf5', 0x0, 0x0, 0},
        {'\xf6', 0x0, 0x0, 0},
        {'\xf7', 0x0, 0x0, 0},
        {'\xf8', 0x0, 0x0, 0},
        {'\xf9', 0x0, 0x0, 0},
        {'\xfa', 0x0, 0x0, 0},
        {'\xfb', 0x0, 0x0, 0},
        {'\xfc', 0x0, 0x0, 0},
        {'\xfd', 0x0, 0x0, 0},
        {'\xfe', 0x0, 0x0, 0},
        {'\xff', 0x0, 0x0, 0}
};


void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void writeCharacter(unsigned char c, unsigned char forecolour, unsigned char backcolour)
{
    uint16_t attrib = (backcolour << 4) | (forecolour & 0x0F);

    *currentVideo = c;
    *(currentVideo+1) = attrib;
    currentVideo+=2;
}

void writeStr(char * str, unsigned char forecolour, unsigned char backcolour) {
    for (int i = 0 ; *(str+i) != '\0' ; i++) {
        writeCharacter(*(str+i), forecolour, backcolour);
    }
}

void ncPrintChar(char character)
{
	*currentVideo = character;
	currentVideo += 2;
}

void ncNewline()
{
	do
	{
		ncPrintChar(' ');
	}
	while((uint64_t)(currentVideo - video) % (width * 2) != 0);
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

char mapKey(char character[2]) {
    for (int i = 0 ; i < 256 ; i++) {
        if (map[i].make_code == character[0]) {
            if (character[1] == 1 && map[i].character >= 'A' && map[i].character <= 'Z') {
                return map[i].character + 'a' - 'A';
            }
            return map[i].character;
        }
    }
    return '\0';
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
