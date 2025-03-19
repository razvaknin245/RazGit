#include <stdio.h>
#include <stdlib.h>
#include "strHead.h"

size_t StrLen(const char *str)
{
   size_t count = 0;
   while(str[count] != '\0')
   {
	count++;
   }
  return count;
}

int StrCmp(const char *str1 , const char *str2)
{
	int i = 0;
	while(str1[i] != '\0' || str2[i] != '\0')
	{
	    if(str1[i] > str2[i])
	    {
	    	return 1; 
	    }
	    else if(str1[i] < str2[i])
	    {
	    	return -1;
	    }
	    i++;	
	}
	return 0;
}
