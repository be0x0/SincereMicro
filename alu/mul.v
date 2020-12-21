module mul(acc, arg1, out);
    input signed [10:0] acc;
    input signed [10:0] arg1;

    output reg signed [10:0] out;

    wire signed [21:0] tmp;
  
    assign tmp = acc * arg1;

    always @(*) begin
        if(tmp > 999) out = 999;
        else if(tmp < -999) out = -999;
        else  out = tmp[10:0];
    end

`ifdef FORMAL
    always @(*) begin
        assert(out <= 999);
        assert(out >= -999);

        if(acc * arg1 > 999)
            assert(out == 999);
        else if(acc * arg1 < -999)
            assert(out == -999);
        else
            assert(out == acc * arg1);
        end
`endif
endmodule
