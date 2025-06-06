/* sampleCodeModule.c */

#include <stdint.h>
#include <string.h>

extern void sys_write(int fd, const char* buf, int count);
extern void test_int_80h();


static int var1 = 0;
static int var2 = 0;

//DESARROLLO DE LAS FUNCIONES QUE EJECUTAN LOS COMANDOS:
//SIEMPRE CHECKEAR LOS PARAMETROS DADOS (CANTIDAD EXACTA)

//Ej de funcion (La funcion run se encuentra en la carpeta de libasm):
// static void invalidOpcodeException(char parameters[PARAM_QUANT][PARAM_LENGTH]){
//      if(parameters[0][0] != 0){
//          printear que se tiene que invocar al comando sin parametro
//      }
//      runInvalidOpcodeException();
// }

//Ej de funcion
//  static void zeroDivisionException(char parameters[PARAM_QUANT][PARAM_LENGTH]){
//      if(parameters[0][0] != 0){
//          printear que se tiene que invocar al comando sin parametro
//      }
//      runZeroDivisionException();
//  }


//DECLARACION DE VECTOR DE COMANDOS DE LA SHELL
//static const char* commands[] = {"commando 1","commando 2", "commando 3"}


//FUNCION QUE DEVUELVE NRO DE COMANDO LEYENDO DEL BUFFER (DEBE PASARSELO LA FUNCION readInput)
//#define COMMANDS_LENGTH (sizeof(commands)/sizeof(commands[0]))
//static int indexCommand(char* readBuffer) {
//    char *p = readBuffer;
//    for(int i=0; i<COMMANDS_LENGTH; i++) {
//        int cmp;
//        if((cmp = strcmp(p,commands[i])) < 0){
//            return -1;
//        }
//        if(cmp == 0){
//            return i;
//        }
//    }
//    return -1;
//}

//FUNCION QUE LEE DEL BUFFER INGRESADO POR EL USUARIO, Y ALMACENA EL RESULTADO EN:
// 1 STRING: EL STRING DEL COMANDO
// 1 STRING[]: LOS PARAMETROS INGRESADOS POR EL USUARIO
//static void readInput(char command[COMMAND_LENGTH], char parameters[PARAM_QUANT][PARAM_LENGTH], char readBuffer[READ_BUFF_LEGTH])

//FUNCION QUE EJECUTE EL COMANDO CON LOS PARAMETROS DADOS
//static void executeCommand(int commandIndex, char parameters[PARAM_QUANT][PARAM_LENGTH]){
//
// }


int main() {
    test_int_80h;
    //Limpiar pantalla

    //Print de entrada a shell + Print de Type "HELP" for a list of commands.

    //Loop infinito (con while(1))de:{

    //Lectura de ingreso de comando
    //Un getter del commando
    //Si se encuentra el comando, se ejecuta, y sino print de "command not found/n"

    //} Fin del loop infinito

    //Test if BSS is properly set up
    if (var1 == 0 && var2 == 0)
        return 0xDEADC0DE;

    return 0xDEADBEEF;
}
