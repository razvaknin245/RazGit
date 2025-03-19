#include "string.h"

char* StrCpy(char * dest,const char * src)
{
	char *destPlace = dest;
	while(*src != '\0')
	{
	 *dest = *src;
	 dest++;
	 src++;
	}
	*dest = '\0';
	return destPlace;
}

char* StrNcpy(char * dest,const char * src, size_t n)
{
   char *destPlace = dest;
   int flag = 0;
   while(*src != '\0')
   {
    *dest = *src;
    if(*(src+1)=='\0')
    	{
    	  flag = 1;
    	}
    dest++;
    src++;
   }
   if(flag == 1)
   {
     while(n > 0)
     {
     	*dest = '\n';
     	dest++;
     	n--;
     }
   }
   return destPlace;
}
size_t StrLen(const char *str)
{
   size_t count = 0;
   while(*str != '\0')
   {
	str++;
	count++;
   }
  return count;
}

int StrCmp(const char *str1 , const char *str2)
{
	while(*str1 != '\0' || *str2 != '\0')
	{
	    if(*str1 > *str2)
	    {
	    	return 1; 
	    }
	    else if(*str1 < *str2)
	    {
	    	return -1;
	    }
	    str1++;
	    str2++;	
	}
	return 0;
}
int StrNcmp(const char *str1, const char *str2 , size_t n)
{
	while(n > 0)
	{
	    if(*str1 > *str2)
	    {
	    	return 1; 
	    }
	    else if(*str1 < *str2)
	    {
	    	return -1;
	    }
	    str1++;
	    str2++;
	    n--;	
	}
	return 0;
}
int StrCasecmp (const char * str1,const char * str2)
{
	int diff = 'a' - 'A';
	char tmp1;
	char tmp2;
	while(*str1 != '\0' || *str2 != '\0')
	{	
		tmp1 = *str1;
		tmp2 = *str2;
	 	if(tmp1 >='A' && tmp1 <= 'Z')
		{
	 	 	tmp1 = tmp1 + diff;
	 	}
		if(tmp2 >='A' && tmp2<='Z')
		{
	 	 	tmp2 = tmp2 + diff;
	 	}
		if(tmp1 > tmp2)
		{
			return 1;
		}
		else if(tmp1 < tmp2)
		{
		 	return -1;
		}
		str1++;
		str2++;
	}
	return 0;	
}
char *StrChr(const char *s , int c)
{
	while(*s != '\0' )
	{
		if(*s == c)
		{
		  return (char *)s;
		}
	  s++;
	}
	return NULL;
}
char *StrDup(const char *s)
{
	char *retStr;
	char *tmp;
	int countLen = 0;
	while(*(s + countLen) != '\0')
	{
		countLen++;
	}
	retStr = malloc(countLen + 1); 
	tmp = retStr;
	while(*s != '\0')
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';
	return retStr;	
}
char *StrCat(char *dest, const char *src)
{
	int destLen = 0;
	char* tmp;
	while(*(dest+destLen) != '\0')
	{
		destLen++;	
	}
	tmp = dest+destLen;
	while(*src != '\0')
	{
	     *tmp = *src;
	     tmp++;
	     src++;
	}
	*tmp = '\0';
	return dest;	
}
char *StrNcat(char *dest, const char *src,size_t n)
{
	int destLen = 0;
	char* tmp;
	while(*(dest+destLen) != '\0')
	{
		destLen++;	
	}
        tmp = dest + destLen;	
	while(n > 0 && n--)
	{
	    *tmp = *src;
	    tmp++;
	    src++;
	}
	return dest;	
}
char *StrStr(const char *haystack, const char* needle)
{
	const char* currHaystack;
	const char* headNeedle;
	int len;
	int flag = 0;
	len = StrLen(needle);

	headNeedle = needle;
	while(*haystack != '\0')
	{
	   if(*needle == *haystack)
	   {
	      if(needle == headNeedle)
	      {
	        currHaystack = haystack;
	      }
	      needle++;
	      flag++;
	   }
	   else
	   {
	     needle = headNeedle;
	   }
	   if(flag == len)
	     return (char*)currHaystack;
	   haystack++;
	}
	return NULL;	
}
size_t StrSpn(const char *s, const char *accept)
{
	size_t flag = 0;
	const char* temp = accept;
	while(*s !='\0')
	{
		accept = temp;
		while(*accept != '\0')
		{
			if(*accept == *s)
			{
			 flag++;
			 break;
			}
			accept++;
		 }
		 if(*s != *accept)
		 {
		  return flag;
		 }
		s++;
	}
	return flag;
}
int StrPali(const char *s)
{
	int len = StrLen(s);
	int i = 0;
	int j = len - 1;
	const char* tmp = s+j;
	for(i = 0; i < len / 2;i++)
	{
		if(*s != *tmp)
		{
		  return -1;
		}
		s++;
		tmp--;
	}
	return 0;
}
