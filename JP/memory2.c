
/*   \textbf{P-memory2:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: use of 'malloc()' and 'realloc()'.)

\\[5mm]

 {\large Program: memory2.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory2.c
	-----------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  char *str = (char *) malloc(100 * sizeof(char));

  printf("\n Type a string, str = ");
  scanf("%s",str);

  if(str != NULL)
   {
   str = (char *) realloc(str, 30 * sizeof(char));
   }

  printf("\n The given string, str = %s", str);

  free(str);

  printf("\n\n");
 }

