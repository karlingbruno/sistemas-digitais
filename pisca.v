module pisca_leds(
	input clk,
	output led
);
reg [9:0]contador=0;
reg l = 0;
assign led = l;
always@(posedge clk)begin
	contador = contador +1;
	if(contador ==0)begin
		l=~l;
	end

end


endmodule

module testbench;
  reg clk=0;
  wire led;
	pisca_leds Leds1(clk,led);
  always #2 clk = ~clk;
  initial begin
    $dumpvars;
    #50000;
    $finish;
  end

endmodule
