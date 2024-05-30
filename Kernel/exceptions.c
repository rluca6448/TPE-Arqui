#include <stdint.h>
#include "video.h"
#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 1

static void zero_division(uint64_t regex[18]);
static void invalid_opcode(uint64_t regex[18]);



void exceptionDispatcher(int exception, const uint64_t regex[18]) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division(regex);
	if (exception == INVALID_OPCODE_ID)
		invalid_opcode(regex);
}

static void zero_division(uint64_t regex[18]) {
	// Handler para manejar excepcíon
	//Mensaje de error por pantalla

	//Muestra de registros

	//Regreso a la Shell
}

static void invalid_opcode(uint64_t regex[18]){
	//Handler para manejar excepcion
	//Mensaje de error por pantalla

	//Muestra de registros

	//Regreso a la Shell
}