#include "datastructures.h"


int main()
{
	int arr [] = {1 , 1 ,5 ,5 ,4 ,2 ,8 ,9 ,9};
	int size = sizeof(arr) / sizeof(arr[0]);
	FindDup(arr,size);
	return 0;
}

