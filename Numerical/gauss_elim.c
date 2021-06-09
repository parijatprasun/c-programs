/**********************************************************
 * Subject:	Numerical Methods and Programming
 * Purpose:	Solution of Linear Equations
 * Technique:	Gaussian Elimination Method
 *********************************************************/

#include <stdio.h>

#define MAX 10

int main(void)
{
	float a[MAX][MAX],ratio,x[MAX];
	int i,j,k,n;

	/*** accept the necessary data ***/
	printf("\nPlease enter the order of the matrix...");
	scanf("%d",&n);
	printf("\nPlease enter the coefficients and RHS...\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++)
			scanf("%f",&a[i][j]);
		printf("\n");
	}
	/*** reduce the coefficient & RHS matrices ***/
	for(k=1;k<=n-1;k++){
		for(i=k+1;i<=n;i++){
			ratio=a[i][k]/a[k][k];
			for(j=1;j<=n+1;j++)
				a[i][j]=a[i][j]-ratio*a[k][j];
		}
	}
	/*** back-substitution ***/
	x[n]=a[n][n+1]/a[n][n];
	for(k=n-1;k>=1;k--){
		x[k]=a[k][n+1];
		for(j=k+1;j<=n;j++)
			x[k]=x[k]-a[k][j]*x[j];
		x[k]=x[k]/a[k][k];
	}
	/*** display the result ***/
	for(i=1;i<=n;i++)
		printf("\n x(%d)=%g\n",i,x[i]);

	return 0;
}

