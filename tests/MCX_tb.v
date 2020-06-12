module MCX_tb();
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
    #5000;
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