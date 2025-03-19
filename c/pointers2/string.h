#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char * StrCpy(char *dest, const char *src);

char * StrNcpy(char * dest, const char * src, size_t n);

int StrNcmp(const char *str1, const char *str2 , size_t n);

size_t StrLen(const char *str);

int StrCmp(const char *str1,const char *str2);

int StrCasecmp (const char * str1,const char * str2);

char *StrChr(const char *s , int c);

char *StrDup(const char *s);

char *StrCat(char *dest, const char *src);

char *StrNcat(char *dest, const char *src,size_t n);

char *StrStr(const char *haystack, const char* needle);

size_t StrSpn(const char *s, const char *accept);

int StrPali(const char *s);

