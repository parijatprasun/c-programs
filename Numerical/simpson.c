/**************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Numerical Integration
 * Technique:	Simpson's 1/3 Rule
 * N.B.:	Assumed given a function f(x), change the
 * 		definition of f(x) to match required function
 * 		or introduce an array if to compute using
 * 		tabular values
 **************************************************************/

#include <stdio.h>
#include <math.h>

float f(float x);

int main(void)
{
	float a,b,h,x,sum,ans;
	int n,i,r;
	
	/*** accept the necessary data ***/
	printf("\nEnter the Starting Point: ");
	scanf("%f",&a);
	printf("\nEnter the End Point: ");
	scanf("%f",&b);
	printf("\nEnter the number of intervals: ");
	scanf("%f",&h);
	n=(b-a)/h;
	/*** check for the necessary condition ***/
	r=n%2;	
	if(r!=0){
		printf("\nNumber of intervals must be even.\n");
		exit(1);
	}
	/*** compute the step ***/
	/*h=(b-a)/n;*/
	/*** integration process ***/
	sum=0.0;
	for(i=1;i<=(n/2);i++){
		x=a-h+2*h*i;
		sum+=4*f(x);
		if(i!=(n/2))
			sum+=2*f(x+h);
	}
	sum+=f(a)+f(b);
	ans=sum*h/3;
	/*** display the result ***/
	printf("\nThe Integral Value= %f\n\n",ans);

	return 0;
}
				
/***** function defined as f(x) *****/
float f(float x)
{
	float y;
	y=sin(x);

	return y;
}

