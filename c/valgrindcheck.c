#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *arr2 = malloc(10);
	char arr[10] = "raz.vaknin";
	arr[11] = 'g';
	free(arr2);
	printf("%p \n",(void*)arr2);
	printf("%c \n",arr[11]);
	return 0;
}

