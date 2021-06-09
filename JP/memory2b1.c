
/*   \textbf{P-memory2b1:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: use of 'malloc()' and 'realloc()'.)

\\[5mm]

 {\large Program: memory2b1.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory2b1.c
	-------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  int i, n;
  int *a;

  printf("\n Input:\n");

  printf(" Type the number of integer elements in the array, n = ");
  scanf("%d", &n);

  a = (int *) malloc(n * sizeof(int));
//  a = (int *) malloc(12);
//  a = malloc(10);
//  a = (int *) calloc(5, sizeof(int));

  printf("\n Type the integer elements of the array:\n");
  for (i = 0; i < n; i++)
   {
   printf(" %5s a[%d] = ", "", i);
   scanf("%d", &a[i]);
   }

  printf("\n Output:\n");

  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

//  a = (int *) realloc(a, 6);
//  a = (int *) realloc(a, (n*3) * sizeof(int));

  a = (int *) realloc(a, (n/2) * sizeof(int));

  printf("\n After reallocation:\n");
/*
  printf(" Type the number of integer elements in the array, n = ");
  scanf("%d", &n);

  printf("\n Type the integer elements of the array:\n");
  for (i = 0; i < n; i++)
   {
   printf(" %5s a[%d] = ", "", i);
   scanf("%d", &a[i]);
   }
*/
  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

  free(a);

  printf("\n\n");
 }

