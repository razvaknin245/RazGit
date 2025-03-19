#include "structs.h"
#include<stdio.h>
int main()
{
	 vals my_arr[5];
	 int i = 0;
	 
	 my_arr[0] = initInts(5);
	 my_arr[1] = initFloats(56.33);
	 my_arr[2] = initStrings("chapter");

	 
	printf("before adding \n");
	for(i = 0; i < 3; ++i)
	{
		my_arr[i].print(my_arr[i].data);
	}
	printf("now adding \n");
	for(i = 0; i < 3; ++i)
	{
		my_arr[i].add(&(my_arr[i].data), 10);
	}
	printf("after:\n");
	for(i = 0; i < 3; ++i)
	{
		my_arr[i].print(my_arr[i].data);
	}
	for(i = 0; i < 3; ++i)
	{
		my_arr[i].clean(my_arr[i].data);
	}
	printf("finished :)\n");
	return 0;
}
