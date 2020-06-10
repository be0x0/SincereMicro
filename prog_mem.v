module prog_mem(
    input rst,
    input [3:0] addr,
    output reg [45:0] line);

    reg [41:0] mem [6:0];

    always @(*) begin
        line <= {addr,mem[addr]};
    end

    always @(*) begin
        if(!rst) begin
            mem[0] = {2'h0,4'h5,12'd1,12'b0,12'b0}; //Add 1
            mem[1] = {2'h0,4'h5,12'd2,12'b0,12'b0}; //Add 2
            mem[2] = {2'h0,4'h5,12'd3,12'b0,12'b0}; //Add 3
            mem[3] = {2'h0,4'h5,12'd4,12'b0,12'b0}; //Add 4
            mem[4] = {2'h0,4'h5,12'd5,12'b0,12'b0}; //Add 5
            mem[5] = {2'h0,4'h5,12'd6,12'b0,12'b0}; //Add 6
            mem[6] = {2'h0,4'h5,12'd7,12'b0,12'b0}; //Add 7
        end
    end
endmodule