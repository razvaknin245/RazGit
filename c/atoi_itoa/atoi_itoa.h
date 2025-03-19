#ifndef __ATOI_ITOA_H__
#define __ATOI_ITOA_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
#include <ctype.h>

/*reviewed by or gozlan */

#define IS_LITTLE_ENDIAN (*(uint16_t *)"\0\xff" > 0x0100)

void Cmp3Str(char *str1, char *str2, char *str3,int len1,int len2,int len3);

char *reverse(char *str , int length);

char *ItoA(int value,char *string,int base);

int AtoI(const char *string,int base);

int compareInt(int n1,int n2);

void compareToOriginal(const char *str);

int checklittle();

#endif 

