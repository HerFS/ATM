#define _CRT_SECURE_NO_WARNINGS
#include "diary_menu.h"

int menu()
{
    while (1)
    {
        printf("          -메뉴를 선택해주세요-\n");
        draw_menu();
        int choice_menu = move_arrow();
        switch (choice_menu)
        {
        case CHOICE_WRITE:
            system("cls");
            write_diary();
            break;
        case CHOICE_DELETE:
            system("cls");
            delete_diary();
            break;
        case CHOICE_UPDATE:
            system("cls");
            update_diary();
            break;
        case CHOICE_EXIT:
            return 0;
            break;
        default:
            break;
        }
    }
}

int input_key()
{
	char key = getch();

	switch (key)
	{
	case UP:
		return UP;
		break;
	case DOWN:
		return DOWN;
		break;
	case ' ':
		return SUBMIT;
        break;
	default:
		break;
	}
}

int move_arrow() // 메뉴 선택
{
    int x = 13;
    int y = 3;

    while (1)
    {
        int move = input_key();
        switch (move)
        {
        case UP:
        {
            if (y > 3)
            {
                gotoxy(x - 2, y);
                printf(" ");

                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN:
        {
            if (y < 6)
            {
                gotoxy(x - 2, y);
                printf(" ");

                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT:
        {
            return y - 3;
            break;
        }
        default:
            break;
        }
    }
}

void draw_menu()
{
    system("cls");
    printf("----------------------------------------\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|              WRITE DIARY             |\n");
    printf("|              DELETE DIARY            |\n");
    printf("|              UPDATE DIARY            |\n");
    printf("|                  EXIT                |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("----------------------------------------\n");
}
