#ifndef __WORDBOUNDARY_H__
#define __WORDBOUNDARY_H__ 
#include<string.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<assert.h>

#define WORD sizeof(size_t)



/*
	reviewd by maskit 
	date : 28.11.2022 16:30
*/
typedef union unibyte
{
		char eightbit[WORD]; /*using union to use the array on the size of WORD with the same memory location and get the whole WORD*/
		size_t wordbits;
}u32;


void* MyMemset(void *s, int c, size_t n);

void * MyMemcpy(void *dest , const void *src ,size_t n);

void * MyMemmove(void *dest , const void *src ,size_t n);

#endif
