
/*   \textbf{P-memory1c:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to read 'n' integer elements of an array and allocate memory for them using 'malloc()'. Print the values and addresses of the elements of the array at least thrice and observe that the starting address and the subsequent addresses remain unchanged in all 'runs' unless the program is further modified for any change and compiled.)

\\[5mm]

 {\large Program: memory1c.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1c.c
	------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  int i, n;
  int *b;

  printf("\n Input:\n");

  printf(" Type the number of integer elements in the array, n = ");
  scanf("%d", &n);

  b = (int *) malloc(n * sizeof(int));

  printf("\n Type the integer elements of the array:\n");
  for (i = 0; i < n; i++)
   {
   printf(" %5s b[%d] = ", "", i);
   scanf("%d", &b[i]);
   }

  printf("\n Output:\n");

  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   b[%d]: value = %2d; address = %u", i, b[i], &b[i]);

  free(b);

  printf("\n\n");
 }

