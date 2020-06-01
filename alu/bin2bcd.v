module bin2bcd(bin, bcd);
  input signed [10:0] bin;
  output signed [12:0] bcd;

  always @(bin)
  begin
    for(i = 0; i < 12; i++)
      bcd[i]=0;
    bcd[9:0] = bin;
    for(i = 0; i <= 
