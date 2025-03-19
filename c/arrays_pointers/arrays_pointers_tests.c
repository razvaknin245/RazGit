#include "arrays_pointers.h"
int main(int argc,char *argv[],char** envp)
{
	int multiArr[r][c] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4},{5,5,5,5,5}};
	int *dest = malloc(r * sizeof(int*));
	int i = 0;
	for(i=0;i<r;i++)
	   dest[i] = 0;
	if( dest == NULL)
	{
	 printf("Error memory not allocated. \n ");
	 return 0;
	}

	printf("From 5 Guys The Lucky Guy is in place %d \n",findLucky(5));
	printf("From 50 Guys The Lucky Guy in place %d \n",findLucky(50));
	printf("From 40 Guys The Lucky Guy in place %d \n",findLucky(40));
	
	/*printTypes();*/
	rowSum(multiArr , dest,r,c);
	
	while( i < r)
	{
	  printf("%d \n", *dest);
	  dest++;
	  i++;
	}
	printf("%d \n" ,argc);
	printf("%s \n" ,*argv);
	excEnvironment(envp);
	while(*envp)
	{
	 printf("%s \n",*envp);
	 envp++;
	}
	free(dest);
	return 0;
	
}
