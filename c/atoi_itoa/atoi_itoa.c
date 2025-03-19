#include "atoi_itoa.h"
#include "printest.h"
char *ItoA(int value,char *string,int base)
{
	int i = 0;
	int remain = 0;
	int is_negative_flag = 0;
	
	if(value < 0)
	{
		value = value *(-1);
		is_negative_flag = 1;
	}
	if(value == 0)
	{
		string[i++] = '0';
		string[i] = '\0';
		return string;
	}
	while(value)
	{
		remain = value % base;

		if(remain > 9)
		{
			string[i++] = (remain - 10) + 'a';
		}
		else
		{
			string[i++] = remain + '0';
		}
		value /= base;
	}
	
	if(is_negative_flag == 1)
	{
		
		string[i] = '-';
		i++;
	}
	string[i] = '\0';
	
	reverse(string,strlen(string));
	
	return string;
	
}
int AtoI(const char *string,int base)
{
	int retVal = 0;
	int flag_sign = 1;
	char *start;
	int extend = 0;
	int pow = 1;
	
	if(string[0] == '-')
	{
		flag_sign = -1;
		++string;
	}
	
	start = (char*)string;

	if(base > 10)
	{
		extend = 9;
	}
	else
	{
		extend = base;
	}
	
	while(('0' <= (*(start+1)) && (*(start)+ 1) < '0' + extend) || ('a' <= *(start+1) && *(start+1) < ('a'+ base - 11)))
	{
		pow *= base;
		++start;
	}
	while( ('0'<= *string && *string < '0' + extend) || ('a' <= *string && *string <= ('a' + base - 11)))
	{
		if(isdigit(*(string)))
		{
			retVal = retVal +((*string)-'0')*pow;	
		}
		else
		{
			retVal = retVal +((*string)-'a'+10)*pow;
		}
		pow /= base;
		++string;
	}
	return (retVal * flag_sign);
}





char* reverse(char *str , int size)
{
	int i,j;
	char temp;
	j = size - 1;
	for( i = 0;i < size / 2; i++)
	{
	 temp = str[i];
	 str[i] = str [j];
	 str[j] = temp;
	 j--;
	}
	return str;
}
int compareInt(int n1,int n2)
{
	if(n1 == n2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void Cmp3Str(char *str1, char *str2, char *str3,int len1,int len2,int len3)
{
	int dict[256] = {0};
	int i = 0;
	while(i < len1)
	{
		dict[(int)(*str1)] = 1;
		str1++;
		i++;
	}
	i = 0;
	while(i < len2)
	{
		if(dict[(int)(*str2)] == 1)
		{
		   dict[(int)(*str2)] = 2;	
		}
		str2++;
		i++;
	}
	i = 0;
	while(i < len3)
	{
		if(dict[(int)(*str3)] == 2)
		{
			dict[(int)(*str3)] = 0;	
		}
		str3++;
		i++;
	}
	i = 0;
	while(i<256)
	{
		if(dict[i] == 2)
		{
			printf("%c \n" ,(char)i);
			last_print = (char)i;
		}
		i++;
	}
}

void compareToOriginal(const char *str)
{
	printTest(compareInt(AtoI(str,10),atoi(str)),__LINE__,__FILE__);
}
int checklittle()
{
	int n = 1;
	if(*(char*)&n == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}




