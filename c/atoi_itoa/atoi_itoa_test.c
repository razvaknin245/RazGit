#include "atoi_itoa.h"
#include "../test/printest.h"
int main()
{
	
	char *array1= "hello";
  	char *array2="hey";
  	char *array3="bye";
  	int size1 = 5;
  	int size2 = 3;
  	int size3 = 3;
  	
  	
  	char str[12];
  	char str2[12];
  	char str3[3];
  	char str4[2];
  	char str5[2];
  	
  	char strtoi[12];
  	char strtoi2[12];
  	char strtoi3[3];
  	char strtoi4[2];
  	char strtoi5[2];
  	
  	int a = 0;
  	Cmp3Str(array1,array2,array3,size1,size2,size3);
  	
  	printTest(strcmp(ItoA(INT_MAX,str,10),"2147483647"),__LINE__,__FILE__);
  	printTest(strcmp(ItoA(-2147483647,str2,10),"-2147483647"),__LINE__,__FILE__);
  	printTest(strcmp(ItoA(101,str3,10),"101"),__LINE__,__FILE__);
  	printTest(strcmp(ItoA(0,str4,10),"0"),__LINE__,__FILE__);
  	printTest(strcmp(ItoA(1,str5,10),"0"),__LINE__,__FILE__);
  	printTest(strcmp(ItoA(-5,str5,2),"-101"),__LINE__,__FILE__);
  	printf("------------------------------------------------------------------ \n");
  	
  	ItoA(INT_MAX,strtoi,10);
  	ItoA(INT_MIN,strtoi2,10);
  	ItoA(101,strtoi3,10);
  	ItoA(0,strtoi4,10);
  	ItoA(0,strtoi5,10);
  	
  	printTest(compareInt(AtoI(strtoi,10),INT_MAX),__LINE__,__FILE__);
  	printTest(compareInt(AtoI(strtoi2,10),INT_MIN),__LINE__,__FILE__);
  	printTest(compareInt(AtoI(strtoi3,10),101),__LINE__,__FILE__);
  	printTest(compareInt(AtoI(strtoi4,10),0),__LINE__,__FILE__);
  	printTest(compareInt(AtoI(strtoi5,10),1),__LINE__,__FILE__);
  	printf("------------------------------------------------------------------ \n");
  	compareToOriginal("252");
  	a = checklittle();
  	printTest(compareInt(0,a),__LINE__,__FILE__);
	return 0;
}
