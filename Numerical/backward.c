/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Interpolation
 * Technique:	Newton's Backward Formula
 * N.B.:	Assumed given tabular values of function f(x),
 * 		introduce a function if it is given. 
 ***************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 10

int main(void)
{
	float x[MAX],y[MAX],Dy[MAX];
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
	printf("\nEnter the values of y:\n");
	for(i=0;i<n;i++){
		printf("\ny[%d]= ",i);
		scanf("%f",&y[i]);
	}
	printf("\nEnter x= ");
	scanf("%f",&u);

	/*** compute the coefficients ***/
	for(i=0;i<n;i++)
		Dy[n-(1+i)]=y[i];
	for(j=1;j<n;j++){
		temp0=Dy[j-1];
		for(k=j;k<n;k++){
			temp1=Dy[k];
			Dy[k]=(temp0-Dy[k])/(k-(k-j));
			temp0=temp1;
		}
	}
	
	/*** compute h and t ***/
	h=x[1]-x[0];
	printf("\nh=%f",h);
	t=(u-x[n-1])/h;
	printf("\nt=%f",t);
	
	/*** interpolate using the coefficients ***/
	for(i=n-1;i>=1;i--)
		sum=(sum+Dy[i])*(t+(i-1));
	sum+=Dy[0];
	
	/*** display the result ***/
	printf("\nInterpolated value= %f",sum);
		
	printf("\n");

	return 0;
}	
