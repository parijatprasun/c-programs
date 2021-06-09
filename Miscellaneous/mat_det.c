/*****Program for finding the determinant of a matrix using*****/
/*****PIVOTAL CONDENSATION METHOD*****/
/*****Source obtained from 'C.Xavier'*****/

#include <stdio.h>
#include <stdlib.h>

/*#define MAX 10*/

int main(void)
{
	float **a,det,ratio;
	int i,j,k,n;

	printf("\nPlease enter the order of the matrix...");
	scanf("%d",&n);

	/****allocate memory for the matrix(courtesy:Santanu Chattopadhyay)****/
	a=(float**)calloc(n,sizeof(float));
	for(i=1;i<=n;i++)
		a[i]=(float*)calloc(n,sizeof(float));

	/****accept the determinant****/
	printf("\nPlease enter the matrix row-wise\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			scanf("%f",&a[i][j]);
		printf("\n");
	}

	/****start pivotal condensation****/
	for(k=1;k<=n-1;k++){
		for(i=k+1;i<=n;i++){
			ratio=a[i][k]/a[k][k];
			for(j=1;j<=n;j++)
				a[i][j]=a[i][j]-ratio*a[k][j];
		}
		det=1.00;
	}

	/****calculate the determinant by multiplication of the diagonal elements****/
	for(i=1;i<=n;i++)
		det=det*a[i][i];
	printf("\nDeterminant of the given matrix= %f\n\n",det);

	return 0;
}

