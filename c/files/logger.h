#ifndef FILES_H
#define FILES_H 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1000

#define MAX_CHAR 50

#define NUM_FUNC 5

typedef enum functions_log{SUCCESS = 0 ,FAILED = -1} STATUS;

struct function_command 
{
	char *str_ph2;
	int (*comp_ptr)();
	STATUS (*oper_ptr)();
};
struct print_me
{
	int x;
	void (*foo_ptr)();
};
extern struct function_command function_array[BUFFER_SIZE];

extern struct print_me str_arr[10];

int CompStartAdd(char * str,char *str2);

int CompAppend();

int CompFunc(char *str , char *str2);

STATUS OperFuncRemove(char *fname);

STATUS OperFuncCount(char* f_name);

STATUS OperFuncExit();

STATUS OperFuncAdd(char *data,char* f_name);

void InitStructArr(struct function_command strft[]);

STATUS AppendFile(char *f_name,char *data_to_file);


void give_val(struct print_me arr[]);

void print_func(int x);

#endif
