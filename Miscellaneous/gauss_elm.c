/*****Gauss elimination method for solving Linear Algebraic Equation*****/
/*****Source obtained from...*****/
/*****"C Language & Numerical Methods"-->C.Xavier/New Age*****/

#include <stdio.h>

#define MAX 10

int main(void)
{
	float a[MAX][MAX],ratio,x[MAX];
	int i,j,k,n;

	printf("\nPlease enter the order of the matrix...");
	scanf("%d",&n);
	printf("\nPlease enter the coefficients and RHS...\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++)
			scanf("%f",&a[i][j]);
		printf("\n");
	}
	for(k=1;k<=n-1;k++){
		for(i=k+1;i<=n;i++){
			ratio=a[i][k]/a[k][k];
			for(j=1;j<=n+1;j++)
				a[i][j]=a[i][j]-ratio*a[k][j];
		}
	}
	x[n]=a[n][n+1]/a[n][n];
	for(k=n-1;k>=1;k--){
		x[k]=a[k][n+1];
		for(j=k+1;j<=n;j++)
			x[k]=x[k]-a[k][j]*x[j];
		x[k]=x[k]/a[k][k];
	}
	for(i=1;i<=n;i++)
		printf("\n x(%d)=%g\n",i,x[i]);

	return 0;
}

