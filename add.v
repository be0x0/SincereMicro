module add(arg1, acc, out)
  input [9:0] arg1;
  input [8:0] acc;
  output [8:0] out;
  out = arg1 + acc;
endmodule;
