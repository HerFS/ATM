int main()
{
    InitConsole();

    while (1)
    {
        DrawTitle();
        int menu = DrawMenu();
        system("cls");
        switch (menu)
        {
        case 0:
        {
            AccountMenu();
            break;
        }
        case 1:
        {
            DrawInfo();
            break;
        }
        case 2:
        {
            DrawExit();
            return 0;
        }
        default:
        {
            break;
        }
        }
    }
    return 0;
}
