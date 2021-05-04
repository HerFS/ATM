#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LEN (22)
#define MIN_NAME_LEN (4)
#define MAX_NUM_LEN (15)
#define MAX_PASSWORD_LEN (6)
#define MAX_USERS (100)
#define MAX_ACCOUNTS_INFO (1024)

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct Bank
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASSWORD_LEN];
}Account_t;

void CreateAccount();
void LoadAccounts();

Account_t accounts[MAX_USERS];
int users_index = 0;

int main()
{
    LoadAccounts();
    CreateAccount();
    return 0;
}

void LoadAccounts()
{
    FILE* accounts_txt = fopen("Accounts_Info.txt", "a+");

    char users_info[MAX_ACCOUNTS_INFO];

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        exit(1);
    }

    while (!feof(accounts_txt))
    {
        fgets(users_info, MAX_ACCOUNTS_INFO, accounts_txt);
        sscanf(users_info, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s", accounts[users_index].name, accounts[users_index].num, &accounts[users_index].money, accounts[users_index].password);
        users_index++;
    }

    fclose(accounts_txt);
}

void CreateAccount()
{
    srand(time(NULL));
    FILE *accounts_txt = fopen("Accounts_Info.txt", "r+");

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        exit(1);
    }

    accounts[users_index].money = 0;

    accounts[users_index].num[0] = rand() % 9 + '1';
    for (int i = 1; i < 14; i++)
    {
        accounts[users_index].num[i] = rand() % 10 + '0';
    }
    accounts[users_index].num[14] = '\0';


    char input_name[MAX_NAME_LEN];

    printf("계좌번호에 사용할 이름을 입력하세요.\n(한글 10자, 영문 20자 이내)\n>>");
    while (1)
    {
        fgets(input_name, MAX_NAME_LEN, stdin);
        rewind(stdin);
        sscanf(input_name, "%s", accounts[users_index].name);
        int users_name_len = strlen(accounts[users_index].name) + 1;
        if (MIN_NAME_LEN < users_name_len && users_name_len < MAX_NAME_LEN)
        {
            break;
        }
        else if (users_name_len < MIN_NAME_LEN)
        {
            printf("최소 한글 2글자, 영문 4글자 이상이어야 합니다.\n 다시 입력해주세요.\n>>");
        }
        else
        {
            printf("한글 10자, 영문 20자 이내이어야 합니다.\n 다시 입력해주세요.\n>>");
        }
    }

    char input_password[MAX_PASSWORD_LEN];

    printf("비밀번호 4자리를 입력하세요\n>>");
    while (1)
    {
        fgets(input_password, MAX_PASSWORD_LEN, stdin);
        rewind(stdin);
        sscanf(input_password, "%s", accounts[users_index].password);
        if (strlen(accounts[users_index].password) + 2 == MAX_PASSWORD_LEN)
        {
            break;
        }
        else
        {
            printf("비밀번호 4자리가 아닙니다.\n 다시 입력해주세요.\n>>");
        }
    }
    fprintf(accounts_txt, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);
    printf("계좌생성이 완료되었습니다.\n");
    printf("이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);
    fclose(accounts_txt);
}
