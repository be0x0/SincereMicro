#include <stdlib.h>
#include <iostream>
#include "VMCX.h"
#include "verilated.h"
#include <string>

using namespace std;

string argDecode(int aArg);
char condDecode(int aCond);

int main(int argc, char **argv) {
	// Initialize Verilators variables
	Verilated::commandArgs(argc, argv);

	// Create an instance of our module under test
	VMCX *tb = new VMCX();

	const char *instSet[16] = {"nop", "mov", "jmp", "slp", "slx", "add", "sub",
		"mul", "not", "dgt", "dst", "teq", "tgt", "tlt", "tcp", "gen"};

	// Reset
    tb->clk = 0;
    tb->nrst = 1;
    tb->eval();
    tb->nrst = 0;
	tb->eval();
	tb->nrst = 1;
	tb->eval();

	// Tick the clock until we are done
	for(int i = 0; i < 10 && !Verilated::gotFinish(); i++) {
		tb->clk = 1;
		tb->eval();

		int tick = i;
		int pc = tb->MCX__DOT__PC;
		int cond = tb->MCX__DOT__cond;
		int inst = tb->MCX__DOT__inst;
		string args[3] = {argDecode(tb->MCX__DOT__args[0]),
			argDecode(tb->MCX__DOT__args[1]), argDecode(tb->MCX__DOT__args[2])};
		int acc = tb->MCX__DOT__acc;


		printf("Tick %d \n", i);
		printf("%d\t%c %s %s %s %s\t", pc, cond, instSet[inst], args[0].c_str(), args[1].c_str(), args[2].c_str());
		printf("\tAcc: %d\n",acc);
		tb->clk = 0;
		tb->eval();
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