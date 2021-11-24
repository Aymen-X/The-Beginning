#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int accountID = 0;

//Functions Prototypes
void displayMenuOptions();
void accountCreationOption();
void singleAccountCreation();
void multAccountCreation();
void accountOperationsOption();
void withdrawOption();
void depositOption();
void accountDisplayOptions();
void ascendingOrder();
void descendingOrder();
void ascendingOrderMin();
void descendingOrderMin();
void searchCIN();
void applyLoyaltyBonus();

//Account Struct
struct account_details
{
    char account_CIN[20];
    char account_FirstName[20];
    char account_LastName[30];
    float account_Balance;
}; struct account_details Account[100];


int main()
{
    printf("This app serves the purpose of managing clients' bank accounts. Bank Account Management (BAM!)\n\n");
    printf("Operate the menu below using numbers only\n\n");
    printf("The Menu: \n\n");
    displayMenuOptions();
}

//The Display Menu
void displayMenuOptions()
{
    printf("1. Account Creation\n");
    printf("2. Account Operations\n");
    printf("3. Display Options\n");
    printf("4. Apply loyalty bonus\n");
    printf("5. Exit the application\n");


        int menuOption;
        scanf("%d", &menuOption);

            switch (menuOption)
                {
                case 1: accountCreationOption();
                break;

                case 2: accountOperationsOption();
                    break;

                case 3: accountDisplayOptions();
                    break;

                case 4: applyLoyaltyBonus();
                    break;

                case 5: exit(0);
                    break;
                }
                getch();

}
//1-Account Creation options:
void accountCreationOption()
{
    printf("\t1. Single Account Creation\n");
    printf("\t2. Multiple Account Creation\n");

        int menuOption;
        menuOption = 0;
        scanf(" %d", &menuOption);
            switch (menuOption)
                {
                case 1: singleAccountCreation();
                    break;

                case 2: multAccountCreation();
                    break;
                }
}

    //Single account creation option
void singleAccountCreation()
{
    printf("\nEnter your CIN: ");
    scanf("%s", Account[accountID].account_CIN);
    printf("\nEnter your First Name: ");
    scanf("%s", Account[accountID].account_FirstName);
    printf("\nEnter your Last Name: ");
    scanf("%s", Account[accountID].account_LastName);
    printf("\Your account with the CIN #%s has been created successfully! \n\n", Account[accountID].account_CIN);
    ++accountID;
    displayMenuOptions();
}

    //Multiple account creation option
void multAccountCreation()
{
    int creationAmount;
    printf("Enter the number of accounts you wish to create: ");
    scanf("%d", &creationAmount);

    struct account_details account[creationAmount];

        for (int i = 0; i < creationAmount; i++)
        {
            printf("\nEnter your CIN: ");
            scanf("%s", Account[accountID].account_CIN);
            printf("\nEnter your First Name: ");
            scanf("%s", Account[accountID].account_FirstName);
            printf("\nEnter your Last Name: ");
            scanf("%s", Account[accountID].account_LastName);
            printf("\nYour account with the CIN #%s has been created successfully! \n\n", Account[accountID].account_CIN);
            accountID++;
        }
        displayMenuOptions();
}

//Account operations option
 void accountOperationsOption()
{
    printf("\t1. Withdraw\n");
    printf("\t2. Deposit\n");

    int menuOption;
        menuOption = 0;
        scanf(" %d", &menuOption);
            switch (menuOption)
                {
                case 1: withdrawOption();
                    break;

                case 2: depositOption();
                    break;
                }
}

    //Withdraw Option
void withdrawOption()
{
    char accountNo[20];
    int moneyWithdrawal;

    printf("\nEnter the account CIN that you wish to withdraw from: \n");
    scanf("%s", accountNo);

    for (int i = 0; i < accountID; i++)
    {
        if (stricmp(accountNo, Account[i].account_CIN) == 0)
        {
            printf("\nCurrent balance of the account #%s is: %.2f\n", accountNo, Account[i].account_Balance);
            printf("\nEnter the amount you wish to withdraw: ");
            scanf("%d",&moneyWithdrawal);

            Account[i].account_Balance -=moneyWithdrawal;
            printf("\nThe New balance for account #%s is: %.2f \n\n", accountNo, Account[i].account_Balance);
        }
    }

    displayMenuOptions();
}

    //Deposit Option
void depositOption()
{
    char accountNo[20];
    int moneyDeposit;

    printf("\nEnter the account CIN that you wish to deposit to: \n");
    scanf("%s", accountNo);
    for (int i = 0; i < accountID; i++)
    {
        if (stricmp(accountNo, Account[i].account_CIN) == 0)
        {
            printf("\nCurrent balance of the account #%s is: %.2f\n", accountNo, Account[i].account_Balance);
            printf("\nEnter the amount you wish to deposit: ");
            scanf("%d",&moneyDeposit);

            Account[i].account_Balance += moneyDeposit;
            printf("\nThe New balance for account #%s is: %.2f \n\n", accountNo, Account[i].account_Balance);
        }
    }

    displayMenuOptions();
}

//Display options
 void accountDisplayOptions()
{
    printf("\t1. Ascending\n");
    printf("\t2. Descending\n");
    printf("\t3. Ascending (Superior to an X amount only)\n");
    printf("\t4. Descending (Superior to an X amount only)\n");
    printf("\t5. Search by CIN\n");

    int menuOption;
        menuOption = 0;
        scanf(" %d", &menuOption);
            switch (menuOption)
                {
                case 1: ascendingOrder();
                    break;

                case 2: descendingOrder();
                    break;

                case 3: ascendingOrderMin();
                    break;

                case 4: descendingOrderMin();
                    break;
                case 5: searchCIN();
                    break;
                }
}

    //Ascending Order
