#include <stdint.h>
#include "video.h"
#include "exceptions.h"
#include "IO.h"
#include "lib.h"

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
}

static void zero_division() {
    sys_write(2 ,zero_division_exception_message, buflen(zero_division_exception_message));
}

static void invalid_opcode() {
    sys_write(2, invalid_opcode_exception_message, buflen(zero_division_exception_message));
}

static void showRegisters(const uint64_t regex[18]){
    return;
}