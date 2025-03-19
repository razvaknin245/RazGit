#include "printest.h"

void printTest(int flag,int line,char* file_name,int *success_flag)
{
	if(0 == flag)
	{
		printf("\033[0;32m");
		printf("Test in line %d SUCCESS at file : %s \n",line,file_name);
		printf("\033[0m");
		*success_flag = 1;
	}
	if(0 != flag)
	{
		printf("\033[1;31m");
		printf("Test in line FAILED at line %d in file : %s  \n",line,file_name);
		printf("\033[0m");
		*success_flag = 0;
	}
}
