#ifndef _STDIO_H
#define _STDIO_H

extern char sys_getChar();
extern void sys_putCharWC(char c, unsigned char colorCode);
extern int sys_getTime(int descriptor);
extern void sys_getRegistersInfo();
extern void sys_clear();
extern void sys_PrintMem(char * address);
extern void sys_printInPos(char * string, int row, int col, unsigned char colorCode);
extern unsigned long sys_getDeciseconds();
extern void sys_raiseInvOpCodeExc();

char getChar();
char getCharOrNull();
void print(char * string);
void putChar(char c);
void putCharWithColor(char c, unsigned char colorCode);
int scan(char *buffer, int size);
void printWithColor(char * string, unsigned char colorCode);
void clear();
int getTime(int descriptor);
unsigned long getDeciseconds();

//#define BACKSPACE 0x0E
#define BACKSPACE '\b'

// COLORES: El formato es COLORLETRA_COLORFONDO
#define BLUE_BLACK 0x01
#define GREEN_BLACK 0x02
#define CYAN_BLACK 0x03
#define RED_BLACK 0x04
#define MAGENTA_BLACK 0x05
#define ORANGE_BLACK 0x06
#define GREY_BLACK 0x07
#define YELLOW_BLACK 0x0E
#define WHITE_BLACK 0x0F
#define RED_RED 0x44
#define MAGENTA_MAGENTA 0x55
#define WHITE_WHITE 0xFF
    
#endif
