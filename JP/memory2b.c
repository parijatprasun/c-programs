
/*   \textbf{P-memory2b:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: use of 'malloc()' and 'realloc()'.)

\\[5mm]

 {\large Program: memory2b.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory2b.c
	------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  int i, n;
  long int *a;

  printf("\n Input:\n");

  printf(" Type the number of integer elements in the array, n = ");
  scanf("%d", &n);

//  a = (int *) malloc(n * sizeof(int));
  a = (long int *) malloc(10);
//  a = malloc(10);

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

//  a = (long int *) realloc(a, 6);
  a = (long int *) realloc(a, 30);

  printf("\n After reallocation:\n");

  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

  printf("\n\n");

  printf("\n Type the integer elements of the array:\n");
  for (i = 0; i < n; i++)
   {
   printf(" %5s a[%d] = ", "", i);
   scanf("%d", &a[i]);
   }

  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

//  a = (long int *) realloc(a, 6);
  a = (long int *) realloc(a, 30);

  printf("\n After reallocation:\n");

  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

/*
  free(a);
   str = (char *) realloc(str, 30 * sizeof(char));
*/
  printf("\n\n");
 }

