
/*   \textbf{P-memory2b3:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to read 'n' integer elements of an array and allocate memory for them using 'malloc()'. Print the values and addresses of the elements of the array. Reduce the memory by half of the previous memory using 'realloc()' and print the values and addresses of the same array elements. Observe that the values remain unchanged up to the new size which is about half of the number of elements but all the addresses remain unchanged. Take the number of elements at least greater than 5 to observe the effect.)

\\[5mm]

 {\large Program: memory2b3.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory2b3.c
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

  a = (int *) realloc(a, (n/2) * sizeof(int));

  printf("\n\n After reallocation:\n");

  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

  free(a);

  printf("\n\n");
 }

