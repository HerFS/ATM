#include "main.h"

#define MAX_NAME_LEN (22)
#define MIN_NAME_LEN (4)
#define MAX_NUM_LEN (16)
#define MAX_PASSWORD_LEN (6)
#define MAX_USERS (100)
#define BUFFER_SIZE (1024)
#define BUFFER_MONEY (13)
#define MAX_MONEY (1000000000)

#define ENGLISH_LEN (20)
#define KOREAN_LEN (ENGLISH_LEN / 2)

typedef struct Bank
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASSWORD_LEN];
}Account_t;

void Menu();
void LoadAccounts(int *user_count);
int CreateAccount();
void Deposit(int user_count);
void WithDraw(int user_count);
void Remit(int user_count);
void CheckAccount(int user_count);
void EditName(int user_count);
void EditPassword(int user_count);
void EditMenu(int user_count);

Account_t accounts[MAX_USERS];
bool g_Exit_Outer_Loop = false;
int g_user_nums = 0;

enum Menu
{
    e_Create = 1,
    e_Deposit,
    e_WithDraw,
    e_Remit,
    e_CheckInfo
};
