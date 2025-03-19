#include "function.h"

foo_ptr fp_arr[256] = {NULL};
/*
	Reviewer: Or Gozlan
	What func do :
	the func use if/else to check the char that enter
*/
void if_key_Check(char c)
{
	while(c)
	{
		system("stty -icanon -echo");
		c = getchar();
		if(c == 'A')
		{
			printf("A-pressed \n");
		}
			else if(c == 'T')
			{
				printf("T-pressed \n");
			}
				else if(c == ESC)
				{
					system("stty icanon echo");
					return;
				}
	}
	
}
/*
	Reviewer: Or Gozlan
	What func do :
	the func use switch/case to check the char that enter
*/
void sc_key_Check(char c)
{
	while(c)
	{
		c = getchar();
		system("stty -icanon -echo");
		switch(c)
		{
			case 'A':
			printf("A-pressed \n");
			break;
			
			case 'T':
			printf("T-pressed \n");
			break;
			
			case ESC:
			system("stty icanon echo");
			return;
		}
	}
}
void empty_func(){}
/*
	Reviewer: Or Gozlan 
	What func do :
	the func is for initialize the function pointer to empty function 
*/
void initLut(int size)
{
	int i = 0;
	while(i < size)
	{
		fp_arr[i] = empty_func;
		i++;
	}
	fp_arr['A'] = a_key;
	fp_arr['T'] = t_key;
	fp_arr[ESC] = esc_key;
}
void a_key()
{
	printf("A-pressed \n");
}
void t_key()
{
	printf("T-pressed \n");
}
void esc_key()
{
	exit(0);
}


