module MCX(
    input clk, rst);
    
    //Program Counter [4b] Conditional[2 bits] Instruction[4 bits] arg1[12 bits] arg2[12 bits] arg3 [12 bits]
    reg [3:0] PC;
    reg [1:0] cond;
    reg [3:0] inst;
    reg signed [10:0] args [2:0];
    
    //registers
    reg signed [10:0] acc;

    reg [3:0] next_inst;

    wire [45:0] line;

    wire signed [10:0] alu_out;

    parameter acc_addr = 1;

    alu ALU1(.inst(inst), .arg1(args[0]), .arg2(args[1]), .acc(acc), .out(alu_out)); 
    prog_mem MEM(.rst(rst), .addr(next_inst), .line(line));

    //Load next instruction
    always @(posedge clk) begin
        PC <= line[45:42];
        cond <= line[41:40];
        inst <= line[39:36];
        args[0] <= line[35:24];
        args[1] <= line[23:12];
        args[2] <= line[11:0];
    end

    //Queue next instruction to be loaded
    always @(*) begin
            if(inst == 4'h3)
                next_inst <= args[0];
            else if(PC == 6)
                next_inst <= 0;
            else
                next_inst <= PC + 1;
    end

    //Update acc register
    always @(posedge clk) begin
        if(inst != 4'h1) acc <= alu_out;
        else if(args[2] == acc_addr) acc <= args[1];
        else acc <= acc;
    end


    //Reset
    always @(*) begin
        if(!rst) begin
            acc <= 0;
            PC <= 15;
            inst <= 0;
        end
    end
endmodule


