/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Interpolation
 * Technique:	Newton's Divided Difference Formula
 * N.B.:	Assumed given tabular values of function f(x),
 * 		introduce a function if it is given. 
 ***************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 10

int main(void)
{
	float x[MAX],y[MAX],Dd[MAX];
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
	printf("\nEnter the values of f(x):\n");
	for(i=0;i<n;i++){
		printf("\nf[x%d]= ",i);
		scanf("%f",&y[i]);
	}
	printf("\nEnter x= ");
	scanf("%f",&u);
	
	/*** compute the coefficients ***/
	for(i=0;i<n;i++)
		Dd[i]=y[i];
	for(j=1;j<n;j++){
		temp0=Dd[j-1];
		for(k=j;k<n;k++){
			temp1=Dd[k];
			Dd[k]=(Dd[k]-temp0)/(x[k]-x[k-j]);
			temp0=temp1;
		}
	}
	
	/*** interpolate using the coefficients ***/
	for(i=n-1;i>=1;i--)
		sum=(sum+Dd[i])*(u-x[i-1]);
	sum+=Dd[0];
	
	/*** display the result ***/
	printf("\nInterpolated value= %f",sum);
	
	printf("\n");

	return 0;
}	
