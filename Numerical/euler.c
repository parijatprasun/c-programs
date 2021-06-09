/**************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of ODE
 * Technique:	Euler's Method
 * N.B:		ODE given in the form dy/dx=f(x,y)
 *************************************************************/

#include <stdio.h>
#include <math.h>

/***** RHS function defined as f(x,y) *****/
float f(float x, float y)
{
	float z;
	
	z=0.05*pow(x,2)-pow(y,2);

	return z;
}

	
int main(void)
{
	float x0,y0,x,y,xf,h;
	float k;
	int i,n;

	/*** accept necessary values ***/
	printf("\nPlease give the values:\n");
	printf("\nx0= ");
	scanf("%f",&x0);
	printf("\ny0= ");
	scanf("%f",&y0);
	printf("\nx= ");
	scanf("%f",&xf);
	printf("\nNumber of steps: ");
	scanf("%d",&n);
	
	/*** compute step size ***/
	h=(xf-x0)/n;
	printf("\nh= %f\n",h);
	/*** initialize the values x,y ***/
	x=x0,y=y0;

	/*** Euler loop ***/
	for(i=1;i<=n;++i){
		k=f(x,y);
		y=y+h*k;
		x=x+h;
		printf("\ny(%g)= %f\n",x,y);
	}

	printf("\n");

	return 0;
}	
