/**************************************************************
 * Purpose: Display of a Fibonacci series until golden ratio
 *          between two successive terms is reached
 *************************************************************/

#include<stdio.h>

void fib(long, long);
short isgolden(long, long);

FILE *fp;

int main()
{
	fp=fopen("fibo","w");
	long int a=1,b=1;
	fprintf(fp,"%ld\n%ld\n",a,b);
	fib(1,1);
	fclose(fp);
	return 0;
}

void fib(long a, long b)
{
	long c;
	c=b;
	b=a+b;
	a=c;
	fprintf(fp,"%ld\n",b);
	if(!isgolden(a,b))
		fib(a,b);
	else{
		printf("\nGolden Ratio found :)\n Bailing out\n\n");
		return;
	}
}

short isgolden(long a, long b)
{
	static double G=0;
	double g,diff;
	g=(double)b/(double)a;
	// One way of testing if Golden Ratio reached
	diff=g-G;
	if(diff<0.00001 && diff>-0.00001){
		printf("\nRATIO IS %lf\n",g);
		return 1;
	}else{
		G=g;
		return 0;
	}
	// Another way of testing Golden Ratio
	/*diff=g*g-g-1;
	if(diff<0.00001 && diff>-0.00001)
		return 1;
	else
		return 0;
	*/
}

