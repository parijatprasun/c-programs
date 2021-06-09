/**************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Numerical Integration
 * Technique:	Weddle's Rule
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
	int coef[7],i,j;
	int n;

	/*** assign the coefficients ***/
	coef[1]=5,coef[2]=1;
	coef[3]=6,coef[4]=1;
	coef[5]=5,coef[6]=2;
	/*** accept the necessary data ***/
	printf("\nEnter the Starting Point: ");
	scanf("%f",&a);
	printf("\nEnter the End Point: ");
	scanf("%f",&b);
	printf("\nEnter the number of intervals: ");
	scanf("%d",&n);
	/*** check for the necessary condition ***/
	if(n<6){
		printf("\nAt least 7 consecutive values are reqd.\n");
		exit(1);
	}
	/*** compute the step ***/
	h=(b-a)/n;
	/*** integration process ***/
	sum=0.0;
	i=1,j=1;
	while(i<n){
		x=a+h*i;
		sum+=coef[j]*f(x);
		i++;
		j++;
		if(j>6)
			j=1;
	}
	sum+=f(a)+f(b);
	ans=sum*3*h/10;
	/*** display the result ***/
	printf("\nThe Integral Value= %f\n\n",ans);

	return 0;
}
				
/***** function defined as f(x) *****/
float f(float x)
{
	float y;
	y=1/(1+x);

	return y;
}
