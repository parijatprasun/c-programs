/******************************************************************
 * Purpose: Finding the GCD of two given numbers
 *****************************************************************/
#include<stdio.h>

int main()
{
	int a,b,temp;
	printf("Enter two integers : ");
	scanf("%d %d",&a,&b);
	if (a<b)
		temp=a, a=b, b=temp;
	for(temp=b;temp>0;temp--)
		if((a%temp==0) && (b%temp==0)){
			printf("G.C.D of the Nos. is : %d\n",temp);
			return 0;
		}
}
