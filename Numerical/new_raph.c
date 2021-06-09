/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of Algebraic Equation
 * Technique:	Newton-Raphson Method 
 * N.B.:	Change defn of f(x) to match reqd function
 * 		The method may converge to a root different 
 * 		from the expected one or diverge if the 
 * 		starting value is not close enough to the root
 ***************************************************************/

#include <stdio.h>
#include <math.h>

float f(float x);
float f_dash(float x);

int main(void)
{
	float x0,x1,tol1,tol2;
	int iter;

	/*** accept the necessary data ***/
	printf("\nEnter the value of x0: ");
	scanf("%f",&x0);
	printf("\nEnter the tolerance for x: ");
	scanf("%f",&tol1);
	printf("\nEnter the tolerance for f(x): ");
	scanf("%f",&tol2);

	/*** print a heading ***/
	printf("\nIter\tx0\t\tf(x0)\n");
	
	if(f(x0) != 0.00 && f_dash(x0) != 0.00){
		/*** solve ***/
		iter=1;
		do{
			printf("%4d\t%f\t%f\n",iter,x0,f(x0));
			x1=x0;
			x0=x0-f(x0)/f_dash(x0);
			iter++;
		} while(fabs(x0-x1) >=tol1 || fabs(f(x0)) >= tol2);
	}

	printf("\n");

	return 0;
}

/*** function defined as f(x) ***/
float f(float x)
{
	float y;
	
	y=pow(x,3)+2*pow(x,2)+2.2*x+0.4;

	return y;
}

/*** first derivative of f(x) ***/
float f_dash(float x)
{
	float y;

	y=3*pow(x,2)+4*x+2.2;
		
	return y;
}
	
