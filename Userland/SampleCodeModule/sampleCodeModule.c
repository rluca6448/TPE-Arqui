/* sampleCodeModule.c */

#include <stdint.h>

extern void sys_write(int fd, const char* buf, int count);
extern void test_int_80h();


static int var1 = 0;
static int var2 = 0;

int main() {
	test_int_80h;
	sys_write(1, "este es un mensaje", 18);

    //Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;

	return 0xDEADBEEF;
}
