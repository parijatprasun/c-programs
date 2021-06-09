/****************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Soluton of ODE
 * Technique:	Milne's Predictor-Corrector Method
 * N.B.:	ODE of the form dy/dx=f(x,y)
 * 		Supposed 4 equispaced starting values known.
 ****************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 10

float f(float x,float y);

int main(void)
{
	float x[MAX],y[MAX];
	float y_p,y_c;
	float u,h,n,tol;
	int i;

	/*** accept the necessary data ***/
	printf("\nx(0)= ");
	scanf("%f",&x[0]);
	printf("\ny(%g)= ",x[0]);
	scanf("%f",&y[0]);
	printf("\nh= ");
	scanf("%f",&h);
	printf("\nx= ");
	scanf("%f",&u);
	printf("\ntolerance= ");
	scanf("%f",&tol);

	n=(u-x[0])/h;

	/*** obtain 1st 3 values ***/
	for(i=0;i<=2;i++){
		x[i+1]=x[i]+h;
		printf("\ny(%g)= ",x[i+1]);
		scanf("%f",&y[i+1]);
	}

	/*** use predictor & corrector formulae ***/
	for(i=3;i<=n-1;i++){
		x[i+1]=x[i]+h;
		printf("\nf(%d)= %f",i-2,f(x[i-2],y[i-2]));
		printf("\nf(%d)= %f",i-1,f(x[i-1],y[i-1]));
		printf("\nf(%d)= %f",i,f(x[i],y[i]));
		y_p=y[i-3]+4*(h/3)*(2*f(x[i-2],y[i-2])-f(x[i-1],y[i-1])+2*f(x[i],y[i]));
		printf("\ny[%d]_p= %f",i+1,y_p);
		printf("\nf(%d)= %f",i+1,f(x[i+1],y_p));
		
		y_c=y[i-1]+(h/3)*(f(x[i-1],y[i-1])+4*f(x[i],y[i])+f(x[i+1],y_p));
		printf("\ny[%d]_c= %f",i+1,y_c);
		while(fabs(y_p-y_c)>tol){
			y_p=y_c;
			printf("\ny[%d]_p= %f",i+1,y_p);
			printf("\nf(%d)= %f",i+1,f(x[i+1],y_p));
			
			y_c=y[i-1]+(h/3)*(f(x[i-1],y[i-1])+4*f(x[i],y[i])+f(x[i+1],y_p));
			printf("\ny[%d]_c= %f",i+1,y_c);
		}
		y[i+1]=y_c;
		printf("\n%f\t%f",x[i+1],y[i+1]);
	}
	puts(" ");

	return 0;
}

/***** given RHS defined by f(x,y) *****/
float f(float x,float y)
{
	float z;

	z=(1+x*x)*y;

	return z;
}
			
		
