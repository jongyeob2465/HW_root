static double R = 0.08314 ; //bar  m^3 / Kg- mol*K
static double a = 1.463 ;//bar  m^6 / (Kg*mol)^2
static double b = 0.0394 ;// m^3 / Kg
static double T = 215 ;// K
static double P = 70 ;// bars

double f(double v) { // define function
	return (P + a/(v*v))*(v-b) - R*T ;
}

void prob5()
{

	double x3, x2, x1 ;
	int num = 0 ;
		x1 = 10 ;
		x2 = 9 ;
		while(fabs(x2-x1) > 1e-12) {
			x3 = (x2*f(x1) - x1*f(x2))/(f(x1) - f(x2)) ;
			x1 = x2 ;
			x2 = x3 ;
			num++ ;
			}	
		printf(" x1 %f\t x2 %f\t x3 %f\t f(x1) %f\t f(x2) %f\t f(x3) %f\t num %d\n",x1,x2,x3,f(x1),f(x2),f(x3),num);

		printf(" ideal gas equation V = RT/P = %f (m^3/kg-mole) \t, nonideal gas V = %f (m^3/kg-mole) \t Difference : %f (m^3/kg-mole) \n",R*T/P,x3,R*T/P - x3) ;
}
