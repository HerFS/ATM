#include <stdio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SUBMIT 0

int DrawMenu();
int InputKey();
void DrawAtm();
void DrawInfo();
void DrawExit();
void InitConsole();
void DrawTitle();   
void Gotoxy(int, int);

int InputKey() // 키 입력
{
    char key = getch(); 

    switch (key)
    {
        case UP:
        {
            return UP;
            break;
        }
        case DOWN:
        {
            return DOWN;
            break;
        }
        case LEFT:
        {
            return LEFT;
            break;
        }
        case RIGHT:
        {
            return RIGHT;
            break;
        }
        case ' ':
        {
            return SUBMIT;
        }
        default:
        {
            break;
        }

    }

}


int DrawMenu() // 메뉴 선택
{
    int x = 54;
    int y = 21;

    while (1)
    {
        int n = InputKey();
        switch (n)
        {
        case UP:
        {
            if (y > 21)
            {
                Gotoxy(x - 2, y);
                printf(" ");

                Gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }

        case DOWN:
        {
            if (y < 23)
            {
                Gotoxy(x - 2, y);
                printf(" ");

                Gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }

        case SUBMIT:
        {
            return y - 21;
        }
        default:
            break;
        }
    }
}


void DrawAtm()
{
    system("cls");
}


void DrawInfo()
{
    system("cls");

    printf("\n\n");
    printf(" 사용 방법 : \n");
    printf("스페이스 바를 누르면 메인 화면으로 이동합니다.");

    while (1)
    {
        if (InputKey() == SUBMIT)
        {
            system("cls");
            break;
        }
    }
}


void DrawExit()
{
    system("cls");
    printf("은행을 종료합니다.");
}


void InitConsole()
{
    system("mode con:cols=122 lines=30  | Title B A N K"); // 콘솔 창 크기

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0; // false 또는 0 : 숨기기
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
    // 깜빡이는 커서 지우기
}


void DrawTitle() // 제목
{
    Gotoxy(3, 4);
    printf("                      ■■■■■■         ■■■■       ■■■         ■■   ■■      ■■      ");
    Gotoxy(3, 5);
    printf("                      ■■      ■■    ■■      ■■    ■■■■       ■■   ■■     ■■       ");
    Gotoxy(3, 6);
    printf("                      ■■        ■   ■■        ■■   ■■ ■■      ■■   ■■    ■■       ");
    Gotoxy(3, 7);
    printf("                      ■■        ■   ■■        ■■   ■■  ■■     ■■   ■■  ■■         ");
    Gotoxy(3, 8);
    printf("                      ■■      ■■   ■■        ■■   ■■   ■■    ■■   ■■■■           ");
    Gotoxy(3, 9);
    printf("                      ■■■■■■     ■■■■■■■■   ■■    ■■   ■■   ■■■             ");
    Gotoxy(3, 10);
    printf("                      ■■      ■■   ■■        ■■   ■■     ■■  ■■   ■■■■           ");
    Gotoxy(3, 11);
    printf("                      ■■        ■   ■■        ■■   ■■      ■■ ■■   ■■  ■■         ");
    Gotoxy(3, 12);
    printf("                      ■■        ■   ■■        ■■   ■■       ■■■■   ■■    ■■       ");
    Gotoxy(3, 13);
    printf("                      ■■      ■■   ■■        ■■   ■■         ■■■   ■■      ■■     ");
    Gotoxy(3, 14);
    printf("                      ■■■■■■     ■■        ■■   ■■           ■■   ■■       ■■    ");
    Gotoxy(3, 15);
    printf("                      ─────────────────────────────────────────────────────────────────────────   ");
    Gotoxy(3, 16);
    printf("                                                    환엽합니다!   ");
    Gotoxy(3, 17);
    printf("                                                      고객님!   ");
    Gotoxy(3, 18);
    printf("                                                 좋은하루 되세요♩♪   ");
    Gotoxy(3, 19);
    printf("                      ─────────────────────────────────────────────────────────────────────────   ");
    Gotoxy(52, 21);
    printf("> 은 행 시 작 ");
    Gotoxy(54, 22);
    printf("은 행 정 보 ");
    Gotoxy(54, 23);
    printf("   종  료    ");
}


void Gotoxy(int x, int y) // 좌표
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
