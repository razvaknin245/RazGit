#include "logger.h"
/*
reviewd by yahav

*/
struct function_command strctarr[BUFFER_SIZE];


STATUS AppendFile(char *f_name,char *data_to_file)
{
	FILE *f = fopen(f_name,"a+");
	if (f == NULL) 
	{
    		printf("Failed:( ");
   	 	return FAILED;
   	}
	fputs(data_to_file,f);
	fputc('\n',f);
	fseek(f, 0, SEEK_END);
	fclose(f);
	return SUCCESS;
}

int CompFunc(char *str,char *str2)
{
	if(0 == (strcmp(str,"append")))
	{
		return 0;
	}
	return strcmp(str2,str);
}
STATUS OperFuncRemove(char *fname)
{
	if(SUCCESS == remove(fname))
	{
		printf("FILE Removed \n");
		return SUCCESS;
	}
	else
	{
		printf("SORRY :( unable to delete file \n");
		return FAILED;
	}
	
}
int CompStartAdd(char * str,char *str2)
{
	return strncmp(str,str2,1);
}
STATUS OperFuncCount(char* f_name)
{
	int counter = 0;
	char c = 0;
	FILE *f = fopen(f_name,"a+");
	if (f == NULL) 
	{
    		printf("Failed:( ");
   	 	return FAILED;
   	}
	fseek(f,0,SEEK_SET);
	while(c != EOF)
	{	
		c = getc(f);
		if(c == '\n')
		{
			counter++;
		}
	}
	printf("number of lines is %d \n",counter);
	fclose(f);
	return SUCCESS;
}
STATUS OperFuncExit()
{
	exit(0);
	return SUCCESS;
}

STATUS OperFuncAdd(char *f_name,char* data)
{
	FILE *f = fopen(f_name,"r+");
	char* buffer;
	char c = 0;
	int counter = 0;
	int i = 0;
	
	if (f == NULL) 
	{
    		printf("Failed:( \n");
   	 	return FAILED;
   	}
   	
	while(c != EOF)
	{
		c = getc(f);
		counter++;
	}
	
	fseek(f , 0, SEEK_SET);
	buffer = malloc(sizeof(char) * (counter));
	c = getc(f);
	
	while(c != EOF)
	{
		buffer[i] = c;
		i++;
		c = getc(f);
	}
	
	buffer[counter] = 0;
	fseek(f, 0, SEEK_SET);
	c = 0;
	i = 0;
	
   	data++;
	
	fputs(data,f);
	fputc('\n',f);
	fseek(f, strlen(data), SEEK_SET);
	fputs(buffer,f);
	fclose(f);
	free(buffer);
	return SUCCESS;
}

void InitStructArr(struct function_command strft[])
{
	strft[0].str_ph2 = "-remove\n";
	strft[0].comp_ptr = CompFunc;
	strft[0].oper_ptr = OperFuncRemove;
	
	strft[1].str_ph2 = "-count\n";
	strft[1].comp_ptr = CompFunc;
	strft[1].oper_ptr = OperFuncCount;
	
	strft[2].str_ph2 = "-exit\n";
	strft[2].comp_ptr = CompFunc;
	strft[2].oper_ptr = OperFuncExit;
	
	strft[3].str_ph2 = "<";
	strft[3].comp_ptr = CompStartAdd;
	strft[3].oper_ptr = OperFuncAdd;
	
	strft[4].str_ph2 = "append";
	strft[4].comp_ptr = CompFunc;
	strft[4].oper_ptr = AppendFile;	
}

int main(int argc,char* argv[])
{
	char *file_name;
	struct function_command func_arr[BUFFER_SIZE];
	char data[BUFFER_SIZE];
	int i = 0;
	
	if(NULL != argv)
	{
		file_name = argv[1];
	}
	
	InitStructArr(func_arr);
	
	while(1)
	{
		fgets(data, MAX_CHAR, stdin);
		for(i=0; i < NUM_FUNC; i++)
		{
			if(SUCCESS == func_arr[i].comp_ptr(func_arr[i].str_ph2,data))
			{
				func_arr[i].oper_ptr(file_name,data);
				break;
			}
		}
	}
	return 0;
}



