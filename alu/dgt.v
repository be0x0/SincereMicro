module dgt(acc, arg1, out);
    input signed [10:0] acc;
    input signed [10:0] arg1;
    output wire signed [10:0] out;

    wire [10:0] bin;
    wire [12:0] bcd;

    reg [10:0] acc_safe;
 
    bin2bcd UBCD(.bin(acc_safe), .bcd(bcd));

    always @(*) begin
        if(acc >= 0)
            acc_safe = acc;
        else
            acc_safe = -acc;

        if(arg1 >= 0 && arg1 < 3)
            out <= bcd[4*arg1+:4];
        else
            out <= 999;
    end

`ifdef FORMAL
    always @(*) begin
        assume(acc <= 999 && acc >= -999);
        
        assert(acc_safe >= 0);

        if(arg1 == 0)
            assert(out == (acc_safe % 10));
        else if(arg1 == 1)
            assert(out == ((acc_safe/10) % 10));
        else if(arg1 == 2)
            assert(out == ((acc_safe/100) % 10));
        else
            assert(out <= 999);
    end
`endif
endmodule
