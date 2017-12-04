module teste;
    reg [11:0] px1, py1, px2, py2, px3, py3, px, py;

    wire entrada;

    teste_triangulo A(px1, py1, px2, py2, px3, py3, px, py, entrada);

    initial
        begin
           $dumpvars(0,A);
           #1

           px1 <= 15;
           py1 <= 15;
           px2 <= 35;
           py2 <= 10;
           px3 <= 15;
           py3 <= 30;
           px <= 20;
           py <= 20;

           #1
           px <= 13;
           py <= 15;
           #1
           px <= 10;
           py <= 20;
           #1
           px <= 16;
           py <= 9;
           #1
           px <= 30;
           py <= 10;
           #40
           $finish;
        end
endmodule
