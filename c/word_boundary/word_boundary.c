#include "word_boundary.h"

void* MyMemset(void *s, int c, size_t n)
{
	unsigned char *ptr = s;
	size_t i = 0;
	union unibyte u32;
	
	while(i < WORD)
	{
		u32.eightbit[i] = c;
		++i;
	}
	
	while(n)
	{
		if(n >= WORD && (size_t) ptr % WORD == 0)/*check if n is bigger then WORD to know if i can copy whole
							WORD and then check if the address of the pointer is aligned */								
		{
			*(size_t*)ptr = u32.wordbits;
			ptr += WORD;
			n -= WORD;
		}
		else
		{
			*ptr++ = (unsigned char)c; /*if not aligned or not bigger than n so copy byte - byte*/
			n--;
		}
	}
	return s;
}

void * MyMemcpy(void *dest, const void *src, size_t n)
{
	char* psrc = (char*)src; /* save src start */
	char* pdest = (char*)dest; /* save dest start */
	
	assert(dest);
	assert(src);
	
	while(n && pdest && psrc) /*check if n and dest and src have content*/
	{
		if(n >= WORD && ((size_t) psrc % WORD == 0) && pdest) /* check if n bigger than WORD,and psrc is aligned and
									pdest not equal to '\0'*/ 							
		{
			strncpy(pdest,psrc,WORD);
			pdest += WORD;
			psrc += WORD;
			n -= WORD;
		}
		else
		{
			*pdest = *psrc; /*if not aligned or n smalled than WORD and 
					pdest have content so copy byte - byte*/
			++pdest;
			++psrc;
			n--;
		}
	}
	return dest;
}

void * MyMemmove(void *dest, const void *src, size_t n)
{
	char* psrc = ((char*) src); /* save src start that i can work with src*/
	char* pdest = ((char*) dest);/* save dest start for that i can work with dest and return the start in the end*/
	if(psrc < pdest && psrc + n > pdest)  /*check if pdest address is bigger that psrc address and psrc+n address bigger
						then pdest*/  	
	{
		psrc += n;
		pdest += n;
		while(n > 0)
		{
			*--pdest = *--psrc;
			n--;
		}
	}
	else
	{
		while(n > 0)
		{
			*pdest++ = *psrc++;
			n--;
		}
	}
	return dest;
}

