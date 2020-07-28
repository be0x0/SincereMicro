module mul_tb();

  reg signed [10:0] num1;
  reg signed [10:0] num2;
  wire signed [10:0] product;

  mul DOT ( .acc(num1), .arg1(num2), .out(product));

  initial
  begin
    $display("Beginning simulation.");
    //normal - 3x7 = 21
    num1 = 3;
    num2 = 7;
    #20;
    //both negative- -5 * -17 = 85
    num1 = -5;
    num2 = -17;
    #20;
    //mixed bag- 421 * -2 = -842
    num1=-2;
    num2=421;
    #20;
    //positive overflow- 136*492 = 999
    num1=136;
    num2=492;
    #20;
    //negative overflow- 844 * -91
    num1=844;
    num2=-91;
    $20;
    $display("Stopping");
    $stop;
  end

  initial
  begin
    $monitor("num1=%d, num2=%d, product=%d",num1,num2,product);
    
  end

initial
 begin
    $dumpfile("mul_tb_dump.vcd");
    $dumpvars(0,DOT);
 end
endmodule
