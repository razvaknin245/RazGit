#include "bitwise.h"


int main()
{
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	unsigned int arr[4] = {(unsigned int)13,(unsigned int)7,(unsigned int)6,(unsigned int)8};
	num1 = 5;
	num2 = 4;
	printf("%ld \n",Pow2(num1,num2));
	
	num1 = 4;
	printf("%d \n",checkPow(num1,CHOOSEN_CASE));
	
	num1 = 0;
	printf("%d \n",checkPow(num1,CHOOSEN_CASE));
	
	num1 = 16;
	printf("%d \n",checkPow(num1,CHOOSEN_CASE));
	num1 = 15;
	printf("the num is: %d \n after add the num is: %d \n",num1,addOne((int)num1));
	
	threeBitsPrint(arr , 4);
	
	ByteMirrorLoop(2);
	ByteMirrorNoLoop(2);
	printf ("check two n six 0 :%d \n",checkTwoNSix(0));
	printf ("check two n six 2 :%d \n",checkTwoNSix(2));
	printf ("check two n six 3 :%d \n",checkTwoNSix(3));
	printf ("check two n six 32 :%d \n",checkTwoNSix(32));
	printf ("check two n six 34 :%d \n",checkTwoNSix(34));
	printf ("check two n six 35 :%d \n",checkTwoNSix(35));
	printf ("check two n six 255 :%d \n",checkTwoNSix(255));
	printf ("\n");
	
	printf ("check two or six 0 :%d \n",checkTwoOrSix(0));
	printf ("check two or six 2 :%d \n",checkTwoOrSix(2));
	printf ("check two or six 3 :%d \n",checkTwoOrSix(3));
	printf ("check two or six 32 :%d \n",checkTwoOrSix(32));
	printf ("check two or six 34 :%d \n",checkTwoOrSix(34));
	printf ("check two or six 35 :%d \n",checkTwoOrSix(35));
	printf ("check two or six 255 :%d \n",checkTwoOrSix(255));
	printf ("\n");
	
	printf ("16 before swap : %d \n ", 16);
	printf ("16 after swap: %d \n ",SwapThirdFifth(16));
	printf ("4 before swap: %d \n ", 4);
	printf ("4 after swap: % d \n ",SwapThirdFifth(4));
	printf ("6 before swap: %d \n ", 6);
	printf ("6 after swap: : %d \n ",SwapThirdFifth(6));
	printf ("18 before swap: %d \n ", 18);
	printf ("18 after swap: %d \n ",SwapThirdFifth(18));
	
	printf("the closed num that divied by 16  is :%d \n",ClosedDivisibleBySixteen(22));
	
	swapInt(5,7);
	printf ("|Loop|num of bits in -50 that set is %d \n",countSetBitsLoop(-));
	printf ("|NoLoop|num of bits in -5 that set is %d \n",countSetBitsNoLoop(-141));
	FloatPrint(52.654);
	return 0;
}
