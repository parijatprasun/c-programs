#include <stdio.h>
#include <math.h>
#define pi 3.141592654

FILE *source;

struct cmplx{
	double real,imag;
};

struct cmplx det;
int e,n;

struct ckt{
	char type,type2;
	int pos1,pos2;
	double imp,value,angle;
};

char name[10]="",com;

#define prompt printf("\nLatuSCAn>%s>",name)

struct cmplx addc(struct cmplx z1,struct cmplx z2)
{
	struct cmplx x;
	x.real=z1.real+z2.real;
	x.imag=z1.imag+z2.imag;
	return(x);
}

struct cmplx subc(struct cmplx z1,struct cmplx z2)
{
	struct cmplx x;
	x.real=z1.real-z2.real;
	x.imag=z1.imag-z2.imag;
	return(x);
}

struct cmplx mulc(struct cmplx z1,struct cmplx z2)
{
	struct cmplx x;
	x.real=z1.real*z2.real-z1.imag*z2.imag;
	x.imag=z1.real*z2.imag+z1.imag*z2.real;
	return(x);
}

double absc(struct cmplx z)
{
	double x;
	x=sqrt(pow(z.real,2)+pow(z.imag,2));
	return(x);
}

struct cmplx invc(struct cmplx z)
{
	struct cmplx x;
	x.real=z.real/(pow(absc(z),2));
	x.imag=-z.imag/(pow(absc(z),2));
	return(x);
}

struct cmplx divc(struct cmplx z1,struct cmplx z2)
{
	struct cmplx x;
	x=mulc(z1,invc(z2));
	return(x);
}

double argc(struct cmplx z)
{
	double x;
	x=atan(z.imag/z.real);
	if(z.imag<0&&z.real<0)
		x=x+pi;
	if(z.real<0&&z.imag>=0)
		x=x+pi;
	return(x);
}

struct cmplx determinant(struct cmplx a[n-1][n-1])
{
	int i,j;
	struct cmplx ratio,b[n-2][n-2];
	if(n-1==1)
		return(a[0][0]);
	else{
		for(j=1;j<n-1;j++){
			ratio=divc(a[j][0],a[0][0]);
			for(i=0;i<n-2;i++)
				b[j-1][i]=subc(a[j][i+1],mulc(ratio,a[0][i+1]));
		}
		n--;
		det=mulc(a[0][0],determinant(b));
		return(det);
	}
}

