module sub_tb();

  reg signed [10:0] num1;
  reg signed [10:0] num2;
  wire signed [10:0] sum;

  sub DOT ( .acc(num1), .arg1(num2), .out(sum));

  initial
  begin
    $display("Beginning simulation.");
    //Negative normal -51-51 = -102
    num1 = -51;
    num2 = 51;
    #20;
    //positive normal 52--53 = 105
    num1=52;
    num2=-53;
    #20;
    //mixed normal -25--27 = 2
    num1=-25;
    num2=-27;
    #20;
    //mixed normal 27-25 = 2
    num1=27;
    num2=25;
    #20;
    //negative overflow -951 - 902 = -999
    num1=-951;
    num2=902;
    #20;
    //positive overflow 900--900=999
    num1 = 900;
    num2 = -900;
    #20;
    $display("Stopping");
    $stop;
  end

  initial begin
    $monitor("num1=%d, num2=%d, sum=%d",num1,num2,sum);
  end

  initial begin
    $dumpfile("sub_tb_dump.vcd");
    $dumpvars(0,DOT);
  end
endmodule
