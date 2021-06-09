/**************************************************************
 * Purpose: Finding nCr from given values of n and r
 *************************************************************/
#include<stdio.h>

int main()
{
	double n,r;
	double nCr=1.00;
	printf("Enter 'n' and 'r' : ");
	scanf("%lf %lf",&n,&r);
	/* Check Data Validity */
	if(n<r || n<=0 || r<=0 || (n!=(int)n) || (r!=(int)r)){
		printf("Invalid input data\n");
		exit(1);
	}
	/* Calculate */
	for(;r>0;n--,r--)
		nCr *= n/r;
	/* Print Result after cutting off decimal part */
	printf("nCr = %.0lf\n",nCr);
	return 0;
}
