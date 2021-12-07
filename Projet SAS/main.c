#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int accountID = 0;
int f;

//Functions Prototypes
void displayMenuOptions();

void accountCreationOption();
    void accountCreation();
        void singleAccountCreation();
        void multAccountCreation();

void accountOperationsOption();
    void withdrawOption();
    void depositOption();

void accountDisplayOptions();
    void sortingF();
    void printingF();
        void ascendingOrder();
        void descendingOrder();
        void ascendingOrderMin();
        void descendingOrderMin();
    void searchCIN();

void applyLoyaltyBonus();

//Account Structure
struct account_details
{
    char account_CIN[20];
    char account_FirstName[20];
    char account_LastName[30];
    float account_Balance;
}; struct account_details Account[100];


int main()
{
    printf("\t\tBank Account Management. (BAM!) \n");
    printf("\nThis app serves the purpose of managing clients' bank accounts. \n\n");
    printf("(Operate the menu below using numbers only)\n\n");

    displayMenuOptions();
}

//The Display Menu
void displayMenuOptions()
{
    printf("\n***** The Menu *****\n\n");
    printf("1. Account Creation\n");
    printf("2. Account Operations\n");
    printf("3. Display Options\n");
    printf("4. Apply loyalty bonus\n");
    printf("5. Exit the application\n\n");


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
    //Account Creation
void accountCreation()
{
    printf("\nEnter your CIN: ");
    scanf("%s", Account[accountID].account_CIN);
    printf("Enter your First Name: ");
    scanf("%s", Account[accountID].account_FirstName);
    printf("Enter your Last Name: ");
    scanf("%s", Account[accountID].account_LastName);
    printf("\nYour account with the CIN #%s has been created successfully! \n\n", Account[accountID].account_CIN);
    ++accountID;
}

        //Single account creation option
void singleAccountCreation()
{
    accountCreation();
    displayMenuOptions();
}

        //Multiple account creation option
void multAccountCreation()
{
    int creationAmount;
    printf("\nEnter the number of accounts you wish to create: ");
    scanf("%d", &creationAmount);

    struct account_details account[creationAmount];

        for (int i = 0; i < creationAmount; i++)
        {
            accountCreation();
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

    printf("\nEnter the account CIN that you wish to withdraw from: ");
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

    printf("\nEnter the account CIN that you wish to deposit to: ");
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
    //Sorting Function
void sortingF()
{
    struct account_details temp_value;
    for(int i=0;i<accountID;i++)
        {
            for(int j=i+1;j<accountID;j++)
            {
                if(Account[i].account_Balance>Account[j].account_Balance)
                {
                temp_value=Account[i];
                Account[i]=Account[j];
                Account[j]=temp_value;
                }
            }

        }
}

    //Printing Function
void printingF()
{
    printf("Account #%s \n", Account[f].account_CIN);
    printf("\tFirst Name: %s\n", Account[f].account_FirstName);
    printf("\tLast Name: %s\n", Account[f].account_LastName);
    printf("\tAmount: %.2f \n\n",Account[f].account_Balance);
}

        //Ascending Order
void ascendingOrder()
{
    sortingF();

    printf("\n Ascending order display: \n");
    for(f=0;f<accountID;f++)
    {
    printingF();
    }

    displayMenuOptions();
}

        //Descending Order
void descendingOrder()
{
    sortingF();

    printf("\n Descending order display: \n");
    for(f=accountID-1;f>=0;f--)
    {
    printingF();
    }

    displayMenuOptions();
}

        //Ascending Order (By Amount)
void ascendingOrderMin()
{
    sortingF();

    int amountMin;
    printf("Enter the minimum amount to be shown: ");
    scanf("%d", &amountMin);

    printf("\n Ascending order display: \n");
    for(f=0;f<accountID;f++)
    {
        if (Account[f].account_Balance>=amountMin)
        {
        printingF();
        }
    }

    displayMenuOptions();
}

        //Descending Order (By Amount)
void descendingOrderMin()
{
    sortingF();

    int amountMin;
    printf("Enter the minimum amount to be shown: ");
    scanf("%d", &amountMin);

    printf("\n Descending order display: \n");
    for(f=accountID-1;f>=0;f--)
    {
        if (Account[f].account_Balance>=amountMin)
            {
            printingF();
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

    for (f=0;f<accountID; f++)
    {
        if (stricmp(accountNo, Account[f].account_CIN) == 0)
        {
        printingF();
        }
    }
        displayMenuOptions();
}

//Apply Loyalty Bonus
void applyLoyaltyBonus()
{
        sortingF();

        for(f=accountID-1;f>=accountID-3;f--)
        {
        Account[f].account_Balance *= 101.3/100;
        }

        for(f=accountID-1;f>=accountID-3;f--)
        {
        printingF();
        }

        displayMenuOptions();
}







