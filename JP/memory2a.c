
/*   \textbf{P-memory2a:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to allocate memory to store a string of 100 characters and check for the availability of memory. Send an error message if the space is not available.)

\\[5mm]

 {\large Program: memory2a.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory2a.c
	------------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

 main()
  {
  char *s;

  s = (char *) malloc(100 * sizeof(char));

  if(s == NULL)
   {
   printf("\n No free space is available.\n");
   return 0;
   }
  else
   printf("\n OK. Free space is available.\n");

  printf("\n Now, type a string, s = ");
  scanf("%s",s);

  printf("\n The given string, s = %s", s);

  free(s);

  printf("\n\n");
 }

