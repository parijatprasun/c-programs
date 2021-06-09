#include<stdio.h>

int stringcpr( char *a, char *b)
{
	int ret,i,c=1;
	for(i=1;a[i]!=0||b[i]!=0;i++){
		if(a[i]==b[i])
			c++;
	}
	if(i==c)
		ret=1;
	else
		ret=0;
	return (ret);
}

find(int n)
{
	char line[200], word[15];
	int i=1,k=0,j=1,l,c=0;
	struct st{
		char search[15];
	}w[n];
	printf("\nEnter a line. End your line with a space.\n");
	scanf("%[^.].",line);
	printf("\nThe word to search.\n");
	scanf("%[^.].",word);
	while(line[i]!=0){
		j=1;
		while(line[i]!=' '){
			w[k].search[j]=line[i];
			j++;
			i++;
		}
		w[k].search[j]=0;
		i++;
		k++;
	}
	for(k=0;k<n;k++){
		l=stringcpr(w[k].search,word);
		if(l==1)
			c++;
	}

	printf("\nThe word occurs %d time(s).\n",c);
}
		
main()
{
	int n;
	puts("***");
	printf("\nGive the number of words.\n");
	scanf("%d",&n);
	find(n);
}
			

