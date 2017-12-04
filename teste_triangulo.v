module teste_triangulo (
    input [11:0] px1, py1, px2, py2, px3, py3, px, py,
    output inside
);
    wire sinal1, sinal2, sinal3;
    assign inside = (sign1 == 1 && sign2 == 1 && sign3 == 1) ? 1:0;

    sinal saida1(px1, py1, px2, py2, px, py, sinal1);
    sinal saida2(px2, py2, px3, py3, px, py, sinal2);
    sinal saida3(px3, py3, px1, py1, px, py, sinal3);

endmodule
