#include<stdio.h> /* to use printf command*/
#include<stdlib.h>/* to use malloc and free functions */
#include<ctype.h> /*for tolower case*/
#include<string.h>

#define r 5
#define c 5

int findLucky(int n);

void printTypes();

int * rowSum(int arr[r][c],int *dest,int rows,int column);

void copyEnvp(char **newEnv,char* src[]);

void printEnv(char* env[],size_t size);

size_t retSize(char* src[]);

void excEnvironment(char *envp[]);

char** createNewenvp(char *env[] ,size_t sizeEnv);

void freeFunc(char* env[],size_t size);


