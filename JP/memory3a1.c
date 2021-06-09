
/*   \textbf{P-memory3a1:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: )

\\[5mm]

 {\large Program: memory3a1.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory3a1.c
	-------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  int i, n;
  char *s;

  printf("\n Input:\n");

  printf(" Type the number of character elements in the array, n = ");
  scanf("%d", &n);

  s = (char *) calloc(n, sizeof(char));

  printf("\n Type the character elements of the array:\n");
  for (i = 0; i < n; i++)
   {
   getchar();
   printf(" %5s s[%d] = ", "", i);
   scanf("%c", &s[i]);
   }

  printf("\n Output:\n");

  printf(" The values and addresses of the character elements:");
  for (i = 0; i < n; i++)
   printf("\n   s[%d]: value = %c; address = %u", i, s[i], &s[i]);

  free(s);

  s = (char *) calloc(n, sizeof(int));

  printf("\n\n After using second calloc():\n");

  printf(" The values and addresses of the character elements:");
  for (i = 0; i < n; i++)
   printf("\n   s[%d]: value = %d; address = %u", i, s[i], &s[i]);

  free(s);

  printf("\n\n");
 }

