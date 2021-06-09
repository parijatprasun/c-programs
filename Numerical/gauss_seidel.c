/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of Linear Equations
 * Technique:	Iterative Method (Gauss-Seidel)
 * N.B.:	It is assumed that the system Ax=b has been
 * 		rearranged so that the coefficient matrix, A,
 * 		is diagonally dominant.
 * 		We begin with an initial approximation
 ***************************************************************/

#include <stdio.h>

#define MAX 10

int main(void)
{
	float a[MAX][MAX],b[MAX];
	float x[MAX],old_x[MAX],diff[MAX];
	float tol,maxdiff;
	int i,j,n,iter;

	/*** accept the necessary data***/
	printf("\nEnter the order of matrix A: ");
	scanf("%d",&n);
	printf("\nEnter the elements of matrix A:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			scanf("%f",&a[i][j]);
		printf("\n");
	}
	printf("\nEnter the matrix b:\n");
	for(i=1;i<=n;i++)
		scanf("%f",&b[i]);
	printf("\nEnter the initial guess:\n");
	for(i=1;i<=n;i++)
		scanf("%f",&x[i]);
	printf("\nEnter the tolerance value: ");
	scanf("%f",&tol);
	
	for(i=1;i<=n;i++){
		b[i]/=a[i][i];
		for(j=1;j<=n;j++){
			if(j==i)
				continue;
			a[i][j]/=a[i][i];
		}
	}
	/*** update x with latest values & print result ***/
	iter=1;
	do{
		printf("\n\nAfter Iteration No. %d\n",iter);
		for(i=1;i<=n;i++){
			old_x[i]=x[i];
			x[i]=b[i];
			for(j=1;j<=n;j++){
				if(j==i)
					continue;
				x[i]-=a[i][j]*x[j];
			}
			printf("\nx[%d]= %f",i,x[i]);
			diff[i]=fabs(x[i]-old_x[i]);
		}
		maxdiff=fabs(diff[1]);
		for(i=2;i<=n;i++){
			if(fabs(diff[i])>maxdiff)
				maxdiff=fabs(diff[i]);
		}
		iter++;
	} while(maxdiff>tol);
	printf("\n");

	return 0;
}	
