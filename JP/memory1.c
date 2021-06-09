
/*   \textbf{P-memory1:} (new) Write a program to illustrate the use of \textbf{Dynamic Memory Allocation}. (kr-143,167,185,252: balagurusamy-331)

 (Problem: Write a program to  .)

\\[5mm]

 {\large Program: memory1.c ;\hspace*{5mm} Include? (Y/N): \hspace*{1cm}; \;Sum No. = }
-------------------------------------------------------------------------------
MALLOC(3)                  Linux Programmer’s Manual                 MALLOC(3)
                                                                                
NAME
       calloc, malloc, free, realloc - Allocate and free dynamic memory
                                                                                
SYNOPSIS
       #include <stdlib.h>
                                                                                
       void *calloc(size_t nmemb, size_t size);
       void *malloc(size_t size);
       void free(void *ptr);
       void *realloc(void *ptr, size_t size);
                                                                                
DESCRIPTION
       calloc()  allocates memory for an array of nmemb elements of size bytes
       each and returns a pointer to the allocated memory.  The memory is  set
       to zero.
                                                                                
       malloc()  allocates  size  bytes and returns a pointer to the allocated
       memory.  The memory is not cleared.
                                                                                
       free() frees the memory space pointed to by ptr, which must  have  been
       returned by a previous call to malloc(), calloc() or realloc().  Other-
       wise, or  if  free(ptr)  has  already  been  called  before,  undefined
       behaviour occurs.  If ptr is NULL, no operation is performed.
                                                                                
       realloc()  changes  the  size  of the memory block pointed to by ptr to
       size bytes.  The contents will be unchanged to the minimum of  the  old
       and new sizes; newly allocated memory will be uninitialized.  If ptr is
       NULL, the call is equivalent to malloc(size); if size is equal to zero,
       the  call is equivalent to free(ptr).  Unless ptr is NULL, it must have
       been returned by an earlier call to malloc(), calloc() or realloc().

RETURN VALUE
       For calloc() and malloc(), the value returned is a pointer to the allo-
       cated  memory,  which  is suitably aligned for any kind of variable, or
       NULL if the request fails.
                                                                                
       free() returns no value.
                                                                                
       realloc() returns a pointer to the newly  allocated  memory,  which  is
       suitably  aligned  for  any  kind of variable and may be different from
       ptr, or NULL if the request fails. If size was equal to 0, either  NULL
       or a pointer suitable to be passed to free() is returned.  If realloc()
       fails the original block is left untouched - it is not freed or  moved.
-------------------------------------------------------------------------------


	SOURCE FILE : memory1.c
	-----------------------

*/
 # include <stdio.h>
 # include <stdlib.h>

// # define NULL 0

 main()
  {
  int *p, *table;
  int size;


//  printf("\n Input/Output:\n");

  printf("\n What is the size of table ? ");
  scanf("%d", &size);

  printf(" %3s size = %d", "", size);

  printf("\n");

  if((table = (int *)malloc(size * sizeof(int))) == NULL)
   {
   printf(" No space available\n");
   exit(1);
   }

  printf("\n Address of the first byte is %u \n", table);

  printf("\n Input table values:\n");

  for(p = table; p < table + size; p++)
   scanf("%d", p);

  for(p = table + size - 1; p >= table; p--)
   printf("\n %d is stored at address %u \n", *p, p);

  free(p);

  printf("\n\n");
 }

