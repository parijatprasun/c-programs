/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of Algebraic Equation
 * Technique:	Regula Falsi( False Position) 
 * N.B.:	Change defn of f(x) to match reqd function
 * 		The method may fail if f(x) is discontinuous
 * 		on the interval
 ***************************************************************/

#include <stdio.h>
#include <math.h>

float f(float x);

int main(void)
{
	float x0,x1,x2,tol;
	int iter;

	/*** accept the necessary data ***/
	printf("\nEnter the value of x0: ");
	scanf("%f",&x0);
	printf("\nEnter the value of x1: ");
	scanf("%f",&x1);
	printf("\nEnter the value of tolerance: ");
	scanf("%f",&tol);
	/*** print a heading ***/
	printf("\nIter\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	/*** solve and print after each iteration ***/
	iter=1;
	do{
		x2=x1-f(x1)*(x0-x1)/(f(x0)-f(x1));
		printf("%4d\t%f\t%f\t%f\t%f\n",iter,x0,x1,x2,f(x2));
		if(f(x2)*f(x0) < 0.00)
			x1=x2;
		else
			x0=x2;
		iter++;
	} while(fabs(f(x2)) >= tol && fabs(f(x2))>= tol) ;
	
	printf("\n");

	return 0;
}

/*** function defined as f(x) ***/
float f(float x)
{
	float y;
	
	y=pow(x,3)-3*x-5;

	return y;
}
		
		
	
