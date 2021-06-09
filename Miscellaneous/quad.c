/****************************************************************
 * Purpose: Solution of a quadratic equation
 ***************************************************************/

#include <stdio.h>
#include <math.h>

main()
{
    float a, b, c, dis;
    float x1, x2, Re_x, Im_x;
    int i;

    printf("\nPlease enter a,b and c: ");
    scanf("%f %f %f", &a, &b, &c);
    dis = b * b - 4 * a * c;
    if (dis == 0)
	i = 1;
    if (dis > 0)
	i = 2;
    if (dis < 0)
	i = 3;
    switch (i) {
    case 1:
	printf("\nThe roots are equal.");
	x1 = -b / (2 * a);
	x2 = x1;
	printf("\nThe roots are:\n");
	printf("x1= %f\n", x1);
	printf("x2= %f\n", x2);
	break;

    case 2:
	printf("\nThe roots are real and different");
	x1 = (-b + sqrt(dis)) / (2 * a);
	x2 = (-b - sqrt(dis)) / (2 * a);
	printf("\nThe roots are:\n");
	printf("x1= %f\n", x1);
	printf("x2= %f\n", x2);
	break;
    case 3:
	printf("\nThe roots are imaginary");
	dis = (-1) * dis;
	Re_x = -b / (2 * a);
	Im_x = sqrt(dis) / (2 * a);
	printf("\nThe roots are:\n");
	printf("x1= %f+j %f\n", Re_x, Im_x);
	printf("x2= %f-j %f\n", Re_x, Im_x);
	break;
    default:
	printf("\nPlease cooperate.");
	break;
    }

    return 0;
}
