#include <stdio.h>
#include <string.h>

int IsAllowedUser(char *user)
{
	return 0;
}
void PrivilegedAction()
{
	printf("hacked \n");
}
int main () 
{
    char username[8];
    int allow = 0;

    printf("Enter your username, please: ");
    gets(username);

    if (IsAllowedUser(username)) {
        allow = 1;
    }

    if (allow) {
        PrivilegedAction();
    }

    return 0;
}
