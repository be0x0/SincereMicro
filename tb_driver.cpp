#include <stdlib.h>
#include <iostream>
#include <string>
#include "mcx.cpp"
#include <iomanip>

using namespace std;
using std::setw;

std::string argDecode(int aArg);
char condDecode(int aCond);

//dump_item functions stolen from github.com/tomverbeure/cxxrtl_eval
void dump_all_items(cxxrtl::debug_items &items)
{
    cout << "All items:" << endl;
    for(auto &it : items.table)
        for(auto &part: it.second)
            cout << setw(24) << it.first 
                 << " : type = " << part.type 
                 << " ; width = " << setw(4) << part.width 
                 << " ; depth = " << setw(6) << part.depth 
                 << " ; lsb_at = " << setw(3) << part.lsb_at 
                 << " ; zero_at = " << setw(3) << part.zero_at << endl;
    cout << endl;
}

int dump_int(cxxrtl::debug_items &items, std::string path)
{
    cxxrtl::debug_item item = items.at(path);

    // Number of chunks per value
    const size_t nr_chunks = (item.width + (sizeof(chunk_t) * 8 - 1)) / (sizeof(chunk_t) * 8);


/*    for (size_t index = 0; index < item.depth; index++) {
        if (item.depth > 1)
            cout << "location[" << index << "] : "; 

        for(size_t chunk_nr = 0; chunk_nr < nr_chunks; ++chunk_nr){
            cout << item.curr[nr_chunks * index + chunk_nr];
            cout << (chunk_nr == nr_chunks-1 ? "\n" : ",  ");
        }
    } */
	return item.curr[0];
}


int main(int argc, char **argv) {

	// Create an instance of our module under test
	cxxrtl_design::p_MCX top;
	cxxrtl::debug_items all_debug_items;
	top.debug_info(all_debug_items);
	dump_all_items(all_debug_items);

	const char *instSet[16] = {"nop", "mov", "jmp", "slp", "slx", "add", "sub",
		"mul", "not", "dgt", "dst", "teq", "tgt", "tlt", "tcp", "gen"};

	// Reset
	top.p_clk.set(0U);
    top.p_nrst.set(1U);
    top.step();
    top.p_nrst.set(0U);
	top.step();
	top.p_nrst.set(1U);
	top.step();

	// Tick the clock until we are done
	for(int i = 0; i < 10; i++) {
		top.p_clk.set(1U);
		top.step();
		int tick = i;
		int pc = dump_int(all_debug_items,"PC");
		int cond = dump_int(all_debug_items,"cond");
		int inst = dump_int(all_debug_items,"inst");
		std::string args[3] = {
			argDecode(dump_int(all_debug_items,"args[0]")),
			argDecode(dump_int(all_debug_items,"args[1]")),
			argDecode(dump_int(all_debug_items,"args[2]"))};
		int acc = dump_int(all_debug_items,"acc");

		printf("Tick %d \n", i);
		printf("%d\t%c %s %s %s %s\t", pc, cond, instSet[inst], args[0].c_str(), args[1].c_str(), args[2].c_str());
		printf("\tAcc: %d\n",acc);

		top.p_clk.set(0U);
		top.step();

	} exit(EXIT_SUCCESS);
}

string argDecode(int aArg) {
	std::string dArg;
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
