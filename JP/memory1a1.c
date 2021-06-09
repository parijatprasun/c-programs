
/*   \textbf{P-memory1a1:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to make a duplicate of a given string allocating memory space for it using 'malloc()' and checking for the availability of memory.)

\\[5mm]

 {\large Program: memory1a1.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1a1.c
	-------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  char s[25], *p;

  printf("\n Input:\n");

  printf(" Type a character string, s = ");
  scanf("%s",s);

  printf("\n Output:\n");

  if ((p = (char *) malloc(strlen(s) + 1)) == NULL)
   {
   printf("\n Memory is not available.");
   return 0;
   }
  else
   {
   printf(" Memory is available.\n");
   strcpy(p,s);
   }

  printf("\n The given string, s = %s", s);
  printf("\n The copied string, p = %s", p);

  free(p);

  printf("\n\n");
 }

