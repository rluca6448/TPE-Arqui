#include <stdint.h>
#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 1

static void zero_division();

void exceptionDispatcher(int exception, const uint64_t regex[18]) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division(regex);
	if (exception == INVALID_OPCODE_ID)
		invalid_opcode(regex);
}

static void zero_division(uint64_t regex[18]) {
	// Handler para manejar excepcíon
}

static void invalid_opcode(uint64_t regex[18]){
	//Handler para manejar excepcion
}