module notop(acc, out);
  input signed [10:0] acc;
  output reg signed [10:0] out;

  always @(acc)
  begin
    if(acc == 0)
      out <= 100;
    else
      out <= 0;
  end
endmodule
