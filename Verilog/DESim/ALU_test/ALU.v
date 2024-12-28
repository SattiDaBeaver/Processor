// Arithmetic Logic Unit

module ALU(A, B, SELx, OUT);
  input wire [7:0] A;
  input wire [7:0] B; 
  input wire [1:0] SELx;
  output reg [7:0] OUT;
  
  parameter ADD = 2'b00, SUB = 2'b01, MUL = 2'b10, DIV = 2'b11;
  
  always @ (*)
	begin
	  case (SELx)
		ADD: OUT = A + B;
		SUB: OUT = A - B;
		MUL: OUT = A * B;
		DIV: OUT = A / B;
		default: OUT = 2'bxx;
	  endcase
	end
endmodule