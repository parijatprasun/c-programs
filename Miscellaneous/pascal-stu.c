#include <stdio.h>

int main(void)
{
    int b, p, q, r, x;
    b = 1;
    q = 0;
    printf("\nRows= ");
    scanf("%d", &p);
    printf("%d\n", p);

    while (q < p) {
	for (r = 60 - 4 * q; r > 0; --r)
	    printf(" ");
	for (x = 0; x <= q; ++x) {
	    if ((x == 0) || (q == 0))
		b = 1;
	    else
		b = (b * (q - x + 1)) / x;
	    printf("%4d", b);
	}
	printf("\n");
	++q;
    }

    return 0;
}
