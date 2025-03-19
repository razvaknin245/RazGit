#include "arrays_pointers.h"

/*

*/
int findLucky(int n)
{
	int * arr;
	int curr = 0;
	int i = 0;
	arr = (int *)malloc((n * sizeof(int)));
	for(i=0;i<n;i++)
	{
	   arr[i] = 0;
	}
	if( arr == NULL)
	{
	 printf("Error memory not allocated. \n ");
	 return 0;
	}
	while(curr < n-1)
	{
	 arr[curr] = curr+1;
	 curr++;
	}
	curr = 0;
	while(curr != arr[curr])
	{
	   arr[curr] = arr[arr[curr]];
	   curr = arr[curr];
	}
	free(arr);
	return curr;		
}
void printTypes()
{
 	printf("the size of  signed char %lu \n",sizeof(signed char));
 	printf("the size of unsigned char %lu \n",sizeof(unsigned char));
 	printf("the size of char %lu \n",sizeof(char));
 	printf("the size of signed int %lu \n",sizeof(signed int));
 	printf("the size of unsigned int %lu \n",sizeof(unsigned int));
 	printf("the size of int %lu \n",sizeof(int));
 	printf("the size of short int  %lu \n",sizeof(short int));
 	printf("the size of unsigned short int %lu \n",sizeof(unsigned short int));
 	printf("the size of long int %lu \n",sizeof(long int));
 	printf("the size of unsigned long int %lu \n",sizeof(unsigned long int));
 	printf("the size of float %lu \n",sizeof(float));
 	printf("the size of double %lu \n",sizeof(double));
 	printf("the size of long long int %lu \n",sizeof(long double));
}
int * rowSum(int arr[r][c],int *dest,int rows,int column)
{
 	int i , j;
 	int* start = dest;
 	for(i = 0; i < column;i++)
 	{
 		for(j = 0;j < rows;j++)
 		{
 	        	*dest += arr[i][j];
		}
	 	dest++;
	}
	return start;
}
char** createNewenvp(char *env[] ,size_t size_env)
{
	char** n_evnp = (char**)malloc((sizeof(char*)*(size_env)));
	char** start = n_evnp;
	if(!n_evnp)
	{
		n_evnp = NULL;
	}
	while(NULL !=  *env)
	{
        	*n_evnp = malloc(strlen(*env)+1);
		if(NULL == *n_evnp)
		{
		  	n_evnp--;
		   	while(n_evnp != start)
		   	{
		   		free(*n_evnp);
		   		n_evnp--;
		   	}
		   	return NULL;
		}
		n_evnp++;
		env++;
	}
	return start;
}
void copyEnvp(char **newEnv,char* src[])
{
	while(NULL != *src)
	{
		char * start_src = *src;
		char * start_dest = *newEnv;
		while('\0' != *start_src)
		{
			*start_dest = tolower(*start_src);
			(start_dest)++;
			(start_src)++;
		}
		*start_dest = '\0';
		newEnv++;
		src++;
	 }
	 newEnv = NULL;
}
size_t retSize(char* src[])
{
	char ** start_src = src;
  	while(NULL != *src)
  	{
  		src++;
	}
	return (src - start_src);
}
void printEnv(char** env, size_t size)
{
	char ** save = env + size;
	while(env != save)
	{
		printf("%s \n",*env);
		env++;
	}
	printf("\n End Printing \n");
}
void freeFunc(char* env[],size_t size)
{
	char **save = env;
	char **end = env + size;	
	while(save != end)
	{
		free(*save);
		*save = NULL;
		save++;	 
	}
	free(env);
	env = NULL;
}
void excEnvironment(char *envp[])
{	
	size_t env_Size = retSize(envp);
	char **new_evnp = createNewenvp(envp,env_Size);
	copyEnvp(new_evnp,envp);
	printEnv(new_evnp,env_Size);
	freeFunc(new_evnp,env_Size);
}

