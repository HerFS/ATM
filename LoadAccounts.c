#include "main.h"

void LoadAccounts();

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
    user_nums -= 1;
    fclose(accounts_txt);
}
