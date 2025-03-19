#include "structs.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void printInts(void* t_int)
{

	printf("%d \n",*(int*)&t_int);
	
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void printFloats(void* t_float)
{
	printf("%f \n", *(float*)&t_float);
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void printStrings(void *t_string)
{
	printf("%s \n",(char*)t_string);
}

vals initInts(int d_int)
{
	vals intStruct;
	intStruct.print = &printInts;
	intStruct.add = &AddInts;
	intStruct.clean = &cleanInt;
	*(int*)&intStruct.data = d_int;
	return intStruct;
}
vals initFloats(float d_floats)
{
	vals floatStruct;
	floatStruct.print = &printFloats;
	floatStruct.add = &AddFloats;
	floatStruct.clean = &cleanFloat;
	*(float*)&floatStruct.data = d_floats;
	return floatStruct;
}
vals initStrings(char *d_string)
{
	vals stringStruct;
	stringStruct.print = &printStrings;
	stringStruct.add = &AddStrings;
	stringStruct.clean = &cleanString;
	stringStruct.data = malloc(strlen(d_string) + NULLTER);
	if(NULL == stringStruct.data)
	{
		stringStruct.print = NULL;
		stringStruct.add = NULL;
		stringStruct.clean = NULL;
		return(stringStruct);
	}
	strcpy(stringStruct.data , d_string);
	
	return stringStruct;
}

/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void AddInts(void *t_int , int n)
{
	*(int*)t_int += n;
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void AddFloats(void* t_float, int n)
{
	*(float*)t_float += n;
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void AddStrings(char** t_string,int n)
{
	char saveInt[12];
	size_t size ;
	sprintf(saveInt,"%d",n);
	size = strlen(*t_string) + strlen(saveInt) + NULLTER;
 	*t_string = realloc(*t_string,size);
 	strcat(*t_string,saveInt);
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void cleanInt()
{
	return;
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void cleanFloat()
{
	return;
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void cleanString(void* str)
{
	free((char*)str);
}
/*reviewd by yahav 
  date: 27.11.2022 10:40*/




