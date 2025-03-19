#include "stack.h"
#include <printest.h>
int main()
{
	size_t capacity = 5;
	size_t elem_size = 7;
	int cap_flag = 1;
	char stringtopush[6] = "yahav";
	char stringtopush2[7] = "yahav2";
	stack_t *st = StackCreate(capacity,elem_size);
	printTest(StackSize(st),__LINE__,__FILE__);
	if(StackCapacity(st) == capacity)
	{
		cap_flag = 0;
	}
	printTest(cap_flag,__LINE__,__FILE__);
	printTest(IsStackEmpty(st),__LINE__,__FILE__);
	StackPush(st,stringtopush);
	puts(StackPeek(st));
	printf("size of stack after push first : %d \n",(int)StackSize(st));
	StackPush(st,stringtopush2);
	puts(StackPeek(st));
	printf("size of stack after push second : %d \n",(int)StackSize(st));
	StackPop(st);
	printf("size of stack after pop first: %d \n",(int)StackSize(st));
	StackPop(st);
	printf("size of stack after pop second: %d \n",(int)StackSize(st));
	printTest(IsStackEmpty(st),__LINE__,__FILE__);
	printTest(StackDestroy(st),__LINE__,__FILE__);
	
	return 0;
}
