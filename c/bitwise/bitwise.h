#ifndef BIT_H
#define BIT_H 

#include<stdio.h>
#include<stdlib.h>

#define CHOOSEN_CASE 2


long Pow2(unsigned int x, unsigned int y);

int checkPow(unsigned int n, int select);

int addOne(int x);

void threeBitsPrint(unsigned int* arr,int size);

void ByteMirrorLoop(unsigned char in);

void ByteMirrorNoLoop(unsigned char in);

int checkTwoNSix(unsigned char num);

int checkTwoOrSix(unsigned char num);

unsigned char SwapThirdFifth(unsigned char num);

unsigned int ClosedDivisibleBySixteen(unsigned int num);

void swapInt(int num1,int num2);

int countSetBitsLoop(int num);

int countSetBitsNoLoop(int num);

void FloatPrint(float num);

#endif

