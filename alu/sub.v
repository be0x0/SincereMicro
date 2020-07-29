module sub(
  input signed [10:0] arg1, acc,
  output reg [10:0] out);

  wire signed [11:0] tmp;

  assign tmp = acc - arg1;

  always @(*) begin //overflow handler
    if(tmp>999) out = 999;
    else if(tmp<-999) out = -999;
    else out = tmp[10:0];
  end
endmodule
