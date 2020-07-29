tb: MCX.v alu/
	verilator MCX.v -y alu/ --cc --exe --build tb_driver.cpp

.PHONY: clean
clean:
	rm -rf obj_dir