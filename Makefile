tb: cxxrtl cxxrtl_compile
    
cxxrtl: MCX.v prog_mem.v alu/
	yosys -p "read_verilog MCX.v prog_mem.v alu/*; write_cxxrtl mcx.cpp"

cxxrtl_compile:
	clang++ -g -I `yosys-config --datdir`/include tb_driver.cpp -o tb -ferror-limit=3 -Wno-everything

tb_verilator: MCX.v alu/
	verilator MCX.v -y alu/ --cc --exe --build tb_driver.cpp --trace

.PHONY: clean
clean:
	rm -rf obj_dir
