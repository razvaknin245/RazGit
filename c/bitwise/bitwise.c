#include "bitwise.h"
/*review by guy shababo*/
long Pow2(unsigned int x, unsigned int y)
{
	return (x<<y);
}
int checkPow(unsigned int n, int select)
{
	
	unsigned int i = 0; /*index to use for shift 2*/
	switch(select)
	{
		case 1:
			while((2 << i))
			{
				if(n == ((unsigned)1 << i))
				{
					return 1;
				}
				else
				{
					i++;
				}
			}
			return 0;
		case 2:
			if((n)&&!(n & (n - 1)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
	}
	return 1;
}
int addOne(int x)
{
	int index = 1;
	
	while(x & index)
	{
		x = x ^ index;
		index <<= 1;
	}
	x = x ^ index;
	return index;	
}
void threeBitsPrint(unsigned int arr[],int size)
{
	unsigned int count = 0;
	unsigned int n = 0;
	while(size)
	{
		n = *arr; /* give n the current number*/
		while(n)
		{
			count += n & 1; /* add to count if n is 1*/
			n >>=1;	 /*go to next bit*/	
		}
		if(count == 3)/*check if exactly 3 bits are on*/
		{
			printf("num %d have 3 bits \n",*arr);	
		}
		arr++;/*go to next number in the array*/
		size--;
		count = 0;
	}
	
}
void ByteMirrorLoop(unsigned char in)
{
	unsigned char count = sizeof(in) * 8 - 1;/*give count the max number*/
	unsigned char out = in; /* create new unsigned char for the result*/
	in >>= 1;
	while(in)
	{
		out <<= 1;
		out |= in & 1; /* check if in is 1 and then give out the result if he diffrent from in*/		
		in >>=1;
		count --;	
	}
	out <<= count;
	printf("after byte mirroring loop:%d \n",out);
}
void ByteMirrorNoLoop(unsigned char num)
{
	printf("after byte mirroring no loop in start %d \n",num);
	num = num >> 4 | num << 4; /*switch between nibbles*/
	num = ((num >> 2) & 0x33)| (num & 0x33) << 2; /*0x33 = 00110011*/
	num = ((num >> 1) & 0x55)| (num & 0x55) << 1; /*0x55 = 01010101*/
	printf("after byte mirroring no loop in start %d \n",num);
	
}
int checkTwoNSix(unsigned char num)
{
	unsigned int flag1 = 1 & (num >> 1); /*check if two is set*/
	unsigned int flag2 = 1 & (num >> 5);/*check if six is set*/
	 return (flag1 & flag2);/*then check if they both set*/
}
int checkTwoOrSix(unsigned char num)
{
	unsigned int flag1 = 1 & (num >> 1);/*check if two is set*/
	unsigned int flag2 = 1 & (num >> 5);/*check if six is set*/
	return (flag1 | flag2);/*check if al least is set*/ 
}
unsigned char SwapThirdFifth(unsigned char num)
{
	unsigned char bit5 = 1 & (num >> 4);
	unsigned char bit3 = 1 & (num >> 2);
	unsigned char tmp = bit5 ^ bit3;
	unsigned char result = 0;
	tmp = (tmp << 4) | (tmp << 2);
	
	return result = num ^ tmp;
}
unsigned int ClosedDivisibleBySixteen(unsigned int num)
{

	return (num>>4)<<4;
}
void swapInt(int num1,int num2)
{
	printf("num1 is %d , num2 is %d\n",num1,num2);
	num1 = num1 ^ num2; /*num1 now becomes 15 (1111)*/
	num2 = num1 ^ num2; /*num2 now becomes 10 (1010)*/
	num1 = num1 ^ num2; /*num1 now becomes 5 (0101)*/
	printf("num1 is %d , num2 is %d\n",num1,num2);
}
int countSetBitsLoop(int num)
{
	unsigned int count = 0;
	int i = 0;
	int mask = 1;
	for(;i < 32; i++)
	{
		if((mask & num)== mask)
		{
			count++;
		}
		mask = mask << 1;		
	}
	return count;
}
int countSetBitsNoLoop(int n)
{
	n = n - ((n >> 1) & 0x55555555);/*0x55555555 = 01010101010101010101010101010101*/
	n = (n & 0x33333333) + ((n >> 2) &0x33333333); /*0x33333333 = 00110011001100110011001100110011*/
	n = (n + (n >> 4)) & 0x0f0f0f0f;/* 0x0f0f0f0f = 1111000011110000111100001111*/
	n = n + (n >> 8);
	n = n + (n >> 16);
   	return n & 0x0000003f; /*0x0000003f = 00111111*/
}
void FloatPrint(float num)
{
	int *n = (int*)&num;
	unsigned i;
	for (i = 1 << 31; i > 0; i = i / 2)
	{
		(*n & i) ? printf("1") : printf("0");
	}
	printf("\n");
}
