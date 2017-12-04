module sinal (
    input [11:0] px1, py1, px2, py2, px, py,
    output sinal
);

    wire signed [11:0] sub1, sub2, sub3, sub4;
    wire signed [22:0] mult1, mult2, sub5;

    assign sub1 = px - py2;
    assign sub2 = py1 - py2;
    assign sub3 = py1 - px2;
    assign sub4 = py - py2;
    assign mult1 = sub1 * sub2;
    assign mult2 = sub3 * sub4;
    assign Sub5 = mult1 - mult2;
    assign sinal = sub5 >= 0 ? 1 : 0;

endmodule
