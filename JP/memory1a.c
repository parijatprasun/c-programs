
/*   \textbf{P-memory1a:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to make a duplicate of a given string allocating memory space for it using 'malloc()'.)

\\[5mm]

 {\large Program: memory1a.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1a.c
	------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  char s[25], *p;

  printf("\n Type a string, s = ");
  scanf("%s",s);

  p = (char *) malloc(strlen(s) + 1);

  if(p != NULL)
   strcpy(p,s);

  printf("\n The given string, s = %s\n", s);
  printf(" The copied string, p = %s\n", p);

  free(p);

  printf("\n\n");
 }

