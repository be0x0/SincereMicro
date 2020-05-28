module add(arg1, acc, out);
  input signed [10:0] arg1;
  input signed [10:0] acc;
  
  output reg signed [11:0] out;
  
  wire signed [11:0] tmp;

  assign tmp = arg1 + acc;
  
  always @(tmp)
  begin
    out <= tmp;
  end
endmodule
