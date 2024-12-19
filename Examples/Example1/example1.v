module example1(SW, LEDR, KEY);

	input wire [9:0] SW;
	input wire [3:0] KEY;
	output wire [9:0] LEDR;

	reg Q0, Q1, Q2;
	wire clk;
	assign clk = ~KEY[0];
	
	always @ (posedge clk) begin
		if (!KEY[1])
			{Q2, Q1, Q0} <= 3'b0;
			
		else begin
			Q0 <= SW[0];
			Q1 <= Q0;
			Q2 <= Q1;
		end
	end
	
	assign LEDR[2:0] = {Q0, Q1, Q2};
	
endmodule