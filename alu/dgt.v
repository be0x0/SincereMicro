module dgt(acc, arg1, out)
  input signed [10:0] acc;
  output wire signed [10:0] out;


  assign out = acc%10;
