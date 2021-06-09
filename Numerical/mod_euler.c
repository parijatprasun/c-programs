/**************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of ODE
 * Technique:	Modified Euler's Method
 * N.B:		ODE given in the form dy/dx=f(x,y)
 *************************************************************/

#include <stdio.h>
#include <math.h>

/***** RHS function defined as f(x,y) *****/
float f(float x, float y)
{
	float z;
	
	z=x*x+y;

	return z;
}

	
int main(void)
{
	float x0,y0,x,y,xf,h;
	float k1,k2,k;
	int i,n;

	/*** accept necessary values ***/
	printf("\nPlease give the values:\n");
	printf("\nx0= ");
	scanf("%f",&x0);
	printf("\ny0= ");
	scanf("%f",&y0);
	printf("\nValue of x at which y is to be determined: ");
	scanf("%f",&xf);
	printf("\nNumber of steps: ");
	scanf("%d",&n);
	
	/*** compute step size ***/
	h=(xf-x0)/n;
	/*** initialize the values x,y ***/
	x=x0,y=y0;

	/*** modified Euler loop ***/
	for(i=1;i<=n;++i){
		k1=f(x,y);
		k2=f(x+h,y+h*k1);
		k=(k1+k2)/2;
		y=y+h*k;
		x=x+h;
	}

	/*** display result ***/
	printf("y(%g)= %f",x,y);

	printf("\n");

	return 0;
}	