void ascendingOrder()
{
    int i,j,minimum;
    struct account_details temp_value;

    for(i=0;i<accountID;i++)
        {
            for(j=i+1;j<accountID;j++)
            {
                if(Account[i].account_Balance>Account[j].account_Balance)
                {
                temp_value=Account[i];
                Account[i]=Account[j];
                Account[j]=temp_value;
                }
            }

        }

    printf("\n Ascending order display: \n");
    for(i=0;i<accountID;i++)
    {
    printf("Account #%s \n", Account[i].account_CIN);
    printf("\tFirst Name: #%s\n", Account[i].account_FirstName);
    printf("\tLast Name: #%s\n", Account[i].account_LastName);
    printf("\tAmount: %.2f \n\n",Account[i].account_Balance);
    }

    displayMenuOptions();
}

    //Descending Order
void descendingOrder()
{
    int i,j,minimum;
    struct account_details temp_value;

    for(i=0;i<accountID;i++)
        {
            for(j=i+1;j<accountID;j++)
            {
                if(Account[i].account_Balance<Account[j].account_Balance)
                {
                temp_value=Account[i];
                Account[i]=Account[j];
                Account[j]=temp_value;
                }
            }

        }

    printf("\n Descending order display: \n");
    for(i=0;i<accountID;i++)
    {
    printf("Account #%s \n", Account[i].account_CIN);
    printf("\tFirst Name: #%s\n", Account[i].account_FirstName);
    printf("\tLast Name: #%s\n", Account[i].account_LastName);
    printf("\tAmount: %.2f \n\n",Account[i].account_Balance);
    }

    displayMenuOptions();
}

    //Ascending Order (By Amount)
void ascendingOrderMin()
{
    int i,j,minimum,amountMin;
    struct account_details temp_value;

    printf("Enter the minimum amount to be shown: ");
    scanf("%d", &amountMin);

    for(i=0;i<accountID;i++)
        {
            for(j=i+1;j<accountID;j++)
            {
                if(Account[i].account_Balance>Account[j].account_Balance)
                {
                temp_value=Account[i];
                Account[i]=Account[j];
                Account[j]=temp_value;
                }
            }

        }

    printf("\n Ascending order display: \n");
    for(i=0;i<accountID;i++)
    {
        if (Account[i].account_Balance>=amountMin)
        {
        printf("Account #%s \n", Account[i].account_CIN);
        printf("\tFirst Name: #%s\n", Account[i].account_FirstName);
        printf("\tLast Name: #%s\n", Account[i].account_LastName);
        printf("\tAmount: %.2f \n\n",Account[i].account_Balance);
        }
    }

    displayMenuOptions();
}

    //Descending Order (By Amount)
void descendingOrderMin()
{
    int i,j,minimum,amountMin;
    struct account_details temp_value;

    printf("Enter the minimum amount to be shown: ");
    scanf("%d", &amountMin);

    for(i=0;i<accountID;i++)
        {
            for(j=i+1;j<accountID;j++)
            {
                if(Account[i].account_Balance>Account[j].account_Balance)
                {
                temp_value=Account[i];
                Account[i]=Account[j];
                Account[j]=temp_value;
                }
            }

        }

    printf("\n Ascending order display: \n");
    for(i=accountID;i>0;i--)
    {
        if (Account[i].account_Balance>=amountMin)
            {
        printf("Account #%s \n", Account[i].account_CIN);
        printf("\tFirst Name: #%s\n", Account[i].account_FirstName);
        printf("\tLast Name: #%s\n", Account[i].account_LastName);
        printf("\tAmount: %.2f \n\n",Account[i].account_Balance);
            }
    }

        displayMenuOptions();
}

    //Search by CIN
void searchCIN()
{
char accountNo[20];
printf("\nEnter the account CIN that you wish to search for: ");
scanf("%s", accountNo);

    for (int i = 0; i < accountID; i++)
    {
        if (stricmp(accountNo, Account[i].account_CIN) == 0)
        {
        printf("Account #%s \n", Account[i].account_CIN);
        printf("\tFirst Name: #%s\n", Account[i].account_FirstName);
        printf("\tLast Name: #%s\n", Account[i].account_LastName);
        printf("\tAmount: %.2f \n\n",Account[i].account_Balance);
        }
    }
        displayMenuOptions();
}

//Apply Loyalty Bonus
void applyLoyaltyBonus()
{
    int i,j,minimum;
    struct account_details temp_value;

    for(i=0;i<accountID;i++)
        {
            for(j=i+1;j<accountID;j++)
            {
                if(Account[i].account_Balance>Account[j].account_Balance)
                {
                temp_value=Account[i];
                Account[i]=Account[j];
                Account[j]=temp_value;
                }
            }

        }

        for(i=accountID-1;i>=accountID-3;i--)
        {
        Account[i].account_Balance *= 101.3/100;
        }

        for(i=accountID-1;i>=accountID-3;i--)
        {
        printf("Account #%s \n", Account[i].account_CIN);
        printf("\tFirst Name: #%s\n", Account[i].account_FirstName);
        printf("\tLast Name: #%s\n", Account[i].account_LastName);
        printf("\tAmount: %.2f \n\n",Account[i].account_Balance);
        }

        displayMenuOptions();
}







