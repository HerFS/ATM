#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

#define MAX_NAME_LEN (22)
#define MIN_NAME_LEN (4)
#define MAX_NUM_LEN (16)
#define MAX_PASSWORD_LEN (6)
#define MAX_USERS (100)
#define BUFFER_SIZE (1024)

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
int user_nums = 0;

void LoadAccounts()
{
    FILE* accounts_txt = fopen("Accounts_Info.txt", "a+");

    char buffer[BUFFER_SIZE];

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        assert(0);
        exit(1);
    }

    while (!feof(accounts_txt))
    {
        fgets(buffer, BUFFER_SIZE, accounts_txt);
        sscanf(buffer, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s", accounts[user_nums].name, accounts[user_nums].num, &accounts[user_nums].money, accounts[user_nums].password);
        user_nums++;
    }

    fclose(accounts_txt);
}

void CreateAccount()
{
    if (user_nums < MAX_USERS)
    {
        return 0;
    }
    srand(time(NULL));
    FILE *accounts_txt = fopen("Accounts_Info.txt", "r+");

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        assert(0);
        exit(1);
    }

    accounts[user_nums].money = 0;

    accounts[user_nums].num[0] = rand() % 9 + '1';
    for (int i = 1; i < 14; i++)
    {
        accounts[user_nums].num[i] = rand() % 10 + '0';
    }
    accounts[user_nums].num[14] = '\0';


    char input_name[MAX_NAME_LEN];

    printf("계좌번호에 사용할 이름을 입력하세요.\n(한글 %d자, 영문 %d자 이내)\n>>", MAX_NAME_LEN - 12, MAX_NAME_LEN - 2);
    while (1)
    {
        fgets(input_name, MAX_NAME_LEN, stdin);
        rewind(stdin);
        sscanf(input_name, "%s", accounts[user_nums].name);
        int name_len = strlen(accounts[user_nums].name) + 2;
        if (name_len > MIN_NAME_LEN  && name_len < MAX_NAME_LEN)
        {
            break;
        }
        else if (name_len < MIN_NAME_LEN)
        {
            printf("최소 한글 %d글자, 영문 %d글자 이상이어야 합니다.\n 다시 입력해주세요.\n>>", MIN_NAME_LEN - 2, MIN_NAME_LEN);
        }
        else
        {
            printf("한글 %d자, 영문 %d자 이내이어야 합니다.\n 다시 입력해주세요.\n>>", MAX_NAME_LEN - 12, MAX_NAME_LEN - 2);
        }
    }

    char input_password[MAX_PASSWORD_LEN];

    printf("비밀번호 %d자리를 입력하세요\n>>", MAX_PASSWORD_LEN - 2);
    while (1)
    {
        fgets(input_password, MAX_PASSWORD_LEN, stdin);
        rewind(stdin);
        sscanf(input_password, "%s", accounts[user_nums].password);
        if (strlen(accounts[user_nums].password) + 2 == MAX_PASSWORD_LEN)
        {
            break;
        }
        else
        {
            printf("비밀번호 %d자리가 아닙니다.\n 다시 입력해주세요.\n>>", MAX_PASSWORD_LEN - 2);
        }
    }
    fprintf(accounts_txt, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[user_nums].name, accounts[user_nums].num, accounts[user_nums].money, accounts[user_nums].password);
    printf("계좌생성이 완료되었습니다.\n");
    printf("이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[user_nums].name, accounts[user_nums].num, accounts[user_nums].money, accounts[user_nums].password);
    fclose(accounts_txt);
}
