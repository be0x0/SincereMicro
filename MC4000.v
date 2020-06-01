//TODO
module MC4000();
    //Conditional[2 bits] Instruction[4 bits] arg1[12 bits] arg2[12 bits] arg3 [12 bits]
    reg [4:0] inst;
    reg clk;
    reg [1

    alu U1(.inst, .arg1, .arg2, .acc, .out(alu_out));