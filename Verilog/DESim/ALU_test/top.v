// Copyright (c) 2020 FPGAcademy
// Please see license at https://github.com/fpgacademy/DESim

module top (CLOCK_50, SW, KEY, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, LEDR);

    input CLOCK_50;             // DE-series 50 MHz clock signal
    input wire [9:0] SW;        // DE-series switches
    input wire [3:0] KEY;       // DE-series pushbuttons

    output wire [6:0] HEX0;     // DE-series HEX displays
    output wire [6:0] HEX1;
    output wire [6:0] HEX2;
    output wire [6:0] HEX3;
    output wire [6:0] HEX4;
    output wire [6:0] HEX5;

    output wire [9:0] LEDR;     // DE-series LEDs   

    ALU_test U1 (SW[9:0], KEY[3:0], LEDR[9:0], HEX0, HEX1, HEX2, HEX3, HEX4, HEX5);

endmodule

// Module for Part 1
module ALU_test (SW, KEY, LEDR, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5);
    input wire [9:0] SW;
    input wire [3:0] KEY;

    output wire [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5;
    output wire [9:0] LEDR;

    wire [7:0] A, B, OUT;

    reg_8 R1 (SW[7:0], KEY[3], ~KEY[1], A);
    reg_8 R2 (SW[7:0], KEY[3], ~KEY[0], B);

    ALU A1 (A, B, SW[9:8], OUT);

    hex7seg H1 (B[3:0], HEX0);
    hex7seg H2 (B[7:4], HEX1);
    hex7seg H3 (A[3:0], HEX2);
    hex7seg H4 (A[7:4], HEX3);
    hex7seg H5 (OUT[3:0], HEX4);
    hex7seg H6 (OUT[7:4], HEX5);
endmodule

module reg_8 (D, resetn, clk, Q);
    input wire [7:0] D;
    input wire clk, resetn;
    output reg [7:0] Q;

    always @ (posedge clk or negedge resetn) begin
        if (!resetn)
            Q <= 8'b0;
        else
            Q <= D;
    end
endmodule

module hex7seg (hex, display);
    input [3:0] hex;
    output [6:0] display;

    reg [6:0] display;
    always @ (hex)
        case (hex)
            4'h0: display = 7'b1000000;
            4'h1: display = 7'b1111001;
            4'h2: display = 7'b0100100;
            4'h3: display = 7'b0110000;
            4'h4: display = 7'b0011001;
            4'h5: display = 7'b0010010;
            4'h6: display = 7'b0000010;
            4'h7: display = 7'b1111000;
            4'h8: display = 7'b0000000;
            4'h9: display = 7'b0011000;
            4'hA: display = 7'b0001000;
            4'hB: display = 7'b0000011;
            4'hC: display = 7'b1000110;
            4'hD: display = 7'b0100001;
            4'hE: display = 7'b0000110;
            4'hF: display = 7'b0001110;
        endcase
endmodule





