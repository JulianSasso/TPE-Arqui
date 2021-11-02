#include <syscallDispatcher.h>

uint64_t syscallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9) {
	switch (rdi) {
		case 0:
			return kb_getChar(); // getChar
		case 1:
			ncPrintCharWithColor((char) rsi, 0x02); //putChar
			return 1;
	}

    // Por default devuelve 0
	return 0;
}
