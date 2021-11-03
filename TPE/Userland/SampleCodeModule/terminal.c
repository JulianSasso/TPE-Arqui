#include <terminal.h>
#include <stdio.h>
#include <strings.h>

#define COMMANDS_COUNT 10
#define BUFFER_SIZE 50


static char * commandsNames[COMMANDS_COUNT];
static char * commandsDesc[COMMANDS_COUNT];
static void (*commandsFn)(int argSize, char *args[])[COMMANDS_COUNT];


void startTerminal(){
    startCommands();
    char buffer[BUFFER_SIZE];
    while(strcmp(buffer, "exit") != 0){
        printWithColor("$> ", GREEN_BLACK);
        scan(buffer, BUFFER_SIZE);
        executeCommand(buffer);
    }
}

void startCommands(){
    commandBuilder("help", "Displays information about every command available.\n", &help, 0);
    commandBuilder("inforeg", "Displays the information of all the registers.\n", &inforeg, 1);
    commandBuilder("printmem", "Displays a 32 bytes memory dump of the address passed as an argument.\n", &printmem, 2);
    commandBuilder("time", "Displays the current time and date.\n", &printTime, 3);
    commandBuilder("divZero", "Displays exception of division by zero.\n", &divZero, 4);
    commandBuilder("invalidOpCode", "Displays exception of an invalid operation code.\n", &invalidOpCode, 5);
}

void commandBuilder(char *name, char *desc, void (*fn)(), int index){
    commandsNames[index] = name;
    commandsDesc[index] = desc;
    commandsFn[index] = fn;
}

void executeCommand(char *buffer){
    for(int i=0; i< COMMANDS_COUNT; i++){
        if(strcmp(buffer, commandsNames[i])){
            commandsFn[i]();
        }
    }
    print("Invalid command.\n")
}

void help(){
    for(int i=0; i < COMMANDS_COUNT; i++){
        print(commandsNames[i]);
        print(" - ");
        print(commandsDesc[i]);
        putChar('\n')
    }
}

void inforeg(){

}

void printmem(int argSize, char *args[]){

}

void printTime(){

}

void divZero(){

}

void invalidOpCode(){

}

