/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of Algebraic Equation
 * Technique:	Bisection 
 * N.B.:	Change defn of f(x) to match reqd function
 * 		The method may give a false root if f(x) is
 * 		discontinuous on [x1,x2]
 ***************************************************************/

#include <stdio.h>
#include <math.h>

float f(float x);

int main(void)
{
	float x1,x2,x3,tol;
	int iter;

	/*** accept the necessary data ***/
	printf("\nEnter the value of x1: ");
	scanf("%f",&x1);
	printf("\nEnter the value of x2: ");
	scanf("%f",&x2);
	printf("\nEnter the value of tolerance: ");
	scanf("%f",&tol);
	/*** print a heading ***/
	printf("\nIter\tx1\t\tx2\t\tx3\t\tf(x3)\n");
	/*** solve and print after each iteration ***/
	iter=1;
	do{
		if(f(x1)*f(x2) > 0.00){
			printf("\nValues don't bracket a root.\n");
			exit(1);
		}
		x3=(x1+x2)/2;
		printf("%4d\t%f\t%f\t%f\t%f\n",iter,x1,x2,x3,f(x3));
		if(f(x3)*f(x1) < 0.00)
			x2=x3;

		else
			x1=x3;
		iter++;
	} while(fabs(x1-x2) >= 2*tol && f(x3) !=0.00);
	
	printf("\n");

	return 0;
}

/*** function defined as f(x) ***/
float f(float x)
{
	float y;
	
	y=pow(x,2)+x-2;

	return y;
}
	
