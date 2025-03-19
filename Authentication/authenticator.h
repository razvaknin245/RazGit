#ifndef __AUTHENTICATOR_H__ILRD__CR3_
#define __AUTHENTICATOR_H__ILRD__CR3_

#define USER_ADD_SUCCESS 0
#define USER_ADD_EXIST 1
#define ADD_SYS_ERROR 2
#define USER_ADD_INVALID_CHAR 3
#define USER_ADD_USER_PASS_LONG 4

#define USER_DELETE_SUCCESS 0
#define USER_DELETE_NOT_EXIST 1
#define USER_DELETE_SYS_ERROR 2

#define AUTH_SUCESS 0
#define AUTH_USER_NOT_EXIST 1
#define AUTH_SYS_ERROR 2
#define AUTH_NOT_MATCH 3
/*
database default path:
/users_db

pwd_strength default function:
{
	return 0;
}

password and username max length:
32 - including null terminator

password and username invalid chars:
-	' ' (space)
-	'\n' (new line)
-	':'
*/



/*
Add user and password to the authenticator credentials database
return value:
	0 - user added successfully
	1 - user already exists, cant add user
	2 - some kind of system error occured - like memory error / file error
	3 - the user tried to enter invalid characters into username/password.
		The invalid characters are specified in the global invalid characters array
	4 - username or password is too long
	~~~ADVANCED~~~
	 **5 - MAX_INT** - reserved for user's pwd_strength function 
	~~~ADVANCED~~~
*/
int AuthAddUser(const char *username, const char *password);


/*
Delete user from the authenticator credentials database
return value:
	0 - user deleted successfully
	1 - user doesn't exist, cant delete user
	2 - some kind of system error occured - like memory error / file error
*/
int AuthDeleteUser(const char *username);


/*
Authenticate user matching username and password hash with the authenticator credentials database
return value:
	0 - user and password matching, auth successful
	1 - user doesn't exist, cant authenticate user
	2 - some kind of system error occured - like memory error / file error
	3 - user exists, but password is wrong
*/
int AuthAuthenticator(const char *username, const char *password);




/*~~~~~~~~~~~~~~~~~~ ADVANCED ~~~~~~~~~~~~~~~~~~*/ 


typedef int (*pwd_strength)(const char *password);


/*
Configure the authenticators settings
file_path - database-file path
pwd_config_func - the function describing password rules
return value:
	0 - success
	1 - some kind of system error occured - like memory error / file error 
*/
int AuthConfigAuthenticator(const char *file_path, pwd_strength pwd_config_func);


/*~~~~~~~~~~~~~~~~~~ ADVANCED ~~~~~~~~~~~~~~~~~~*/ 

void print_charizard();

void print_gengar();
#endif /*__AUTHENTICATOR_H__ILRD__CR3_*/