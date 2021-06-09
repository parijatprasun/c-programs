/*****Program for multiplication of two matrices*****/
/*****Parijat Prasun Pal*****/

#include <stdio.h>

#define MAX 10

int main(void)
{
	float a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
	int rowa,cola,colb;
	int i,j,k,y;

/****Accept the order of matrix A****/
	printf("\nMatrix A...");
	printf("\nNumber of Rows? ");
	scanf("%d",&rowa);
	printf("\nNumberof Columns? ");
	scanf("%d",&cola);
/****Accept the order of  matrix B****/	
	printf("\nNumber of Rows must be %d ",cola);
	printf("\nNumberof Columns? ");
	scanf("%d",&colb);
/****Just display for verification****/
	printf("\nMatrix A...(%dx%d)",rowa,cola);
	printf("\nMatrix B...(%dx%d)",cola,colb);
/****Accept the matrix A****/
	printf("\nGive the elements of A row-wise\n");
	for(i=0;i<rowa;i++){
		for(j=0;j<cola;j++)
			scanf("%f",&a[i][j]);
		printf("\n");
	}
/****Accept the matrix B****/
	printf("\nGive the elements of B row-wise\n");
	for(i=0;i<cola;i++){
		for(j=0;j<colb;j++)
			scanf("%f",&b[i][j]);
		printf("\n");
	}
/****Multiply the matrices and results form matrix C****/
	for(i=0;i<rowa;i++){
		for(j=0;j<colb;j++){
			c[i][j]=0.00;
			for(k=0;k<cola;k++){
				y=a[i][k]*b[k][j];
				c[i][j]=c[i][j]+y;
			}
		}
	}
/****Display the product matrix C****/
	printf("\nThe product of A and B ...");
	printf("\nMatrix C...(%dx%d)\n",rowa,colb);
	for(i=0;i<rowa;i++){
		for(j=0;j<colb;j++)
			printf("\t %f",c[i][j]);
		printf("\n");
	}
	printf("\n\n");

	return 0;
}

	
