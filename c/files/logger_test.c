#include "logger.h"



int main(int argc,char* argv[])
{
	give_val(str_arr);
	fn.f_name = argv[1];
	
	write_to_file(fn);
	return 0;
}
void print_func(int x)
{
	printf("now in print_func num :%d \n",x);
}

void give_val(print_me arr[])
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


void give_val(struct print_me arr[]);

void print_func(int x);

struct print_me
{
	int x;
	void (*foo_ptr)();
};
extern struct print_me str_arr[10];
