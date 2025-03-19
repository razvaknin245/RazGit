#include <string.h>
#include "string.h"
int main()
{

	char source[]="BC";
	char check[100]="ABCD";
	char checkDUp[100];
	printf("teststrcmp: %d \n",StrCasecmp(source,check));
	/*char dst[10];
	char * firstAddress;
	char * saver ;
	assert(StrCpy(dst,source)); check if str copied to the dst
	assert(StrNcpy(dst,source,3)); check if str copied to the dst
	printf("%ld \n",StrLen(source)); /check if length is right
	printf("%d \n",StrCmp(source,check)); 
	printf("%s \n",source);
	printf("%s \n",check);
	printf("%d \n",StrCasecmp(source,check));
	printf("%s \n",source);
	printf("%s \n",check);
	
	firstAddress = check;
	saver = StrChr(source,'a');
	printf("the a address : %p, the check address : %p \n",(void *)saver,(void*) firstAddress);
	printf("%d \n",StrCasecmp(source,check));
	printf("%s\n",source);
	printf("%s\n",check);
	printf("%s\n",StrDup(check));
	printf("%s\n",StrNcat(check,source,3));
	
	StrCpy(source,check);
	printf("%s \n",source);
	printf("%s \n",check);
	
	printf("addres in src : %p \n",(void *)source);
	printf("adress the the sub start : %p \n",(void *)(StrStr(source,check)));
 	*/
 	printf("addres in src : %p \n",(void *)check);
 	printf("MY adress the the sub start : %p \n",(void *)(StrStr(check,source)));
 	printf("Them adress the the sub start : %p \n",(void*)(strstr(check,source)));
	
 	printf("my : %ld \n",StrSpn(source,check));
	printf("them : %ld \n",strspn(source,check));
	if(StrPali("kosok") == 0)
	{
	 printf("Worked \n");
	}
	if(StrPali("razzar") != 0)
	{
	 printf("Not Worked \n");
	}
	return 0;
}
