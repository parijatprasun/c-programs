/***************************************************************
  * Subject:	Computing Lab
  * Purpose:	See whether a given string is a palindrome or not.
  **************************************************************/

#include <stdio.h>

main()
{
	char a[20],b[20];
	int i,n,p=0,r=0;

	printf("\nPlease enter the string:\n");
	scanf("%s",a);
	printf("\nYour string: %s\n",a);
	
	for(i=0;a[i]!='\0';++i);
	printf("%d\n",i);
	n=i-1;
	for(i=0;i<=n;++i){
		b[i]=a[n-i];
	}
	b[i]='\0';
	i=0;
        while(i<=n){
		if(b[i]!=a[i])
			r=1;
		p+=r;
		++i;
	}
	if(p==0)
		printf("\nYour string is a PALINDROME\n");
	else
		printf("\nNO! Your string is not a palindrome.\n");

	return 0;

}
