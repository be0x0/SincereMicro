module not_tb();

  reg signed [10:0] acc;
  wire signed [10:0] out;

  notop DOT( .acc(acc), .out(out));

  initial
  begin
    $display("Begin");
    acc = 0;
    #1;
    acc = 3;
    #1;
    acc = 999;
    #1;
    acc = -9;
    #1;
    acc = -999;
    #1;
    $stop;
  end

  initial
  begin
    $monitor("acc =%d, out =%d",acc,out);
  end

  initial begin
    $dumpfile("sub_tb_dump.vcd");
    $dumpvars(0,DOT);
  end

endmodule

