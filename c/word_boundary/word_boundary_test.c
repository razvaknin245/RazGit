#include "word_boundary.h"

int main()
{
	void *src = calloc(32,32);
	void *arr2 = calloc(16,16);
	void *dest = calloc(32,32);
	char src2[100] = "RazsFor";
	
	/*src = (void*)(((char*)src)+1);test for check aligned*/
	
	printf("array before memset :%s \n",(char*)src); /* to see the array before my memset*/
	MyMemset(src ,'g', 31);
	printf("array after memset : %s \n",(char*)src); /* to see the array after my memset*/
	
	printf("-------------------------------------------------------\n");
	
	printf("first memcpy src:\n"); 	/* to see the source array before memcpy*/
	printf("%s \n",(char*)src);
	
	printf("first memcpy dest:\n");/* to see the destination array before memcpy*/
	printf("%s \n",(char*)dest);
	
	MyMemcpy(dest,(const void*)src, 31);
	
	printf("after memcpy src:\n"); 
	
	printf("%s \n",(char*)src);/* to see the source array after memcpy*/
	printf("after memcpy dest:\n");
	
	printf("%s \n",(char*)dest);/* to see the destination array after memcpy*/
	
	printf("-------------------------------------------------------\n");
	
	printf("now print array before memmove: \n");
	printf("%s \n",(char*)src2);
	MyMemmove(src2 + 3,src2,strlen(src2)+1);
	printf("now print array after memmove: \n");
	printf("%s \n",(char*)src2);

	printf("-------------------------------------------------------\n");
	free(src);
	free(arr2);
	free(dest);
	return 0;
}
