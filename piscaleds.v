module piscar(
input CLOCK_50, 
input [3:0] KEY, 
input [9:0] SW,
output [7:0]LEDG,
output [7:0]LEDR
);



reg [27:0] contador = 0;
reg l = 0;
assign LEDG = l;
assign LEDR = SW[0] * SW[1];

always @(posedge CLOCK_50) begin
	contador = contador + 1;
	if(SW[0] == 0 && SW[1] == 0) begin
		if(contador == 50000000) begin
		contador = 0;
		l = ~l;
		end
	end
	if(SW[0] ==0 && SW[1]==1) begin
		if(contador == 90000000)begin
		contador = 0;
		l = ~l; 
		end
	end
	if(SW[0] == 1 && SW[1]==0) begin
		if(contador == 25000000)begin
		contador = 0;
		l = ~l; 
		end
	end
end


endmodule
