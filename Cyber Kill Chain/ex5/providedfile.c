#include <stdio.h>

void func(long a, long b) 
{
  void **p = (void**)(&a-1);
  *p = (void *)((char *)(*p)+8);
  return;
  printf("%ld\n", b);
  printf("%ld\n", a);
}

int main() 
{
  int num = 3;
  func(3, 1);
  num = 4;
  printf("num is now %d\n", num);

  return 0;
}
