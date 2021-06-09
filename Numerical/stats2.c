/****************************************************************
 * Subject:	Numerical Methods & Programming
 * Purpose:	Statistical Analysis
 * Metods:	Correlation & Regression
 * N.B.:	Correlation coefficient for given two sets of 
 * 		data, namely 'x's and 'y's, are to find and
 * 		by Regression analysis(method of Least Squares)
 * 		to find the equation of the best fit line.
 ****************************************************************/

#include <stdio.h>
#include <math.h>

/***** function to find the mean *****/
float mean(float *data, int n)
{
	float m,s=0.00;
	int i;
	for(i=1;i<=n;i++)
		s+=data[i];
	m=s/n;

	return m;
}

/***** function to find the standard deviation *****/
float sdev(float *data, int n)
{
	float s,ave,var=0.0,sd;
	int i;

	ave=mean(data,n);
	for(i=1;i<=n;i++){
		s=(data[i]-ave);
		var+=s*s;
	}
	var/=(n-1);
	sd=sqrt(var);

	return sd;
}

int main(void)
{
	FILE *df;
	
	float x[20],y[20];
	float x_bar,y_bar,sigma_x,sigma_y;
	float r=0.0,a,b;
	int n,i,j;

	df=fopen("crdata","r");
	
	/*** accept the data ***/
	printf("\nNo. of observations in each set: ");
	scanf("%d",&n);
	printf("\nReading the values from sets:\n");
	for(i=1;i<=n;++i)
		fscanf("%f %f",&x[i],&y[i]);

	fclose(df);

	/*** if n is not at least 2 stop progress ***/
	if(n<=1){
		puts("n must be at least 2");
		exit(1);
	}

	/*** obtain mean & standard deviation ***/
	x_bar=mean(x,n);
	y_bar=mean(y,n);
	sigma_x=sdev(x,n);
	sigma_y=sdev(y,n);
	
	/*** compute correlation coefficient ***/
	for(i=1;i<=n;i++)
		r +=((x[i]-x_bar)/sigma_x)*((y[i]-y_bar)/sigma_y);
	r/=(n-1);
	
	/*** display the result ***/
	printf("\nCorrelation coefficient= %f",r);
	
	/*** do regression analysis(least squares method) & find the
	 * equation for the best fit line for the given sets of data ***/
	a=r*(sigma_y/sigma_x);
	b=y_bar-a*x_bar;

	printf("\nEquation for the best fit line:\n");
	printf("\t y_cap = %f x %c %f",a, b<0? ' ':'+',b);

	puts(" ");

	return 0;
}

