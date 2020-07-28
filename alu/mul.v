module mul(acc, arg1, out);
  input signed [10:0] acc;
  input signed [10:0] arg1;

  output reg signed [10:0] out;

  wire signed [21:0] tmp;
  
  assign tmp = acc*arg1;
  always @(*) begin
    if(tmp > 999) out <= 999;
    else if(tmp < -999) out <= -999;
    else  out <= tmp;
  end
endmodule
