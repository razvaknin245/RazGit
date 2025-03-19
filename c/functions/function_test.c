#include "function.h"

int main()
{
	unsigned c;
	c = 1;
	sc_key_Check(c);
	initLut(256);
	while(c)
	{
		c = getchar();
		system("stty -icanon -echo");
		fp_arr[c]();		
	}
	system("stty icanon echo");
	return 0;
} 
