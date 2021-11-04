#include <stdio.h>

char getChar(){
    char c;
    while((c = sys_getChar()) == 0);
    return c;
}

void putCharWithColor(char c, unsigned char colorCode){
    if(c != 0)
        sys_putCharWC(c, colorCode);
}

void putChar(char c){
    if(c != 0)
        sys_putCharWC(c, WHITE_BLACK);
}

void print(char * string){
    while (*string != 0){
        putChar(*string);
        string++;
    }    
}

void printWithColor(char * string, unsigned char colorCode){
    while (*string != 0){
        putCharWithColor(*string, colorCode);
        string++;
    }    
}

int scan(char *buffer, int size){
    char c;
    int lenght=0;
    while((c = getChar()) != '\n' && lenght < size){
        putChar(c);
        buffer[lenght++] = c;
    }
    buffer[lenght] = 0;
    return lenght;
}

void clear(){
    sys_clear();
}