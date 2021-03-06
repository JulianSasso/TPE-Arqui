#include <terminal.h>

static char * commandsNames[COMMANDS_COUNT];
static char * commandsDesc[COMMANDS_COUNT];
static void (*commandsFn[COMMANDS_COUNT])(int argSize, char *args[]);

static int commandIndex = 0;

void startTerminal(){
    startCommands();
    char buffer[BUFFER_SIZE] = {0};
    while(1){
        printWithColor("$> ", GREEN_BLACK);
        scan(buffer, BUFFER_SIZE);
        putChar('\n');
        executeCommand(buffer);
    }
}

void startCommands(){
    commandBuilder("help", "Displays information about every command available.", &help);
    commandBuilder("clear", "Clears the screen.", &clearScreen);
    commandBuilder("inforeg", "Displays the information of all the registers, if saved before.", &getRegisters);
    commandBuilder("printmem", "Displays a 32 bytes memory dump of the address passed as an argument", &printmem);
    commandBuilder("time", "Displays the current time and date.", &printTime);
    commandBuilder("divzero", "Displays exception of division by zero.", &divZero);
    commandBuilder("invalidopcode", "Displays exception of an invalid operation code.", &invalidOpCode);
    commandBuilder("gamemode", "Changes the system to game mode + chronometer", &gamemode);
}

void commandBuilder(char *name, char *desc, void (*fn)()){
    commandsNames[commandIndex] = name;
    commandsDesc[commandIndex] = desc;
    commandsFn[commandIndex] = fn;
    commandIndex++;
}

void executeCommand(char *buffer){
    char *arguments[3];
    int argumentsCount = strtok(buffer, ' ', arguments, 3);

    if(argumentsCount <= 0 || argumentsCount > 2){
        print("Invalid amount of arguments.\n");
        return;
    }

    for(int i=0; i< COMMANDS_COUNT; i++){
        if(strcmp(buffer, commandsNames[i]) == 0){
            (*commandsFn[i])(argumentsCount - 1, arguments + 1);
            return;
        }
    }
    print("Invalid command.\n");
}

void help(){
    for(int i=0; i < COMMANDS_COUNT; i++){
        printWithColor(commandsNames[i], YELLOW_BLACK);
        print(" - ");
        print(commandsDesc[i]);
        putChar('\n');
    }
}

void clearScreen(){
    clear();
}

void getRegisters(){
    sys_getRegistersInfo();
}

void printmem(int argSize, char *args[]){
    if(argSize != 1){
        print("Invalid amount of arguments.\n");
        return;
    }
    unsigned long address = hexaStringToInt(args[0]);
    sys_PrintMem(address);
}

void printTime(){
    char str[3];
    int hours = sys_getTime(HOURS);

    itoa(hours, str);
    print(str);

    print(":");

    itoa(sys_getTime(MINUTES), str);
    print(str);

    print(" - ");

    itoa(sys_getTime(DAY), str);
    print(str);

    print("/");

    itoa(sys_getTime(MONTH), str);
    print(str);

    print("/");

    itoa(sys_getTime(YEAR), str);
    print(str);

    putChar('\n');
}

void gamemode(){
    clear();
    drawGameMode();
    gamemodeManager();
    clear();     
}

void divZero(){
    int x = 1/0;
}

void invalidOpCode(){
    sys_raiseInvOpCodeExc();
}

