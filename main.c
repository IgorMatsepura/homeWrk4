#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int pinAdmin=1000;
const int pinUser=1002;
const int user=20;

int main()
{
    int scannum, pinKod, let, userInput, ch, enterNumb;
    int CashInput, pinErr;
    int i,j,z,k;
    int n = 2;
    int arr[user];
    int arr1[user];
    pinKod = 0;
    scannum = 0;
    char str[2];
    enum { min_val = 1000, max_val = 9999 };
    srand(time(NULL));
        //generate Random Pin  entry by array data
        for ( i = 0; i < user; i ++){
        arr1[i]  = user + i*125;
        }

        for ( j = 0; j < user; j ++){

            if  (rand()%10000 > 10000) {
            10000 - rand()%10000 ;
            }

            if (rand()%10000 < 1000) {
            1000 + rand()%10000 ;
            }
            arr[j]  = 1000 + rand()%10000;
        }
        // Entering a loop with the condition that 3 attempts to enter a pin
        for ( k = 0 ; k <= 2; k++){
            for (;;){
            printf("\n Enter Pin : ");
            let = scanf("%4d""%1[^\n]""%*[^\n]",&scannum,str);
            // Checking the Input Values
            if (scannum < 0){
                printf("\n It's negative Numbers\n");
                continue;
            }

            if (let != 1) {
            printf("\n It's letter input number... \n");
            fflush(stdin);
            continue;
            }

            else if (scannum < min_val || scannum > max_val) {
            printf("Number must be in range %d..%d\n", min_val, max_val);
            }
        break;
        }
        // Pin match search and go to the user menu
        for ( j = 0; j < user; j ++){
            if (scannum ==  arr[j]){
            pinKod = arr[j];
            goto userSelect;
            }
        }

        // If 3 attempts - programm blocked Card
        if (k == n) {
        printf("The Card is reject. Please call in your bank\n");
        break;
        }
        // Main User Select
        if (scannum == pinUser || scannum == pinKod  ){
            userSelect:
            printf("\nUser detected....\n");
            printf("1. Account balance.... \n");
            printf("2. Cash money.... \n");
            printf("3. Fund your balance...\n");
            printf("4. Exit take Card....\n");
            printf("\nOperation selected: ");
            scanf("%d",&userInput);
            if ((userInput < 0) || (ch > 4)){
                printf("\nSelect - incorrect. Correct select 1,2,3,4.\n");
                continue;
            }
            switch (userInput){
            case 1:
                printf("Balance %d\n\n", arr1[j]);
                goto userSelect;
            case 2:
                printf("Enter sum: ");
                scanf("%d",&CashInput);
                printf("Cash - %d\n", CashInput);
                CashInput = arr1[j] - CashInput;
                arr1[j] = CashInput;
                printf("Operation successful...\n");
                CashInput = 0;
                goto userSelect;
            case 3:
                printf("Enter sum: ");
                scanf("%d",&CashInput);
                printf("\nCash + %d\n", CashInput);
                CashInput = arr1[j] + CashInput;
                arr1[j] = CashInput;
                printf("Operation successful...\n");
                CashInput = 0;
                goto userSelect;
            case 4:
                break;
                fflush(stdin);
            }
        k = 0;
        userInput = 0;
        }
        // Main admin Select
        if (scannum == pinAdmin){
            while (ch != 3){
            printf("Supervisor main Select....\n");
            printf("1. View all data.... \n");
            printf("2. Clear all data.... \n");
            printf("3. Exit main Supervisor....\n");
            printf("Operation selected: ");
            scanf("%d", &ch);
                if ((ch < 0) || (ch > 3)){
                printf("\nSelect - incorrect. Correct select 1,2,3.\n");
                continue;
            }
            switch (ch){
            case 1:
                for ( i = 0, j = 0; i < user; i ++, j++ ){
                printf("Summ - %d Pin - %d\n",  arr1[i], arr[j]);
                }
                break;
            case 2:
                printf("Clear all array...");
                memset(arr1, 0, sizeof(arr1));
                memset(arr, 0, sizeof(arr));
                printf("Successful...\n");
                break;
            //case 3:
            }
            }
        k = 0;
        ch = 0;
        }
    }
    return 0;
}
