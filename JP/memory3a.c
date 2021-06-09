
/*   \textbf{P-memory3a:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to read 'n' integer elements of an array and allocate memory for them using 'calloc()'. Print the values and addresses of the elements of the array. After freeing the space, make a second call to 'calloc()' and observe that all values are initialized to 0 and the addresses remain unchanged.)

\\[5mm]

 {\large Program: memory3a.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory3a.c
	------------------------

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

  a = (int *) calloc(n, sizeof(int));

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

  free(a);

  a = (int *) calloc(n, sizeof(int));

  printf("\n\n After using second calloc():\n");

  printf(" The values and addresses of the integer elements:");
  for (i = 0; i < n; i++)
   printf("\n   a[%d]: value = %2d; address = %u", i, a[i], &a[i]);

  free(a);

  printf("\n\n");
 }

