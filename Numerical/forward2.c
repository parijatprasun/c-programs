/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Interpolation
 * Technique:	Newton's Forward Formula
 * N.B.:	Assumed given a function f(x), change the
 * 		definition of f(x) to match required function
 * 		or introduce an array if to compute using
 * 		tabular values
 ***************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 10

float f(float x);

int main(void)
{
	float x[MAX],Dy[MAX];
	int i,j,k,n;
	float temp0,temp1;
	float h,t,u,sum=0.00;

	/*** accept necassary data ***/
	printf("\nEnter the number of terms: ");
	scanf("%d",&n);
	printf("\nEnter the values of x:\n");
	for(i=0;i<n;i++){
		printf("\nx[%d]= ",i);
		scanf("%f",&x[i]);
	}
	printf("\nEnter x= ");
	scanf("%f",&u);
	
	/*** compute the coefficients ***/
	for(i=0;i<n;i++)
		Dy[i]=f(x[i]);
	for(j=1;j<n;j++){
		temp0=Dy[j-1];
		for(k=j;k<n;k++){
			temp1=Dy[k];
			Dy[k]=(Dy[k]-temp0)/(k-(k-j));
			temp0=temp1;
		}
	}
		
	/*** compute h and t ***/
	h=x[1]-x[0];
	printf("\nh=%f",h);
	t=(u-x[0])/h;
	printf("\nt=%f",t);
	
	/*** interpolate using the coefficients ***/
	for(i=n-1;i>=1;i--)
		sum=(sum+Dy[i])*(t-(i-1));
	sum+=Dy[0];
	
	/*** display the result ***/
	printf("\nInterpolated value= %f",sum);
	
	printf("\n");

	return 0;
}	

/*** function defined as f(x) ***/
float f(float x)
{
	float y;
	float PI=3.1415927;

	y=sin(x*PI/180);
	
	return y;
}
