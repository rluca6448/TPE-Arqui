#ifndef TPE_SHELL_H
#define TPE_SHELL_H


#include <stdint.h>


void shell();
void printHeader();
void execute(char *inputBuffer);

//para excepciones
void runInvalidOpcode(void);
void runDivideByZero(void);

#endif //TPE_SHELL_H