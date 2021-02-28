module prog_mem(
    input rst,
    input [3:0] addr,
    output reg [45:0] line);

    reg [41:0] mem [6:0];

    always @(*) begin
        line = {addr,mem[addr[2:0]]};
    end

    //Program memory goes here. Commented out are previous tests.
    always @(*) begin
        if(!rst) begin
            //Toggle acc every two cycles.
mem[0] = {2'h0,4'h1,12'd567,12'd2049,12'd0};
mem[1] = {2'h0,4'h0,12'd0,12'd0,12'd0};
mem[2] = {2'h0,4'h9,12'd1,12'd0,12'd0};
mem[3] = {2'h0,4'h0,12'd0,12'd0,12'd0};
mem[4] = {2'h0,4'h2,12'd0,12'd0,12'd0};

        end
    end
endmodule
