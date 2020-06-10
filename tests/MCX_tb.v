module MCX_tb();

  reg signed [10:0] arg1;
  reg signed [10:0] arg2;
  reg signed [10:0] arg3;
  reg signed [3:0] inst;
  reg clk;
  reg rst;

  MCX DOT (.clk(clk), .rst(rst));

  initial
  begin
    $display("Resting at initial conditions.");
    clk = 0;
    rst = 0;
    #1;
    rst = 1;
    #10;
    #100;
    $display("Stopping");
    $stop;
  end

  initial begin
    $dumpfile("MCX_tb_dump.vcd");
    $dumpvars(0,DOT);
  end

  always
    #5 clk = !clk;
endmodule