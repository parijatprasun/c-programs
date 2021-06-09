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
	
	z=1+pow(y,2);

	return z;
}

	
int main(void)
{
	float x[10],y[10];
	float h,n,u;
	int i=0;

	/*** accept necessary values ***/
	printf("\nPlease give the values:\n");
	printf("\nx0= ");
	scanf("%f",&x[0]);
	printf("\ny0= ");
	scanf("%f",&y[0]);
	printf("\nValue of x at which y is to be determined: ");
	scanf("%f",&u);
	printf("\nStep size: ");
	scanf("%f",&h);
	
	/*** compute step size ***/
	n=(u-x[0])/h;
	printf("\nn= %f\n",n);
	/*** initialize the values x,y ***/
	
	/*** modified Euler loop ***/
	for(i=1;i<=n;++i){
		x[i]=x[i-1]+h;
		y[i]=y[i-1]+h*f(x[i-1],y[i-1]);
		printf("\ny(%g)= %f\n",x[i],y[i]);
	}

	printf("\n");

	return 0;
}	
