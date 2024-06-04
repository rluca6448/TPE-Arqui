#include <stdint.h>
#include <video.h>
#include <time.h>
#include <interrupts.h>
#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 1

static void zero_division();
static void invalid_opcode();
static void showRegisters(const uint64_t regex[18]);

static const char* registerNames[18] = {
        "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP", "R8 ", "R9 ", "R10", "R11", "R12", "R13", "R14", "R15", "RIP", "RFLAGS"
};

static const char* zero_division_exception_message = "Error Divide by Zero Exception";

static const char* invalid_opcode_exception_message = "Error Invalid Opcode Exception";

void exceptionDispatcher(int exception, const uint64_t regex[18]) {
	if (exception == ZERO_EXCEPTION_ID){
        zero_division();
    }
	else if (exception == INVALID_OPCODE_ID){
        invalid_opcode();
    }
    showRegisters(regex);
    int secondsElapsed = seconds_elapsed();
    //Esperamos 4 segundos para que el usuario tenga tiempo de ver el error
    do { _hlt() } while (secondsElapsed - seconds_elapsed() < 4);
    clearIn();
    printfCouloured("Presione cualquier tecla para volver", OUT_FORE_COLOR, OUT_BACK_COLOR);
    do { _hlt() } while ( getIn() == 0);
    clearIn();
    clearScreen(OUT_BACK_COLOR);
    _cli();
}

static void zero_division() {
    printfCouloured(zero_division_exception_message, ERR_FORE_COLOR, ERR_BACK_COLOR);
}

static void invalid_opcode() {
    printfCouloured(invalid_opcode_exception_message, ERR_FORE_COLOR, ERR_BACK_COLOR);
}

//FALTA DESARROLLAR
static void showRegisters(const uint64_t regex[18]){
    return;
}