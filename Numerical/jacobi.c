/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Solution of Linear Equations
 * Technique:	Iterative Method (Jacobi)
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
	float new_x[MAX],old_x[MAX],diff[MAX];
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
		scanf("%f",&old_x[i]);
	printf("\nEnter the tolerance value: ");
	scanf("%f",&tol);
	for(i=1;i<=n;i++){
		b[i]/=a[i][i];
		new_x[i]=old_x[i];
		for(j=1;j<=n;j++){
			if(j==i)
				continue;
			a[i][j]/=a[i][i];
		}
	}
	/*** update x with new set of values & print result ***/
	iter=1;
	do{
		for(i=1;i<=n;i++){
			old_x[i]=new_x[i];
			new_x[i]=b[i];
		}
		printf("\n\nAfter iteration no. %d\n",iter);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(j==i)
					continue;
				new_x[i]-=a[i][j]*old_x[j];
			}
			printf("\nx[%d]= %f",i,new_x[i]);
			diff[i]=fabs(new_x[i]-old_x[i]);
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
