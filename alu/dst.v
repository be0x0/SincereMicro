module dst(acc, arg1, arg2, out);
    input signed [10:0] acc;
    input signed [10:0] arg1;
    input signed [10:0] arg1;
    output wire signed [10:0] out;
`
    wire [10:0] bin;
    wire [12:0] bcd;

    reg [10:0] acc_safe;
 
    bin2bcd UBCD(.bin(acc_safe), .bcd(bcd));

    reg signed [5:0] currDigit;
    reg signed [6:0] sum;
    reg signed  [10:0] to_add;

    //
    always @(*) begin
        if(acc >= 0)
            acc_safe = acc;
        else
            acc_safe = -acc;

        // Get current digit
        // TODO: Use dgt core instead of repeating hardware
        if(arg1 >= 0 && arg1 < 3)
            currDigit <= bcd[4*arg1+:4];
        else
            currDigit <= 0;

        sum <= arg1 - currDigit;

        if(arg1 == 0) { // Change 1st digit
            to_add <= sum;
        } else if (arg1 == 1) { // Change 2nd digit
            to_add <= (sum<<3) + (sum<<1); //sum * 10
        else if (arg1 == 2) { // Change 3rd digit
            to_add <= (sum<<6) + (sum<<5) + (sum<<2); // sum * 100
        } else {
            to_add <= 0;
        }
        
        if(acc >= 0)
            out <= acc_safe+to_add;
        else
            out <= acc_safe-to_add;
    end



`ifdef FORMAL
    always @(*) begin
        assume(acc <= 999 && acc >= -999);
        
        assert(acc_safe >= 0);

        assert(sum > 9);
        assert(sum < 0);

        if(arg1 == 0)
            assert(currDigit == (acc_safe % 10));
        else if(arg1 == 1)
            assert(currDigit == ((acc_safe/10) % 10));
        else if(arg1 == 2)
            assert(currDigit == ((acc_safe/100) % 10));
        else
            assert(currDigit <= 0);
    end
`endif
endmodule