int node()
{
	struct ckt N[e];
	char desire;
	float f;
	int i,j,k=0,point,element,m;
	struct cmplx a[n][e],A[n-1][e],AT[e][n-1],Yb[e][e],Vn,Is[e],Vs[e],Yn[n-1][n-1],Yn1[n-1][e],IV[e],Ib[n-1],num,den,Yback[n-1][n-1],Vb,I;
	for(i=0;i<e;i++){
		fscanf(source,"%s",&N[i].type);
	  	fscanf(source,"%d %d",&N[i].pos1,&N[i].pos2);
		if(N[i].type=='V'||N[i].type=='I'){
			fscanf(source,"%lf",&N[i].value);
			fscanf(source,"%lf",&N[i].angle);
			fscanf(source,"%s",&N[i].type2);
			fscanf(source,"%lf",&N[i].imp);
		}
		else{
			N[i].type2=' ' ;
			N[i].value=0;
			N[i].angle=0;
			fscanf(source,"%lf",&N[i].imp);
		}
	}
	printf("What is written in %s",name);
	for(i=0;i<e;i++){
		printf("\n%c\t%d %d\t%lf\t%lf\t%c\t%lf\n",N[i].type,N[i].pos1,N[i].pos2,N[i].value,N[i].angle,N[i].type2,N[i].imp);
	}
	for(j=0;j<e;j++){
		for(i=0;i<n;i++){
			if(i==(N[j].pos1-1))
				a[i][j].real=1;
			else if(i==(N[j].pos2-1))
				a[i][j].real=-1;
			else
				a[i][j].real=0;
			a[i][j].imag=0;
		}
	}
	for(i=0;i<n;i++){
		if(i!=0){
			for(j=0;j<e;j++)
				A[k][j]=a[i][j];
			k++;
		}
	}
	for(i=0;i<e;i++){
		for(j=0;j<n-1;j++)
			AT[i][j]=A[j][i];
	}
	for(i=0;i<e;i++){
		for(j=0;j<e;j++){
			Yb[i][j].real=0;
			Yb[i][j].imag=0;
		}
	}
	f=50;
	for(i=0;i<e;i++){
		if(N[i].type=='V'||N[i].type=='I'){
			if(N[i].type2=='r'){
				Yb[i][i].real=1/N[i].imp;
				Yb[i][i].imag=0;
			}
			if(N[i].type2=='l'){
				Yb[i][i].real=0;
				Yb[i][i].imag=-1/(2*pi*f*N[i].imp);
			}
			if(N[i].type2=='c'){
				Yb[i][i].real=0;
				Yb[i][i].imag=2*pi*f*N[i].imp;
			}
		}
		else if(N[i].type=='r'){
			Yb[i][i].real=1/N[i].imp;
			Yb[i][i].imag=0;
		}
		else if(N[i].type=='l'){
			Yb[i][i].real=0;
			Yb[i][i].imag=-1/(2*pi*f*N[i].imp);
		}
		else if(N[i].type=='c'){
			Yb[i][i].real=0;
			Yb[i][i].imag=2*pi*f*N[i].imp;
		}
		else{
			prompt;
			printf("There is something wrong.");
		}
	}
	for(i=0;i<e;i++){
		if(N[i].type=='V'){
			Vs[i].real=N[i].value*cos(N[i].angle*pi/180);
			Vs[i].imag=N[i].value*sin(N[i].angle*pi/180);
			Is[i].real=0;
			Is[i].imag=0;
		}
		else if(N[i].type=='I'){
			Is[i].real=N[i].value*cos(N[i].angle*pi/180);
			Is[i].imag=N[i].value*sin(N[i].angle*pi/180);
			Vs[i].real=0;
			Vs[i].imag=0;
		}
		else{
			Is[i].real=0;
			Is[i].imag=0;
			Vs[i].real=0;
			Vs[i].imag=0;
		}


	}
	for(i=0;i<n-1;i++){
		for(j=0;j<e;j++){
			Yn1[i][j].real=0;
			Yn1[i][j].imag=0;
			for(k=0;k<e;k++)
				Yn1[i][j]=addc(Yn1[i][j],mulc(A[i][k],Yb[k][j]));
		}
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			Yn[i][j].real=0;
			Yn[i][j].imag=0;
			for(k=0;k<e;k++)
				Yn[i][j]=addc(Yn[i][j],mulc(Yn1[i][k],AT[k][j]));
		}
	}
	for(i=0;i<e;i++)
		IV[i]=subc(Is[i],mulc(Yb[i][i],Vs[i]));
	for(i=0;i<n-1;i++){
		Ib[i].real=0;
		Ib[i].imag=0;
		for(j=0;j<e;j++)
			Ib[i]=addc(Ib[i],mulc(A[i][j],IV[j]));
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			Yback[i][j].real=Yn[i][j].real;
			Yback[i][j].imag=Yn[i][j].imag;
		}
	}
	prompt;
	scanf("%s",&com);
	if(com=='r'){
		printf("The results:");
		while(feof(source)==0){
			fscanf(source,"%s",&desire);
			if(desire=='v'){
				for(i=0;i<n-1;i++){
					for(j=0;j<n-1;j++){
						Yn[i][j].real=Yback[i][j].real;
						Yn[i][j].imag=Yback[i][j].imag;
					}
				}
				fscanf(source,"%d",&point);
				m=n;
				den=determinant(Yn);
				n=m;
				for(i=0,j=point-2;i<n-1;i++){
					Yn[i][j].real=Ib[i].real;
					Yn[i][j].imag=Ib[i].imag;
				}
				num=determinant(Yn);
				n=m;
				Vn=divc(num,den);
				printf("\nV(%d)=%lf+j%lf\n=%lf/_%lf\n",point,Vn.real,Vn.imag,absc(Vn),argc(Vn)*180/pi);
			}
			else if(desire=='i'){
				fscanf(source,"%d",&element);
				Vb.real=0,Vb.imag=0;
				point=N[element-1].pos2;
				for(k=0;k<2;k++){
					if(point==1){
						Vn.real=0;
						Vn.imag=0;
					}
					else{
						for(i=0;i<n-1;i++){
							for(j=0;j<n-1;j++){
								Yn[i][j].real=Yback[i][j].real;
								Yn[i][j].imag=Yback[i][j].imag;
							}
						}
						m=n;
						den=determinant(Yn);
						n=m;
						for(i=0,j=point-2;i<n-1;i++){
							Yn[i][j].real=Ib[i].real;
							Yn[i][j].imag=Ib[i].imag;
						}
						num=determinant(Yn);
						n=m;
						Vn=divc(num,den);
					}
					point=N[element-1].pos1;
					Vb=subc(Vn,Vb);
				}
				I=mulc(Vb,Yb[element-1][element-1]);
				printf("\nI(%d)=%lf+j%lf\n=%lf/_%lf\n",element,I.real,I.imag,absc(I),argc(I)*180/pi);
			}
		}
	}
	fclose(source);
	return(0);
}

int main(void)
{	char com;
	prompt;
	printf("Include:");
	scanf("%s",name);
	prompt;
	source=fopen(name,"r");
	fscanf(source,"%d %d",&e,&n);
	node();
	prompt;
	scanf("%s",&com);
	if(com!='q')
		main();
	else
		return(0);
}

