/***************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Matrix inversion
 * Technique:	Gauss-Jordan elimination 
 ***************************************************************/

#include <stdio.h>

int main(void)
{
	float **a,**b,r;
	int i,j,k,n;

	printf("\nPlease enter the order of the matrix...");
	scanf("%d",&n);

	/**** allocate memory for the matrix A and B ****/
	a=(float **)calloc(n,sizeof(float));
	for(i=0;i<n;i++)
		a[i]=(float *)calloc(n,sizeof(float));
	b=(float **)calloc(n,sizeof(float));
	for(i=0;i<n;i++)
		b[i]=(float *)calloc(n,sizeof(float));
	
	/**** accept the elements of matrix A ****/
	printf("\nPlease enter the matrix A row-wise...\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%f",&a[i][j]);
		printf("\n");
	}
	/**** form matrix B as an identity matrix ****/
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			b[i][j]=0.00;
		b[i][i]=1.00;
	}
	/*** do operations on both A & B to make A an identity matrix ***/
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(i==k)
				continue;
			r=a[i][k]/a[k][k];
			for(j=0;j<n;j++){
				a[i][j]=a[i][j]-r*a[k][j];
				b[i][j]=b[i][j]-r*b[k][j];
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			b[i][j]=b[i][j]/a[i][i];
	}
	
	/**** display the inverse matrix, i.e. B ****/
	printf("\nThe inverse of matrix A is...\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%2.5f",b[i][j]);
			printf("\t");
		}
		printf("\n");
	}

	return 0;
}

