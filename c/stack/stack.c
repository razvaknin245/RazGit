#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
	char *base;
	char *top;
	size_t capacity;
	size_t elem_size;
};

stack_t *StackCreate(const size_t capacity,const size_t elem_size)
{
	stack_t *newstack;
	assert(capacity);
	assert(elem_size);
	newstack = malloc((sizeof(stack_t)));
	if(NULL == newstack)
	{
		printf("allocate failed \n");
	}
	newstack->base = malloc(capacity*elem_size);
	if(NULL == newstack->base)
	{
		printf("allocate failed \n");
	}
	newstack->top = newstack->base;
	newstack->capacity = capacity;
	newstack->elem_size = elem_size;
	return newstack;
}
int StackDestroy(stack_t *stack)
{
	assert(stack);
	free(stack->base);
	free(stack);
	return 0;
}
void StackPush(stack_t *stack ,const void *elem)
{
	assert(elem);
	memcpy(stack->top,elem,stack->elem_size);
	stack->top += stack->elem_size;
}
void *StackPeek(const stack_t *stack)
{
	return stack->top - stack->elem_size;	
}
void StackPop(stack_t *stack)
{
	stack->top = ((stack->top)-(stack->elem_size));
}
int IsStackEmpty(const stack_t *stack)
{
	if(stack->base == stack->top)
	{
		return 0;
	}
	return -1;

}
size_t StackSize(const stack_t *stack)
{
	return ((stack->top) - (stack->base))/ stack->elem_size;
}
size_t StackCapacity(const stack_t *stack)
{
	return stack->capacity;
}
