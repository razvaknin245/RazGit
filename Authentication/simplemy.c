#include<stdio.h>
#include"authenticator.h"

int main()
{
    int verified = 0;

    verified = AuthAuthenticator("admin","adminpass");

    if(0 == verified)
    {
        printf("verified :) \n");
    }
    else
    {
        printf("not verified :( \n");
    }
}
