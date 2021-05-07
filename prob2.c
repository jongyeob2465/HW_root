#include "rtflsp.c" //include rtflsp.c file

float F(float x) { //define function
	return (x*x*x*x - 6*x*x*x + 7*x*x + 6*x -8) ; 
}

void Regula_Falsi_rtflsp()
{
	double x2, x1 , dx ;
	dx = 0.1 ;
	for (double x = -2 ; x < 6 ; x +=2*dx) {
		if (F(x-dx)*F(x+dx) <= 0. ) {
			x1 = x- dx ;
			x2 = x+ dx ;
			printf("%f\n",rtflsp(F,x1,x2,1e-12)) ;
			}
		}
}
