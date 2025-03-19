#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#define MAX2(a,b) a>b ? a:b

#define MAX3(a, b, c) MAX2(a,MAX2(b,c))

#define SIZEOF_VAR(var) (char *)(&var+1) - (char *)(&var)

#define SIZEOF_TYPE(type) ((char *)(((type *)0) + 1) - (char *)(((type *)0)))

#define NULLTER 1
typedef struct vals_t
{
	void *data;
	void (*print)(void*);/*to restore each print func*/
	void (*add)();/*to restore add func*/
	void (*clean)();/*to restore clean func*/
	
}vals;


/*
Desc:
Arguments:
Date:
Status:
Reviewer:	
*/
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
extern struct vals *my_arr;

/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void printInts(void* t_int);
void printFloats(void* t_float);
void printStrings(void* t_string);

vals initInts(int d_int);
vals initFloats(float d_floats);
vals initStrings(char *d_string);
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void AddInts(void* t_int, int n);
void AddFloats(void* t_float,int n);
void AddStrings(char** t_string,int n);
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
void cleanInt();
void cleanFloat();
void cleanString(void* str);
/*reviewd by yahav 
  date: 27.11.2022 10:40*/
#endif
