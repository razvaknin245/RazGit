#include"authenticator.h"
#include"printest.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char username[] = "razsd";
    char password[] =  "passcode";

    char username2[] = "razsd2";
    char password2[] =  "passcode2";

    char username3[] = "admin";
    char password3[] = "adminpass";
    
    char username4[] = "";
    char password4[] = "passcode";
    int flag = 0;
    int all_flag = 0;
    printf("empty result : %d \n",AuthAddUser(username4,password4));
    
    printTest(AuthAddUser(username,password),__LINE__,__FILE__,&flag);
    all_flag += flag;
    printTest(AuthAddUser(username2,password2),__LINE__,__FILE__,&flag);
    all_flag += flag;
    printTest(AuthAddUser(username3,password3)== 0,__LINE__,__FILE__,&flag);
    all_flag += flag;
    printTest(AuthDeleteUser(username),__LINE__,__FILE__,&flag);
    all_flag += flag;
    printTest(AuthDeleteUser(username2),__LINE__,__FILE__,&flag);
    all_flag += flag;
    printTest(AuthAuthenticator(username3,password3),__LINE__,__FILE__,&flag);
    all_flag += flag;
    printTest(!AuthAuthenticator(username3,password2),__LINE__,__FILE__,&flag);
    all_flag += flag;
    if(all_flag == 7)
    {
        print_charizard();
    }
    else if(all_flag < 7)
    {
        print_gengar();
    }
    return 0;
}