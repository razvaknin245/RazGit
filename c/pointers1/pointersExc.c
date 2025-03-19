#include "pointersExc.h"

void SwapInt(int* x ,int* y)
{
   int tmp = *x;
   *x = *y;
   *y = tmp;
}

void Copy_Array(int* src,int size,int* dst)
{
	int i;
	for(i=0; i < size; i++)
	{
	   dst[i] = src[i];
	}	
}

void Swap_Size_T(size_t* x ,size_t* y)
{
	size_t tmp = *x;
	*x = *y;
	*y = tmp;
}

void Swap_Pointers_Size_T(size_t** x ,size_t** y)
{
	Swap_Size_T((size_t*)x ,(size_t*)y);
}
