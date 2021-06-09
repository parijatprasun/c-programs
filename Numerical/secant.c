/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of Algebraic Equation
 * Technique:	Secant Method 
 * N.B.:	Change defn of f(x) to match reqd function
 * 		If f(x) is discontinuous, the method may fail
 ***************************************************************/

#include <stdio.h>
#include <math.h>

float f(float x);

int main(void)
{
	float x0,x1,x2,tol,temp;
	int iter;

	/*** accept the necessary data ***/
	printf("\nEnter the value of x0: ");
	scanf("%f",&x0);
	printf("\nEnter the value of x1: ");
	scanf("%f",&x1);
	printf("\nEnter the value of tolerance: ");
	scanf("%f",&tol);

	if(fabs(f(x0)) < fabs(f(x1))){
		/*** swap x0 with x1 ***/
		temp=x0;
		x0=x1;
		x1=temp;
	}
	/*** print a heading ***/
	printf("\nIter\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	/*** solve ***/
	iter=1;
	do{
		x2=x1-f(x1)*(x0-x1)/(f(x0)-f(x1));
		printf("%4d\t%f\t%f\t%f\t%f\n",iter,x0,x1,x2,f(x2));
		x0=x1;
		x1=x2;
		iter++;
	} while(fabs(f(x2)) >= tol );

	printf("\n");

	return 0;
}

/*** function defined as f(x) ***/
float f(float x)
{
	float y;
	
	y=x-pow(tan(x-1),2);

	return y;
}
		
		
	
