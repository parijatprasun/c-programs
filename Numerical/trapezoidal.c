/**************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Numerical Integration
 * Technique:	Trapezoidal Rule
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
	int n,i;
	
	/*** accept the necessary data ***/
	printf("\nEnter the Starting Point: ");
	scanf("%f",&a);
	printf("\nEnter the End Point: ");
	scanf("%f",&b);
	printf("\nEnter the number of intervals: ");
	scanf("%d",&n);
	/*** compute the step ***/
	h=(b-a)/n;
	/*** integration process ***/
	sum=0.0;
	for(i=1;i<n;i++){
		x=a+h*i;
		sum+=2*f(x);
	}
	sum+=f(a)+f(b);
	ans=sum*h/2;
	/*** display the result ***/
	printf("\nThe Integral Value= %f\n\n",ans);

	return 0;
}
				
/***** function defined as f(x) *****/
float f(float x)
{
	float y;

	y=1/(1+x*x);

	return y;
}

