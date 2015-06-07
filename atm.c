/*************************************************************************
> File Name: atm.c
> Author: AnSwEr
> Mail: 1045837697@qq.com
> Created Time: 2015年06月07日 星期日 14时23分45秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"atm.h"

static i = 0;

void cls()
{
    printf("Please wait...\n");
    sleep(3);
    system("clear");//清屏
}

void inquiry()
{
    printf("%s,your account balance is $%7.2f\n",info[i].name,info[i].money);
    cls();
    menu();
}

void withdrawals()
{
    float m;
    printf("Please input the amount of money:$");
    scanf("%f",&m);
    while(getchar() != '\n')
    continue;
    if(m>info[i].money)
    printf("Your account balance is not enough.");
    else
    {
        info[i].money-=m;
        printf("Transaction completed.");
    }
    cls();
    menu();
}

void depoist()
{
    float m;
    printf("Please input the amount of money:$");
    scanf("%f",&m);
    while(getchar() != '\n')
    continue;
    if(m>10000 && m<0)
    printf("Usage:The range of depoist is $0~$10000");
    else
    {
        info[i].money+=m;
        printf("You have been deposited $%7.2f\n",m);
    }
    cls();
    menu();
}

void out()
{
    printf("%s,Please get your card back.\n",info[i].name);
    cls();
    main();
}

void menu()
{
    int c;
    printf("**********Hello %s**************\n",info[i].name);
    printf("**\tChoice:\n");
    printf("**\tBalance inquiries----1\n");
    printf("**\tWithdrawals----------2\n");    
    printf("**\tDepoist--------------3\n");    
    printf("**\tExit-----------------4\n");
    printf("**********Hello %s**************\n",info[i].name);
    while(1)
    {
        printf("\nPlease input your choice: ");
        scanf("%d",&c);
        while(getchar()!= '\n')//吃掉回车
        continue;
        switch(c)
        {
            case 1:
            inquiry();
            break;
            case 2:
            withdrawals();
            break;
            case 3:
            depoist();
            break;
            case 4:
            out();
            break;
            default:
            printf("Warning:illegal operation!");
            break;
        } 
    }
}

int login()
{
    int account;
    int password;
    int trytimes=0;

    printf("\nPlease input your account: ");
    scanf("%d",&account);
    while(getchar()!= '\n')//吃掉回车
    continue;
    for(i=0;i<10;i++)
    {
        if(account==info[i].account)
        {
            printf("Please input your password: ");
            for(trytimes=0;trytimes<3;trytimes++)
            {
                scanf("%d",&password);
                while(getchar()!= '\n')//吃掉回车
                continue;
                if(password==info[i].password)
                {
                    printf("Login successfully!\n");
                    return 1;
                }
                else
                {
                    if(trytimes==2)
                    {
                        printf("Sorry,you have no chances\n");
                        return 0;
                    }
                    printf("Password is wrong!You only have %d chances!\n\n",2-trytimes);
                    printf("Please retry to input the password:");
                }

            }
        }
    }
    printf("Sorry,your account is not accessable!\n");
    return 0;
}

    int main()
    {
        start:
        printf("\n************Welcome to ATM**************\n");
        printf("****************************************\n");
        if(login() == 1)
        {
            cls();
            menu();
        }
        else
        {
            cls();
            goto start;
        }
    }
