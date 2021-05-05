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
