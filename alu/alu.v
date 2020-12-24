/*`include "add.v"
`include "sub.v"
`include "notop.v"
`include "mul.v"
*/

module alu(
  input wire [3:0] inst,
  input wire [10:0] arg1, arg2, acc,
  output reg [10:0] out);
  
  wire signed [10:0] add_out, sub_out, mul_out, not_out, dgt_out, dst_out;

  add UADD(.arg1(arg1), .acc(acc), .out(add_out));
  sub USUB(.arg1(arg1), .acc(acc), .out(sub_out));
  mul UMUL(.arg1(arg1), .acc(acc), .out(mul_out));
  notop UNOT(.acc(acc), .out(not_out));
  dgt UDGT(.arg1(arg1), .acc(acc), .out(dgt_out));
  dst UDST(.arg1(arg1),.arg2(arg2),.acc(acc),.out(dst_out))

  always @(*) begin
    case(inst)
      5 : out = add_out;
      6 : out = sub_out;
      7 : out = mul_out;
      8 : out = not_out;
      9 : out <= dgt_out;
      10 : out <= dst_out;
      default: out = acc;
    endcase
  end
endmodule
