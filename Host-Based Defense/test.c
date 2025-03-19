#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    char *buf = (char*)malloc(20);
    char *buf2 = NULL;
    char *buf3 = NULL;
    char *malic = NULL;

    strcpy(buf, "password");
    strcat(buf,"first");
    puts(buf);

    buf2 = (char*)malloc(20);
    strcpy(buf2, "pa");
    strcat(buf2,"123");
    puts(buf2);

    buf3 = (char*)malloc(20);

    strcpy(buf3, "password");
    strcat(buf3,"raz");
    puts(buf3);
    malic = (char*)malloc(20);
    puts("worked :P");



    return 0;
}
