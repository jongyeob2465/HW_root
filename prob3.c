double f(double x) { // define function
	return x*x*x*x*x*x*x*x*x*x -1 ;
}

double df(double x) { // differential function	
	return 10*x*x*x*x*x*x*x*x*x ;
}

void Bisection() // Bisection Method
{
	double a, b, c, x, dx ;
	int num ;
	dx = 0.1 ;

	for (x = 0 ; x<1.3 ; x+= 2*dx) { // range 0 to 1.3
		if (f(x-dx)*f(x+dx) <= 0 ) {
			a = x-dx;
			b = x+dx;
			num = 0 ;
			while(fabs(a-b)>1e-12) {
				c = (a+b)/2 ;

				printf("a : %f\t , b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, num : %d\n",a,b,c,f(a),f(b),f(c),num) ;

				if (f(a)*f(c) <= 0) b = c ;
				else a = c ;
				num++ ;

				}
				printf("-----------------------------------------------------------------------------\n");
				printf("a : %f\t , b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, num : %d\n",a,b,c,f(a),f(b),f(c),num) ;

			}
		}
}


void Regula_Falsi() //Regula-Falsi Method
{
	double a, b, c, x, dx ;
	int num ;
	dx = 0.1 ;

	for (x = 0 ; x<1.3 ; x+= 2*dx) { // range 0 to 1.3
		if (f(x-dx)*f(x+dx) <= 0 ) {
			a = x-dx;
			b = x+dx;
			num = 0 ;
			while(1) {
				c = (a*f(b)-b*f(a)) / (f(b) - f(a)) ;
				if (fabs(c-a) < 1e-12 | fabs(b-c) < 1e-12) break ;
				printf("a : %f\t , b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, num : %d\n",a,b,c,f(a),f(b),f(c),num) ;

				if (f(a)*f(c) <= 0) b = c ;
				else a = c ;
				num++ ;
				}
				printf("------------------------------------------------------------------------\n");
				printf("a : %f\t , b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, num : %d\n\n",a,b,c,f(a),f(b),f(c),num) ;

			}
		}
}


void Newton_Raphson() // Newton-Raphson Method
{
	double x2, x1 ;
	int num = 0 ;
	x1 = 0.5 ; // initial x1 value
	while(1) {
		x2 = x1 - f(x1)/df(x1) ;
		if (fabs(x2-x1) <1e-12 ) break ;
		printf(" x1 : %f\t, x2 : %f\t, f(x1) : %f\t, f(x2) : %f\t, num : %d\n",x1,x2,f(x1),f(x2),num);
		x1 = x2 ;
		num++ ;
		}

	printf(" x2 : %f\t, x1 : %f\t, f(x2) : %f\t, f(x1) : %f\t, num : %d\n",x2,x1,f(x2),f(x1),num); 

}


