module notop(
  input signed [10:0] acc,
  output reg signed [10:0] out);
  
  always @(*)
  begin
    if(acc == 0)
      out = 100;
    else
      out = 0;
  end

`ifdef FORMAL
    always @(*) begin
        assert(out == 100 || out == 0);
    end
`endif
endmodule
