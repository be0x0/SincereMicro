#include <stdlib.h>
#include "VMCX.h"
#include "verilated.h"


int main(int argc, char **argv) {
	// Initialize Verilators variables
	Verilated::commandArgs(argc, argv);

	// Create an instance of our module under test
	VMCX *tb = new VMCX();

    tb->clk = 0;
    tb->rst = 0;
    tb->eval();
    tb->rst = 1;

	// Tick the clock until we are done
	while(!Verilated::gotFinish()) {
		tb->clk = 1;
		tb->eval();
		printf("yeet");
		tb->clk = 0;
		tb->eval();
	} exit(EXIT_SUCCESS);
}