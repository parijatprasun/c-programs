
/*   \textbf{P-memory1b:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-167,185,252: balagurusamy-331)

 (Problem: Write a program to read 'n' integer elements of an array and then print their values and addresses at least thrice and observe that the addresses may change in each run.

\\[5mm]

 {\large Program: memory1b.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }


	SOURCE FILE : memory1b.c
	------------------------

*/
 # include <stdio.h>

 main()
  {
  int i, n;
  int b[10];

  printf("\n Input:\n");

  printf(" Type the number of integer elements in the array, n = ");
  scanf("%d", &n);

  printf("\n Type the integer elements of the array:\n");
  for (i = 0; i < n; i++)
   {
   printf(" %5s b[%d] = ", "", i);
   scanf("%d", &b[i]);
   }

  printf("\n Output:\n");

  printf(" The elements values and addresses:");
  for (i = 0; i < n; i++)
   printf("\n   b[%d]: value = %2d;  address = %u", i, b[i], &b[i]);

  printf("\n\n");
 }

