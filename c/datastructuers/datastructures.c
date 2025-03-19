#include "datastructures.h"

void FindDup(int *arr, int size)
{
	int i = 0;
	int j = i + 1;
	for(i = 0; i < size; i++)
	{
		for(j = i+1;j< size; j++)
		{
			if(arr[i] == arr[j])
			{
				printf("%d \n", arr[i]);
			}
		}
	}
}
