#include "pointersExc.h"
#include "strHead.h"

int main()
{
  int *p1 = malloc(8);
  int *p2 = malloc(8);
  
  int array[5] = {1,2,3,4,5};
  int secArray[5];
  
  size_t num1 = 8;
  size_t num2 = 9;
  size_t *pnum1 = &num1;
  size_t *pnum2 = &num2;
  
  char str1[10] = {'r','a','z','v','a'};
  char str2[10] = {'r','a','z'};
  
  *p1 = 5;
  *p2 = 10;
  
  
  printf("the first p1 is %d ,the first p2 is %d \n",*p1 ,*p2);
  printf("%p, %p \n",(void*) p1 ,(void *) p2);
  SwapInt(p1,p2);
  printf("%p, %p \n",(void *) &p1 ,(void *) &p2);
  printf("the second p1 is %d , the second p2 is %d\n",*p1 , *p2);
  
  free(p1);
  free(p2);
  Copy_Array(array,5,secArray);
  
  Swap_Size_T(pnum1,pnum2);
  printf("num1 = %lu,num2 = %lu \n",*pnum1 ,*pnum2);
  
  Swap_Pointers_Size_T(&pnum1,&pnum2);
  printf("num1 = %lu,num2 = %lu \n",*pnum1 ,*pnum2);
  assert(pnum1 == &num2);
  assert(pnum2 == &num1);
  
  assert(StrLen(str1)==5);
  assert((StrCmp(str1,str2)) == (1));
  return 0;
}
