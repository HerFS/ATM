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

Account_t accounts[MAX_USERS];
int user_nums = 0;
