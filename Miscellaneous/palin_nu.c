#include <stdio.h>

main()
{
	int num,a[10],b[10],temp;
	int i=0,n,p=0,r=0;

	scanf("%d",&num);
	temp=num;
	while(temp/=10)
		i++;
	n=i;
	i=0;
	while(i<=n){
		a[i++]=num%10;
		num/=10;
	}
	i=0;
	while(i<=n){
		b[i]=a[n-i];
		i++;
	}
	i=0;
        while(i<=n){
		if(a[i]!=b[i])
			r=1;
		p+=r;
		++i;
	}
	if(p==0)
		printf("\nYour number is a PALINDROME\n");
	else
		printf("\nNO! Your number is not a palindrome.\n");

	return 0;
}
		
