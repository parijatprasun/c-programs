
/*   \textbf{P-memory1c1:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to read the integer elements of an array and allocate memory for them using 'malloc()'. Print the values and addresses of the elements of the array at least thrice and observe that the addresses remain unchanged in all 'runs'.)

\\[5mm]

 {\large Program: memory1c1.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1c1.c
	-------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  unsigned int i;
  int n;
  int *b;

  printf("\n Type the number of integer elements in the array, n = ");
  scanf("%d", &n);

  b = (int *) malloc(n * sizeof(int));
/*
  if((b = (int *) malloc(n * sizeof(int))) == NULL)
   return 0;
*/
  for (i = 0; i < n; i++)
   printf("\n   b[%d]: value = %2d; address = %u", i, b[i], &b[i]);

  printf("\n Type the integer elements of the array:\n");
  for (i = 0; i < n; i++)
   {
//   printf(" %5s b[%d] = ", "", i);
//   scanf("%d", &b[i]);
   b[i] = rand();
   }

  printf("\n The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   b[%d]: value = %2d; address = %u", i, b[i], &b[i]);

//  free(b);

  printf("\n");

  for (i = 0; i < n; i++)
   printf("\n   b[%d]: value = %2d; address = %u", i, b[i], &b[i]);

  printf("\n\n");
 }

