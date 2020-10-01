#include <stdlib.h>
#include <iostream>
#include <string>
#include <mcx.cpp>

string argDecode(int aArg);
char condDecode(int aCond);

int main(int argc, char **argv) {

	// Create an instance of our module under test
	cxxrtl_design::p_VMCX top;

	const char *instSet[16] = {"nop", "mov", "jmp", "slp", "slx", "add", "sub",
		"mul", "not", "dgt", "dst", "teq", "tgt", "tlt", "tcp", "gen"};

	// Reset
	top.p_clk.set(0);
    top.nrst.set(1);
    top.step();
    top.nrst.set(0);
	top.step();
	top.nrst.set(1);
	top.step();

	// Tick the clock until we are done
	for(int i = 0; i < 10 && !Verilated::gotFinish(); i++) {
		top.clk.set(1);
		top.step();

		int tick = i;
		int pc = top.p_PC;
		int cond = top.p_cond;
		int inst = top.p_inst;
		string args[3] = {argDecode(top.p_args[0]),
			argDecode(top.p_args[1]), argDecode(top.p_args[2])};
		int acc = top.MCX__DOT__acc;

		printf("Tick %d \n", i);
		printf("%d\t%c %s %s %s %s\t", pc, cond, instSet[inst], args[0].c_str(), args[1].c_str(), args[2].c_str());
		printf("\tAcc: %d\n",acc);

		top.clk = 0;
		top.step();

	} exit(EXIT_SUCCESS);
}

string argDecode(int aArg) {
	string dArg;
	const char *regList[9] = { "null", "acc", "dat", "p0", "p1", "x0", "x1", "x2", "x3"};
	if(aArg >= 0x800) {
		aArg = aArg - 0x800;
		dArg = regList[aArg];
	} else {
		dArg = to_string(aArg);
	}
	return dArg;
}

char condDecode(int aCond) {
	switch(aCond) {
		case 0:
			return ' ';
		case 1:
			return '-';
		case 2:
			return '+';
		case 3:
			return '@';
	}
	return '!';
}
