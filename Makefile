tb: MCX.v alu/
	verilator MCX.v -y alu/ --cc --exe --build tb_driver.cpp --trace

cxxrtl: MCX.v prog_mem.v alu/
	yosys -p "read_verilog MCX.v prog_mem.v alu/*; write_cxxrtl mcx.cpp"

.PHONY: clean
clean:
	rm -rf obj_dir
