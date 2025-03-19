#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <stdlib.h>
#include "authenticator.h"

#define FILE_NAME "users_db.txt"
#define BUFFER 100

#define IS_EXIST 1
#define GET_LINE 2

#define TMP_FILE "tmp.txt"
#define SALT "$1$"
static int CheckIfUserExist(const char *user, int func_called)
{
    char *line = malloc(BUFFER);
    int num_len = 0;
    int i = 0;
    char ptr[BUFFER];
    FILE *fp = fopen(FILE_NAME, "r");
    while (fgets(line, BUFFER, fp))
    {
        ++num_len;
        for(i = 0;line[i] != ':';i++)
        {
            ptr[i] = line[i];
        }
        ptr[i] = '\0';
        if(0 == strcmp(ptr,user))
        {
            if (IS_EXIST == func_called)
            {
                return USER_ADD_EXIST;
            }
            else if (GET_LINE == func_called)
            {
                return num_len;
            }
        }
    }
    free(line);
    fclose(fp);
    return 0;
}

int AuthAddUser(const char *username, const char *password)
{
    char *crypted_pass = NULL;
    char user_to_write[33];
    int exist_flag = 0;
    FILE *fp = fopen(FILE_NAME, "a+");
    if (fp == NULL)
    {
        return ADD_SYS_ERROR;
    }
    if (strlen(username) >= 32 || strlen(password) >= 32)
    {
        return USER_ADD_USER_PASS_LONG;
    }
    if (NULL != strchr(username, ' ') || NULL != strchr(username, '\n') || NULL != strchr(username, ':')||
    NULL != strchr(password, ' ') || NULL != strchr(passsword, '\n') || NULL != strchr(password, ':'))
    {
        return USER_ADD_INVALID_CHAR;
    }
    exist_flag = CheckIfUserExist(username, IS_EXIST);
    if (USER_ADD_EXIST == exist_flag)
    {
        return USER_ADD_EXIST;
    }
    crypted_pass = crypt(password, SALT);

    if (NULL == crypted_pass)
    {
        return ADD_SYS_ERROR;
    }
    strcpy(user_to_write, username);
    strcat(user_to_write, ":");

    if(-1 == fwrite(user_to_write, 1, strlen(user_to_write), fp))
    {
        return ADD_SYS_ERROR;
    }

    strcat(crypted_pass, "\n");
    if(-1 == fwrite(crypted_pass, 1, strlen(crypted_pass), fp))
    {
        return ADD_SYS_ERROR;
    }

    fclose(fp);

    return USER_ADD_SUCCESS;
}
int AuthDeleteUser(const char *username)
{
    FILE *fp_src = fopen(FILE_NAME, "a+");
    FILE *fp_tmp = fopen(TMP_FILE, "a+");
    char buffer_src[BUFFER];
    int line = CheckIfUserExist(username, GET_LINE);
    int counter = 0;
    char *temp_name = TMP_FILE;

    if (NULL == fp_src)
    {
        return USER_DELETE_SYS_ERROR;
    }
    if (NULL == fp_tmp)
    {
        return USER_DELETE_SYS_ERROR;
    }
    if (line == 0)
    {
        return USER_DELETE_NOT_EXIST;
    }
    while (!feof(fp_src))
    {
        strcpy(buffer_src, "\0");
        fgets(buffer_src, BUFFER, fp_src);
        if (!feof(fp_src))
        {
            counter++;
            if (counter != line)
            {
                fprintf(fp_tmp, "%s", buffer_src);
            }
        }
    }
    fclose(fp_src);
    fclose(fp_tmp);
    if(-1 == remove(FILE_NAME))
    {
        return USER_DELETE_SYS_ERROR;
    }
    rename(temp_name, FILE_NAME);

    return USER_ADD_SUCCESS;
}
int AuthAuthenticator(const char *username, const char *password)
{
    FILE *fp = fopen(FILE_NAME, "r");
    int is_user_exist = CheckIfUserExist(username, IS_EXIST);
    int get_user_line = CheckIfUserExist(username, GET_LINE);
    int counter = 0, i = 0;
    char *crypted_pass = NULL;
    char line_content[BUFFER];
    char checking_buff[BUFFER];

    if (NULL == fp)
    {
        return AUTH_SYS_ERROR;
    }

    if (is_user_exist != AUTH_USER_NOT_EXIST)
    {
        return AUTH_USER_NOT_EXIST;
    }
    crypted_pass = crypt(password, SALT);
    strcat(crypted_pass, "\n");

    if (NULL == crypted_pass)
    {
        return AUTH_SYS_ERROR;
    }

    while (!feof(fp))
    {
        strcpy(line_content, "\0");
        fgets(line_content, BUFFER, fp);
        if (!feof(fp))
        {
            counter++;
            if (counter == get_user_line)
            {
                while (line_content[i] != ':')
                {
                    i++;
                }
                if (line_content[i] == ':')
                {
                    i++;
                }
                strncpy(checking_buff, line_content + i, strlen(line_content));
                if (0 == (strcmp(checking_buff, crypted_pass)))
                {
                    return AUTH_SUCESS;
                }
                else
                {
                    return AUTH_NOT_MATCH;
                }
            }
        }
    }
    fclose(fp);
    return AUTH_SYS_ERROR;
}
void print_charizard()
{
    
    printf("                 .\"-,.__\n");
    printf("                 `.     `.  ,\n");
    printf("              .--'  .._,'\"-' `.\n");
    printf("             .    .'         `'\n");
    printf("             `.   /          ,'\n");
    printf("               `  '--.   ,-\"'\n");
    printf("                `\"`   |  \\\n");
    printf("                   -. \\, |\n");
    printf("                    `--Y.'      ___.\n");
    printf("                         \\     L._, \\\n");
    printf("               _.,        `.   <  <\\                _\n");
    printf("             ,' '           `, `.   | \\            ( `\n");
    printf("          ../, `.            `  |    .\\`.           \\ \\_\n");
    printf("         ,' ,..  .           _.,'    ||\\l            )  '\".\n");
    printf("        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n");
    printf("      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n");
    printf("    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n");
    printf("    |  '          ..         `-...-\"  |  `-'      / /        . `.\n");
    printf("    | /           |L__           |    |          / /          `. `.\n");
    printf("   , /            .   .          |    |         / /             ` `\n");
    printf("  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n");
    printf(" / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n");
    printf(".  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n");
    printf("' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n");
    printf("|'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\\n");
    printf("||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n");
    printf("||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n");
    printf("|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n");
    printf("||/            _,-------7 '              . |  `-'    l         /    `||\n");
    printf(". |          ,' .-   ,' ||               | .-.        `.      .'     ||\n");
    printf(" `'        ,'    `\".'    |               |    `.        '. -.'       `'\n");
    printf("          /      ,'      |               |,'    \\-.._,.'/'\n");
    printf("          .     /        .               .       \\    .''\n");
    printf("        .`.    |         `.             /         :_,'.'\n");
    printf("          \\ `...\\   _     ,'-.        .'         /_.-'\n");
    printf("           `-.__ `,  `'   .  _.>----''.  _  __  /\n");
    printf("                .'        /\"'          |  \"'   '_\n");
    printf("               /_|.-'\\ ,\".             '.'`__'-( \\\n");
    printf("                 / ,\"'\"\\,'               `/  `-.|\" mh\n");


    printf("WOWWWWWWW ALL TEST ARE PASSED CHARIZARD IS REALLY HAPPY \n");
}
void print_gengar()
{
        printf(("                 |`._         |\\\n"));
        printf(("                 `   `.  .    | `.    |`.\n"));
        printf(("                  .    `.|`-. |   `-..'  \\           _,.-'\n"));
        printf(("                  '      `-. `.           \\ /|   _,-'   /\n"));
        printf(("              .--..'        `._`           ` |.-'      /\n"));
        printf(("               \\   |                                  /\n"));
        printf(("            ,..'   '                                 /\n"));
        printf(("            `.                                      /\n"));
        printf(("            _`.---                                 /\n"));
        printf(("        _,-'               `.                 ,-  /\"-._\n"));
        printf(("      ,\"                   | `.             ,'|   `    `.\n"));
        printf(("    .'                     |   `.         .'  |    .     `.\n"));
        printf(("  ,'                       '   ()`.     ,'()  '    |       `.\n"));
        printf(("'-.                    |`.  `.....-'    -----' _   |         .\n"));
        printf((" / ,   ________..'     '  `-._              _.'/   |         :\n"));
        printf((" ` '-\"\" _,.--\"'         \\   | `\"+--......-+' //   j `\"--.. , '\n"));
        printf(("    `.'\"    .'           `. |   |     |   / //    .       ` '\n"));
        printf(("      `.   /               `'   |    j   /,.'     '\n"));
        printf(("        \\ /                  `-.|_   |_.-'       /\\\n"));
        printf(("         /                        `\"\"          .'  \\\n"));
        printf(("        j                                           .\n"));
        printf(("        |                                 _,        |\n"));
        printf(("        |             ,^._            _.-\"          '\n"));
        printf(("        |          _.'    `'\"\"`----`\"'   `._       '\n"));
        printf(("        j__     _,'                         `-.'-.\"`\n"));
        printf(("          ',-.,' mh\n"));
        printf("\n");
        printf("\n");
        printf("\n");
        printf(" OH NO ,TESTS NOT PASSED FIX IT OR GENGAR COME \n ");
}