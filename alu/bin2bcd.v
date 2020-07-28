module bin2bcd(input signed [10:0] bin, output reg signed [12:0] bcd);
  always @(bin) begin
    for(i = 0; i < 12; i=i+1)
      bcd[i] <= 0;
    for(i = 0; i < 12; i++) begin
      for(j = 0; j < 3; j++)
        if(bcd[(4*j+3)-:3)] > 4)
          bcd[4*j+3:4*j] <= bcd[4*j+3:4*j] + 3;
      bcd = bcd[];

    end
  end
endmodule