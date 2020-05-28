module add(arg1, acc, out);
  input signed [10:0] arg1;
  input signed [10:0] acc;
  
  output reg signed [11:0] out;
  
  always @(arg1,acc)
  begin
    out <= acc-arg1;
  end
endmodule
