
/*   \textbf{P-memory1c3:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to allocate memory to store 30 integer elements of an array.)

\\[5mm]

 {\large Program: memory1c3.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1c3.c
	-------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  int i;
  int *a;

  a = (int *) malloc(30 * sizeof(int));

  printf("\n Type the integer elements of the array:\n");
  for (i = 0; i < 30; i++)
   {
   printf(" %5s a[%d] = ", "", i);
   scanf("%d", &a[i]);
   }

  printf("\n The values and addresses of the integer elements:");
  for (i = 0; i < 30; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

//  free(a);

  printf("\n\n");
 }

