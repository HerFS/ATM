#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

int AccountMenu();

int AccountMenu()
{
	int account_menu;

	printf("1. 계좌 생성\n");
	printf("2. 계좌 입금\n");

	scanf("%d", &account_menu);

	switch (account_menu)
	{
	case 1:
	{
		CreateAccount();
		break;
	}
	case 2:
	{
		Deposit();
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		break;
	}
	case 5:
	{
		break;
	}
	default:
		break;
	}

	system("cls");

	return account_menu;
}
