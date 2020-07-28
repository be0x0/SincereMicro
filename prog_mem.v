module prog_mem(
    input rst,
    input [3:0] addr,
    output reg [45:0] line);

    reg [41:0] mem [6:0];

    always @(*) begin
        line <= {addr,mem[addr]};
    end

    //Program memory goes here. Commented out are previous tests.
    always @(*) begin
        if(!rst) begin
            //Toggle acc every two cycles.
            mem[0] = {2'h0,4'h1,12'd150,12'h801,12'b0}; //Set acc to 150
            mem[1] = {2'h0,4'h0,12'd0,12'b0,12'b0}; //Nop
            mem[2] = {2'h0,4'h8,12'd0,12'b0,12'b0}; //Not
            mem[3] = {2'h0,4'h2,12'd1,12'b0,12'b0}; //Jump to instruction 1 
            /*
            mem[0] = {2'h0,4'h5,12'd11,12'b0,12'b0}; //Add 11
            mem[1] = {2'h0,4'h6,12'd140,12'b0,12'b0}; //subtract 140
            mem[2] = {2'h0,4'h7,12'd3,12'b0,12'b0}; //Multiply by 3
            mem[3] = {2'h0,4'h1,12'd1,12'h801,12'b0}; //move 1 to acc
            mem[4] = {2'h0,4'h7,12'd2,12'b0,12'b0}; //Multiply by two
            mem[5] = {2'h0,4'h2,12'h004,12'b0,12'b0}; //Jump to instruction 4
            mem[6] = {2'h0,4'h5,12'd999,12'b0,12'b0}; //Add 999 */
        end
    end
endmodule