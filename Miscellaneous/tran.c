#include <stdio.h>
#define	dt	0.00001

float V(float t,float v)
{
    float e;
    if(t<0.00004)
	e=(v/0.00004)*t;
    else
	e=v;
    return e;
}
analyse(int m,int n,float tau)
{
    float i[n+1],I[m+1],R,L,v,t=dt;
    int a,b;
    printf("\nGive the value or voltage in volts.");
    scanf("%f",&v);
    printf("\nGive the value of R in Ohms.");
    scanf("%f",&R);
    printf("\nGive the value of L in Henry.");
    scanf("%f",&L);
    I[0]=0;
    b=1;
    while(b<=m){
	i[0]=I[b-1];
	a=1;
	while(a<=n){
	   i[a]=(V(t,v)*dt-R*i[a-1]*dt+L*i[a-1])/L;
	    a++;
	    t+=dt;
	}
	I[b]=i[a-1];
	b++;
    }
    b=0;
    t=0;
    do{
	printf("%f ",t);
	b++;
	t+=tau;
    }while(b<=m);
    b=0;
    printf("\n");
    do{
	printf("%1.8f ",I[b]);
	b++;
    }while(b<=m);
    
}
main()
{
    double m,n;
    double tau,T;
    printf("\nGive the stop value in second.");
    scanf("%lf",&T);
    printf("\nGive the step value in second.");
    scanf("%lf",&tau);
    printf("\n%lf %lf\n",T,tau);
    m=T/tau;
    n=tau/dt;
    printf("\n%2.8lf %2.8lf\n",m,n);
    analyse(m,n,tau);
}

