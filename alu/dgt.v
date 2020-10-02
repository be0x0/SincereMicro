module dgt(acc, arg1, out);
  input signed [10:0] acc;
  input signed [10:0] arg1;
  output wire signed [10:0] out;

  wire bcd;
  wire bin;
 
  bin2bcd UBCD(.bin(acc), .bcd(bcd));

  always @(*) begin
    if(arg1 > 0 && arg1 < 3)
      out <= bcd[4*arg1+:4];
    else
      out <= 999;
  end
endmodule