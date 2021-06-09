/**************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of ODE
 * Technique:	4th order Runge-Kutta Method
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
	float x0,y0,x,y,xf,h;
	float k1,k2,k3,k4,Dy;
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

	/*** Runge-Kutta loop ***/
	for(i=1;i<=n;++i){
		k1=h*f(x,y);
		k2=h*f(x+h/2,y+k1/2);
		k3=h*f(x+h/2,y+k2/2);
		k4=h*f(x+h,y+k3);
		Dy=(k1+2*k2+2*k3+k4)/6;
		y=y+Dy;
		x=x+h;
		printf("\ny(%g)= %f\n",x,y);
	}

	printf("\n");

	return 0;
}	
