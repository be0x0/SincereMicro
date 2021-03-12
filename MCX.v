module MCX(
    input clk, nrst,
    inout [6:0] p0, p1);
    
    //Program Counter [4b] Conditional[2 bits] Instruction[4 bits] arg1[12 bits] arg2[12 bits] arg3 [12 bits]
    reg [3:0] PC;
    reg [1:0] cond;
    reg [3:0] inst;
    reg signed [11:0] args [2:0];
    reg signed [10:0] numArgs [2:0];
    // Compare flags
    reg enPlus;
    reg enMinus;

    // Registers
    reg signed [10:0] acc;
    reg [3:0] next_inst;
    wire [45:0] line;
    wire signed [10:0] alu_out;
    reg signed [6:0] p0r;
    reg signed [6:0] p0w;
    reg signed [6:0] p1r;
    reg signed [6:0] p1w;

    // Ports
    assign p0 = p0oe ? p0w : 7'bZ;
    assign p1 = p1oe ? p1w : 7'bZ;

    // Register Addresses
    parameter null_addr = 12'h800;
    parameter acc_addr = 12'h801;
    parameter dat_addr = 12'h802;
    parameter p0_addr = 12'h803;
    parameter p1_addr = 12'h804;
    parameter x0_addr = 12'h805;
    parameter x1_addr = 12'h806;
    parameter x2_addr = 12'h807;
    parameter x3_addr = 12'h808;


    alu ALU1(.inst(inst), .arg1(numArgs[0]), .arg2(numArgs[1]), .acc(acc), .out(alu_out)); 
    prog_mem MEM(.rst(nrst), .addr(next_inst), .line(line));

    // Update register args with numeric values
    reg i;
    always @(*) begin
        for(i=0; i<2; i=i+1) begin
            case(args[i])
                null_addr: numArgs[i] = 0;
                acc_addr: numArgs[i] = acc;
                dat_addr: numArgs[i] = dat;
                p0_addr: numArgs[i] = p0r;
                p1_addr: numArgs[i] = p1r;
                default: numArgs[i] = args[i][10:0];
            endcase
        end
    end

    // Load next instruction
    always @(posedge clk) begin
        if(!nrst) begin
            PC <= 4'd15;
            cond <= 2'b0;
            inst <= 4'b0;
            args[0] <= 12'd0;
            args[1] <= 12'd0;
            args[2] <= 12'd0;
        end
        else begin
            PC <= line[45:42];
            cond <= line[41:40];
            inst <= line[39:36];
            args[0] <= line[35:24];
            args[1] <= line[23:12];
            args[2] <= line[11:0];
        end
    end

    // Queue next instruction to be loaded
    always @(*) begin
            if(inst == 4'h2)    // Jump
                next_inst = args[0][3:0];
            else if(PC == 6)
                next_inst = 0;
            else
                next_inst = PC + 1;
    end

    // Update acc register
    always @(posedge clk) begin
        if(!nrst) begin
            acc <= 0;
        end
        else begin
            if(inst != 4'h1) acc <= alu_out; // everything except mov instruction handled by alu
            else if(args[1] == acc_addr) acc <= numArgs[0]; // mov instruction
            else acc <= acc;
        end
    end

    //update p0
    always @(posedge clk) begin
        if(!nrst) begin
            p0oe <= 0;
            p0r <= 0;
            p0w <= 0;
        end
        else begin
            // mov instruction
            if(args[0] == p0_addr) // Something's trying to read
                p0oe <= 0;
            else if(args[1] == p0_addr)  begin // Maybe mov, maybe not
                if(inst == 4'h1)
                    p0oe <= 1;  // Attempted write
                else
                    p0oe <= 0;  //Just another read
            end
            else
                p0oe <= p0oe;
        end
    end

    // Update CMP flags
    always @(posedge clk) begin
        if(!nrst) begin
            enPlus <= 1;
            enMinus <= 1;
        end
        else begin
            // teq
            if(inst == 4'hB) begin
                if(numArgs[0] == numAargs[1]) begin
                    enPlus <= 1;
                    enMinus <= 0;
                end
                else begin
                    enPlus <= 0;
                    enMinus <= 0;
                end
            end
            // tgt
            else if(inst == 4'hC) begin
            end
            // tlt
            else if(inst == 4'hD) begin
            end
            // tcp
            else if(inst == 4'hE) begin

            end
        end
    end
endmodule
