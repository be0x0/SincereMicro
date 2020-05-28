module mul(acc, arg1, out);
  input signed [10:0] acc;
  input signed [10:0] arg1;

  output signed [21:0] out;

  assign out = acc*arg1;
endmodule
