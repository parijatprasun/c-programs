#include <stdio.h>
#include <math.h>

int main(void)
{
	float data[20],x[20];
	float temp,s,ave,med,max_f,mode,var,sdev;
	int freq[20];
	int n,i,j,N;

	/*** accept the data ***/
	printf("\nPlease enter the no. of observations: ");
	scanf("%d",&n);
	printf("\nPlease enter the data:\n");
	for(i=1;i<=n;++i)
		scanf("%f",&data[i]);

	/*** arrange the data in descending order ***/
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(data[i] < data[j]){
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}

	/*** form the frequency distribution of the data ***/
	x[1]=data[1];
	freq[1]=1;
	j=1;
	for(i=2;i<=n;i++){
		if(data[i]==data[i-1]){
			freq[j]++;
			x[j]=data[i];
		}
		else{
			j++;
			freq[j]=1;
			x[j]=data[i];
		}
	}
	n=j;

	/*** display the frequency distribution ***/
	printf("\nFREQUENCY DISTRIBUTION\n");
	printf("\nObservation\tFrequency");
	printf("\n-----------\t---------\n");
	for(i=1;i<=n;i++)
		printf("%11.4f\t%9d\n",x[i],freq[i]);

	/*** if n is not at least 2 stop progress ***/
	if(n<=1){
		puts("n must be at least 2");
		exit(1);
	}

	N=0;
	for(i=1;i<=n;i++)
		N+=freq[i];

	/*** compute mode ***/
	max_f=freq[1];
	mode=x[1];
	for(i=2;i<=n;i++){
		if(freq[i] > max_f){
			max_f=freq[i];
			mode=x[i];
		}
	}

	/*** compute average, variance, standard deviation ***/
	s=0.0;
	for(i=1;i<=n;i++)
		s+=x[i]*freq[i];
	ave=s/N;
	var=0.0;
	for(i=1;i<=n;i++){
		s=(x[i]-ave);
		var+=freq[i]*s*s;
	}
	var/=(N-1);
	sdev=sqrt(var);

	/*** compute median ***/
	if((N%2)==0)
		med=(data[N/2]+data[(N/2)+1])/2;
	else
		med=data[(N+1)/2];

	/*** display the result ***/
	printf("\nAverage= %f",ave);
	printf("\nMedian= %f",med);
	printf("\nMode= %f",mode);
	printf("\nvariance= %f",var);
	printf("\nStandard Deviation= %f",sdev);

	puts(" ");

	return 0;
}

