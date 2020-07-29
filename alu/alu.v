/*`include "add.v"
`include "sub.v"
`include "notop.v"
`include "mul.v"
*/

module alu(
  input wire [3:0] inst,
  input wire [10:0] arg1, arg2, acc,
  output reg [10:0] out);
  
  wire signed [10:0] add_out, sub_out, mul_out, not_out;
  //signed reg dgt_out;
  //signed reg dst_out;

  add UADD(.arg1(arg1), .acc(acc), .out(add_out));
  sub USUB(.arg1(arg1), .acc(acc), .out(sub_out));
  mul UMUL(.arg1(arg1), .acc(acc), .out(mul_out));
  notop UNOT(.acc(acc), .out(not_out));
  //dgt UDGT(.arg1(arg1), .acc(acc), .out(dgt_out);
  //dst UDST(.arg1(arg1),.arg2(arg2),.acc(acc),.out(dst_out))

  always @(add_out or sub_out or mul_out or not_out or inst) begin
    case(inst)
      5 : out = add_out;
      6 : out = sub_out;
      7 : out = mul_out;
      8 : out = not_out;
      //10 : acc <= dgt_out;
      //11 : acc <= dst_out;
      default: out = acc;
    endcase
  end
endmodule
