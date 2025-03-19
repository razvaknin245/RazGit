#include "logger.h"

struct print_me str_arr[10];

int main(int argc,char* argv[])
{
	give_val(str_arr);
	return 0;
}
void print_func(int x)
{
	printf("now in print_func num :%d \n",x);
}

void give_val(struct print_me arr[])
{
	int i = 0;
	for(;i<10;++i)
	{
		arr[i].x = i;
		printf("%d\n" , arr[i].x);
		arr[i].foo_ptr = print_func;
		arr[i].foo_ptr(arr[i].x);
	}
}

