
/*   \textbf{P-memory1d:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to read the float elements of an array and allocate memory for them using 'malloc()'. Print the values and addresses of the elements of the array at least thrice and observe that the addresses remain unchanged in all 'runs'.)

\\[5mm]

 {\large Program: memory1d.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1d.c
	------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  int i, n;
  float *b;

  printf("\n Type the number of float elements in the array, n = ");
  scanf("%d", &n);

  b = (float *) malloc(n * sizeof(float));

  printf("\n Type the float elements of the array:\n");
  for (i = 0; i < n; i++)
   {
   printf(" %5s b[%d] = ", "", i);
   scanf("%f", &b[i]);
   }

  printf("\n The values and addresses of the float elements:");
  for (i = 0; i < n; i++)
   printf("\n   b[%d]: value = %.2f; address = %u", i, b[i], &b[i]);

  free(b);

  printf("\n\n");
 }

