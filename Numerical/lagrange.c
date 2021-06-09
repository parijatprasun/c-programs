/*************************************************************
 * Subject:	Numerical Methods and Programming
 * Purpose:	Interpolation
 * Technique: 	Lagrange
 * ***********************************************************/

#include <stdio.h>

#define MAX 10

int main(void)
{
	int j,i,n;
	float z,p,sum;
	float x[MAX],y[MAX];

	/*** accept the necessary data ***/
	printf("\nPlease enter N: ");
	scanf("%d",&n);
	printf("\nPlease enter the points x[j]:\n");
	for(i=0;i<n;i++)
		scanf("%f",&x[i]);
	printf("\nPlease enter the values y[j]:\n");
	for(i=0;i<n;i++)
		scanf("%f",&y[i]);
	printf("\nEnter the point x: ");
	scanf("%f",&z);

	/*** Interpolation process ***/
	sum=0.0;
	for(j=0;j<n;j++){
		p=1.0;
		for(i=0;i<n;i++){
			if(i != j)
				p *= (z-x[i])/(x[j]-x[i]);
		}
		sum += p*y[j];
	}

	/*** display the interpolated value ***/	
	printf("\nThe value at x=%f is %f\n",z,sum);

	return 0;
}
