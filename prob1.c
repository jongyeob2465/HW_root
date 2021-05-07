double f(double x) {
	return (x*x*x*x - 6*x*x*x + 7*x*x + 6*x - 8) ;
}

double df(double x) {
	return (4*x*x*x - 18*x*x + 14*x + 6 ) ;
}

void Bisection() // Bisection method
{
	double a, b, c, x, dx ;
	int num;
	dx = 0.1 ;

	for (double x = -2 ; x < 6 ; x += 2*dx) {
		if (f(x-dx)*f(x+dx) <= 0.) {
			a = x-dx ;
			b = x+dx ;
			num = 0 ;
			while (fabs(b-a) >= 1e-12) {
				c = (a+b)/2. ;
				printf(" a : %f\t, b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, repeat number : %d\n ",a,b,c,f(a),f(b),f(c),num) ;
				if (f(a)*f(c) <= 0) b = c ;
				else a = c ;
				num++ ;
				}
			printf("-------------------------------------------------------\n");
			printf(" a : %f\t, b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, repeat number : %d\n\n ",a,b,c,f(a),f(b),f(c),num) ;
		}
	}
}

void Regula_Falsi() // Regula Falsi method
{
	double a, b, c, x, dx ;
	int num ;
	dx = 0.1;
	
        for (double x = -2 ; x < 6 ; x += 2*dx) {
                if (f(x-dx)*f(x+dx) <= 0.) {
                        a = x-dx ;
                        b = x+dx ;
                        num = 0 ;

			while(1) {
				c = (a*f(b) - b*f(a))/(f(b)-f(a)) ;
				if (fabs(a-c)< 1e-12  | fabs(b-c)< 1e-12) break ;
				printf(" a : %f\t, b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, repeat number : %d\n ",a,b,c,f(a),f(b),f(c),num) ;

				if (f(c)*f(b) <= 0 ) a = c ;
				else b = c ;
				num++ ;			
			
				}
			printf("-------------------------------------------------------\n");
			printf(" a : %f\t, b : %f\t, c : %f\t, f(a) : %f\t, f(b) : %f\t, f(c) : %f\t, repeat number : %d\n\n ",a,b,c,f(a),f(b),f(c),num) ;
		}
	}
}

void Newton_Raphson() // Newton Raphson method
{
	double x2, x1, dx ;
	int num ;
	dx = 0.1 ;

        for (double x = -2 ; x < 6 ; x += 2*dx) {
                if (f(x-dx)*f(x+dx) <= 0.) {
                        x1 = x+dx ;
                        num = 0 ;

			while(1) {
                        	if (f(x1) != 0)	x2 = x1 - f(x1)/df(x1) ;
				if (fabs(x2-x1) < 1e-12) break ;
              			printf("x1 : %f\t, x2 : %f\t, f(x1) : %f\t, f(x2) : %f\t, repeat number : %d\n",x1,x2,f(x1),f(x2),num);
				x1 = x2 ;
                        	num++ ;
				}
			printf("----------------------------------------------------------------------------------\n");
              		printf("x1 : %f\t, x2 : %f\t, f(x1) : %f\t, f(x2) : %f\t, repeat number : %d\n\n",x1,x2,f(x1),f(x2),num);
		}
}
}

void Secant() // Secant method
{
        double x3, x2, x1, dx ;
        int num ;
        dx = 0.1 ;

        for (double x = -2 ; x < 6 ; x += 2*dx) {
                if (f(x-dx)*f(x+dx) <= 0.) {
                        x1 = x+dx ;
			x2 = x-dx ;
                        num = 0 ;

                        while(fabs(x2-x1) > 1e-12) {
                        	x3 = (x2*f(x1) - x1*f(x2))/(f(x1) - f(x2)) ;
                        	printf("x1 : %f\t, x2 : %f\t, x3 : %f\t, f(x1) : %f\t, f(x2) : %f\t, f(x3) : %f\t, repeat number : %d\n",x1,x2,x3,f(x1),f(x2),f(x3),num);
                        	x1 = x2 ;
				x2 = x3 ;
                        	num++ ;
                        	}
			printf("----------------------------------------------\n");
                        printf("x1 : %f\t, x2 : %f\t, x3 : %f\t, f(x1) : %f\t, f(x2) : %f\t, f(x3) : %f\t, repeat number : %d\n\n",x1,x2,x3,f(x1),f(x2),f(x3),num);
                }
}
}
