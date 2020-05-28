module add_tb();

  reg signed [10:0] num1;
  reg signed [10:0] num2;
  wire signed [11:0] sum;

  add U1 ( .acc(num1), .arg1(num2), .out(sum));

  initial
  begin
    $display("Beginning simulation.");
    num1 = 900;
    num2 = 900;
    #20;
    num1 = -50;
    num2 = -50;
    #20;
    num1=50;
    num2=50;
    #20;
    num1=-25;
    num2=27;
    #20;
    num1=-27;
    num2=25;
    #20;
    num1=-900;
    num2=-105;
    #20;
    num1=900;
    num2=105;
    #20;
$display("Stopping");
    $stop;
  end

  initial
  begin
    $monitor("num1=%d, num2=%d, sum=%d",num1,num2,sum);
  end
endmodule
