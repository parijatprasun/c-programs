
/*   \textbf{P-memory1d:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to allocate the space to store 10 float elements of an array and then free the space.)

\\[5mm]

 {\large Program: memory1d.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1d.c
	------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  int i;
  float *f;

  if((f = (float *) malloc(10 * sizeof(float))) == NULL)
   {
   printf("\n No free space is available.\n");
   return 0;
   }
  else
   printf("\n OK. Free space is available.\n");

  printf("\n Type the float elements of the array:\n");
  for (i = 0; i < 10; i++)
   {
   printf(" %5s f[%d] = ", "", i);
   scanf("%f", &f[i]);
   }

  printf("\n The values and addresses of the float elements:");
  for (i = 0; i < 10; i++)
   printf("\n   f[%d]: value = %.2f; address = %u", i, f[i], &f[i]);

  free(f);

  printf("\n\n");
 }

