#include <exceptions.h>

static initialState initS;

void exceptionDispatcher(int exception, uint64_t *registers) {
	switch(exception){
		case ZERO_EXCEPTION_ID:
			zeroDivision();
			break;
		case INVALID_OPCODE_EXCEPTION_ID:
			invalidOpcode();
			break;
		default:
			return;
	}
	saveRegisterInfo();
	getRegistersInfo();
	restartTerminal(registers);
}

void zeroDivision() {
	ncPrint("ERROR DIVIDE BY 0 EXCEPTION\n");
}

void invalidOpcode() {
	ncPrint("ERROR INVALID OPCODE EXCEPTION\n");
}

void saveInitialState(uint64_t IP, uint64_t SP){
	initS.IP = IP;
	initS.SP = SP;
}

void restartTerminal(uint64_t *registers){
	registers[IP_INDEX] = initS.IP;
	registers[SP_INDEX] = initS.SP;
}