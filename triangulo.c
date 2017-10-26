#include <stdio.h>
#include <stdlib.h>

int func(int XA, int XB, int XC, int YA, int YB, int YC, int ABC, int i, int j){
	int AC,BC,AB;
	AC=(XA*j + YA*XC + i*YC - (j*XC + XA*YC + YA*i));
	if(AC<0){
		AC=AC*(-1);
	}
	BC=(i*YB + j*XC + XB*YC - (YB*XC + i*YC + j*XB));
	if(BC<0){
		BC=BC*(-1);
	}
	AB=(XA*YB + YA*i + XB*j - (YB*i + XA*j + YA*XB));
	if(AB<0){
		AB=AB*(-1);
	}
	if((AC+BC+AB)<=ABC){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int XA, XB, XC, YA, YB, YC, ABC, i, j;
	printf("Digite as coordendas de A:\n");
	scanf("%d %d", &XA, &YA);
	printf("Digite as coordendas de B:\n");
	scanf("%d %d", &XB, &YB);
	printf("Digite as coordendas de C:\n");
	scanf("%d %d", &XC, &YC);
	ABC=(XA*YB + YA*XC + XB*YC - (YB*XC + XA*YC + YA*XB));
	if(ABC<0){
		ABC=ABC*(-1);
	}
	system("clear");
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			if(func(XA, XB, XC, YA, YB, YC,ABC, i, j)==1)
				printf("*");
			else
				printf(".");
		}
		puts("");
	}
	return 0;
}
