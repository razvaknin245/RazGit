#include <stdio.h>
int func(int n)
{
	int result = 1;
	int base = 10;
	for( int i = 0 ; i < n ; i++)
	{
		result = base * result ;
	}
	return result;
}
void swap(int* first , int* second)
{
	int temp = *first ;
	*first = *second ; 
	*second = temp;
} 
int* flip(int *arr,int size)
{
	int save = arr [ 0 ];
	for(int i = 0; i < size - 1; i++)
	{
		arr [ i ] = arr [ i + 1 ];
	}
	arr[ size - 1 ] = save ; 
	return arr;
}
char* HexArr (char* arr)
{
	for (int i = 0; i < 12; i++)
	{
		printf("%02x" ,arr[ i ] );
	}
}
int main ()
{
	char arrHello [ ] = "Hello World!";
	int arrI[4] = {1,2,3,4};
	int size = 12;
	HexArr(arrHello);
	printf("\n");
	printf("%d",(func(5)));
	for(int i = 0; i < 4; i++)
	{
		printf ( "%d" , arrI [i] );
	}
	printf("\n");
	flip(arrI,4);
	for(int i = 0; i < 4; i++)
	{
		printf ( "%d" , arrI [i] );
	}
	int firstM = 5;
	int secondM = 8;
	
	printf ("first is : %d, second is : %d \n",firstM ,secondM);
	swap( &firstM , &secondM );
	printf ("now first is : %d, second is %d:\n ",firstM ,secondM);
	return 0;
}

