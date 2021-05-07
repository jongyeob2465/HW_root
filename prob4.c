static double g = 9.81 ; // m/s^2
static double Cd = 0.25 ; 
static double area = 0.7 ; //m^2
static double air_density = 1.293 ; // kg/m^3
// ma = mg - 1/2 air_density * Cd * area * v*v  , v = velocity , a = dv/dt

double v(double m) { // function of velocity at time t = 4 , m = mass(kg)
	return sqrt((2*m*g)/(air_density*area*Cd))*TMath::TanH(4*sqrt((g*air_density*Cd*area)/2*m)) -36 ;
}

void prob4()
{
	double x3, x2, x1 ;
	int num = 0 ;
	x1 = 40 ;
	x2 = 39 ;
	while(fabs(x2-x1) >= 1e-12 ) {
		x3 = (x2*v(x1) - x1*v(x2))/(v(x1) - v(x2)) ;

		printf(" x1 %f\t x2 %f\t x3 %f\t v(x1) %f\t v(x2) %f\t v(x3) %f\t num %d\n",x1,x2,x3,v(x1),v(x2),v(x3),num);

		x1 = x2 ;
		x2 = x3 ;
		num++ ;
		}

	printf(" x1 %f\t x2 %f\t x3 %f\t v(x1) %f\t v(x2) %f\t v(x3) %f\t num %d\n",x1,x2,x3,v(x1),v(x2),v(x3),num);
}
