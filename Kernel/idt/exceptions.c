#include <stdint.h>
#include "video.h"
#include <exceptions.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 1

static void zero_division(const uint64_t regex[18]);
static void invalid_opcode(const uint64_t regex[18]);

static const char* registerNames[18] = {
        "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP", "R8 ", "R9 ", "R10", "R11", "R12", "R13", "R14", "R15", "RIP", "RFLAGS"
};

static const char* zero_division_exception_message = "Error Divide by Zero Exception";

static const char* invalid_opcode_exception_message = "Error Invalid Opcode Exception";

void exceptionDispatcher(int exception, const uint64_t regex[18]) {
	if (exception == ZERO_EXCEPTION_ID){
        zero_division(regex);
    }
	else if (exception == INVALID_OPCODE_ID){
        invalid_opcode(regex);
    }
    //showRegisters(regex);

}

static void zero_division(const uint64_t regex[18]) {
	// Handler para manejar excepcíon
	//Mensaje de error por pantalla IDEA
    //printErr(zero_division_exception_message);
}

static void invalid_opcode(const uint64_t regex[18]) {
	//Handler para manejar excepcion
	//Mensaje de error por pantalla IDEA
    //printErr(invalid_opcode_exception_message);
}