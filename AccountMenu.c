void AccountMenu()
{
    int choice_menu = 0;
    int user_count = 0;
    LoadAccounts(&user_count);

    printf("1. 생성\n");
    printf("2. 입금\n");
    printf("3. 출금\n");
    printf("4. 송금\n");
    printf("5. 정보 확인\n>>");

    scanf("%d", &choice_menu);

    switch (choice_menu)
    {
    case e_Create:
        CreateAccount();        
        break;
    case e_Deposit:
        Deposit(user_count);
        break;
    case e_WithDraw:
        WithDraw(user_count);
        break;
    case e_Remit:
        Remit(user_count);
        break;
    case e_CheckInfo:
        CheckAccount(user_count);
        EditMenu(user_count);
        break;
    default:
        break;
    }
}
