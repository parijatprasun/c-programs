/*    FFT -Programming  */
/* Development starting on 7.8.98  */
#include <stdio.h>
#include <math.h>
FILE *ftp1;
FILE *ftp2 ;
float  xreal[2048], ximag[2048];
double pi= 3.14159265359;
int nsm= 1024;

 void main()
{
 int i,nu,j;

 double xnsm, xnu, a[2048], ang[2048];
 int fft(int);
  /* read the sampling Data */

  ftp1 = fopen("d12.dat","r");
  ftp2 = fopen("d33.out","wr");
  for (i =1; i<=nsm ; i++)
  {


    fscanf( ftp1," %f  %f " ,&xreal[i],&ximag[i]);
      printf(" %f  %f" , xreal[i], ximag[i]);

    }
    fclose(ftp1);
    xnsm =nsm;
    xnu = log(xnsm)/log(2.0);
    nu =xnu;
    if (nu < (xnu-0.5)) nu = nu +1;
    printf (" %f  %d", xnu, nu);

    /*     call   FFT  subroutine        */
     fft(nu);
      for (j =1; j<=nsm ; j++)
       {
	 if (j ==1)

	     {
	       a[j] = sqrt(( xreal[j]*xreal[j] + ximag[j]*ximag[j])/xnsm);
	       ang[j] =0.0;
	       printf("\n\n a = %f ang = %f \n", a[j], ang[j]);
		fprintf( ftp2," %d  %f,%f\n " ,j,a[j],ang[j]);
	      }
		else
		{
		  a[j] = sqrt(((xreal[j]*xreal[j] + ximag[j]*ximag[j]))*2.0/xnsm);
		  ang[j] =  atan2 ( ximag[j], xreal[j]);
		  ang[j] = ang[j] *( 180./pi);
		  printf(" a = %f ang = %f\n", a[j], ang[j]);
		  fprintf( ftp2," %d  %f %f\n " ,j,a[j],ang[j]);
		}
	}
	 fclose(ftp2);
    }

      int fft(nu)
     {
     int n2,nu1,k,i,l, k1, k1n2,x,y;
     double dnsm,arg,c,s, treal,timag,dnu1,dk,y1,dx;
     int ibitr( int, int);

     n2 = nsm/2;
     nu1 = nu -1;
     k =0;
     for (l =0; l<nu; l++)
     {
	  start :
	 for (i =0; i<n2; i++)
	   {
		dk = k;
	       //	printf("%f  dk =", dk);
		dnu1 =nu1;
		dx =pow( 2.0,dnu1)   ;
		dx = dk/dx;
		x =dx;

	     //		printf("%d x= ",x);
		y = ibitr(x,nu);
	       //	printf("%f y= ",y);
		dnsm =nsm;
		y1 = y;
		arg = 2.*pi*y1/dnsm;
	       //	printf("%f arg = ",arg);
		c = cos(arg);
		s = sin(arg);
		k1 = k +1;
		k1n2 = k1 +n2;
		treal = xreal[k1n2]*c + ximag[k1n2]*s;
		timag = ximag[k1n2]*c - xreal[k1n2]*s;
		xreal[k1n2] = xreal[k1] -treal;
		ximag[k1n2] = ximag[k1] -timag;
		xreal[k1] = xreal[k1] + treal;
		ximag[k1] = ximag[k1] + timag;
		k = k+1;
	   }

		k = k +n2;
       //	printf("%d n2 = " ,n2);
       //	printf("%d k = " ,k);
	if (k<nsm) goto start;
	k =0;
	nu1 = nu1 -1;
	n2 = n2/2;
     }
	   for (k= 1; k<= nsm; k++)
	     {
		i = ibitr(k-1,nu) +1;
		if(i > k)
		{
		treal = xreal[k];
		timag = ximag[k];
		xreal[k] = xreal[i];
		xreal[i] = treal;
		ximag[i] = timag;
		}

	      }
	     // return(0);
     }


     ibitr(j,nu)
     {
     int p,i, j1,j2;
     j1 =j;
     p = 0;
      for (i = 1; i<= nu; i++)
       {
	j2 = j1/2;
	p = p*2 + (j1 - 2*j2);
	j1 = j2 ;
	}
	return(p);
     }


  // Program stop on 13th August 1998