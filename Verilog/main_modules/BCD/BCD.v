// Convert 8-bit binary to BCD
module BCD (IN, OUT);
    input wire [7:0] IN;
    output reg [11:0] OUT;

    reg [3:0] hundreds;
    reg [3:0] tens;
    reg [3:0] ones;
    
    always @(*) begin
        hundreds = IN / 100;
	    tens = (IN % 100) / 10;
        ones = IN % 10;

        OUT = {hundreds, tens, ones};
    end

endmodule