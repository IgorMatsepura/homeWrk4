#include <stdio.h>
#include <stdlib.h>


const int PINADMIN = 1000;  // Static variable PIN - administrator
const int PINUSER = 1002;   // Test static variable PIN - user
const int USER = 5000;      // Variable number of users and  Pin-codes
enum { MIN_PINCODE = 1000, MAX_PINCODE = 9999 };  // Variable range of Pin-code input is not less than 1000 to 9999
const int RETRYPIN = 2;     // Max input  bad pin-code
const int SUMARRAY = 125;   // Static sum for array sum

int main()
{
    int enterNumb;
    int pinCode;
    int enterNumbers, userInput, adminInput;
    int cashInput;
    int i,j,z,k;
    int arrayPinCod[USER];
    int arraySum[USER];
    pinCode = 0;
    enterNumb = 0;
    enterNumbers = 0;

        //generate Summ and Pin  entry by array data
        for ( i = 0; i < USER; i ++){
            arraySum[i]  = USER + i * SUMARRAY;
        }

        for ( j = 0; j < USER; j ++){
            arrayPinCod[j]  = PINUSER + j;
            printf("%d\t", arrayPinCod[j]);
        }
        // Entering a loop with the condition that 3 attempts to enter a pin
        for ( k = 0; k <= RETRYPIN; k++){
            for (;;){
                printf("\n Enter Pin : ");
                enterNumbers = scanf("%d",&enterNumb);

            // Checking the Input Values
            if (enterNumb < 0){
                printf("\n It's negative Numbers\n");
                continue;
            }
            // Checking the Input Letters
            if (enterNumbers == 0) {
                printf("\n It's letter input number... \n");
                fflush(stdin);
                continue;
            }
            // Checking  Values range of Pin-code
            if (enterNumb < MIN_PINCODE || enterNumb > MAX_PINCODE) {
                printf("Number must be in range %d..%d\n", MIN_PINCODE, MAX_PINCODE);
                continue;
            }
        break;
        }

        if (enterNumb == !pinCode){
            printf("Pin-code is not correct...");
        }

        // If 3 attempts - programm blocked Card
        if (k == RETRYPIN) {
            printf("The Card is reject. Please call in your bank\n");
            break;
        }
        // Pin match search and go to the user menu
        for ( j = 0; j < USER; j ++){
            if (enterNumb ==  arrayPinCod[j]){
                pinCode = arrayPinCod[j];
                break;
            }
        }
        // Main User Select
        if (enterNumb == pinCode){
            for (;;){
                while (userInput != 4){
                    printf("\nUser detected....\n");
                    printf("1. Account balance.... \n");
                    printf("2. Cash money.... \n");
                    printf("3. Fund your balance...\n");
                    printf("4. Exit take Card....\n");
                    printf("\nOperation selected: ");
                    scanf("%d",&userInput);
                    if ((userInput < 0) || (userInput > 4)){
                        printf("\nSelect - incorrect. Correct select 1,2,3,4.\n");
                    }
                    switch (userInput){
                        case 1:
                            printf("Balance %d\n", arraySum[j]);
                            break;
                        case 2:
                            printf("Enter sum: ");
                            scanf("%d",&cashInput);
                            printf("Cash - %d\n", cashInput);
                            cashInput = arraySum[j] - cashInput;
                            arraySum[j] = cashInput;
                            printf("Operation successful...\n");
                            cashInput = 0;
                            break;
                        case 3:
                            printf("Enter sum: ");
                            scanf("%d",&cashInput);
                            printf("\nCash + %d\n", cashInput);
                            cashInput = arraySum[j] + cashInput;
                            arraySum[j] = cashInput;
                            printf("Operation successful...\n");
                            cashInput = 0;
                            break;
                        default:
                            break;
                    }
                }
            break;
            }
        k = 0;
        userInput = 0;
        }
        // Main admin Select
        if (enterNumb == PINADMIN){
            while (adminInput != 3){
                printf("Supervisor main Select....\n");
                printf("1. View all data.... \n");
                printf("2. Clear all data.... \n");
                printf("3. Exit main Supervisor....\n");
                printf("Operation selected: ");
                scanf("%d", &adminInput);
                if ((adminInput < 0) || (adminInput > 3)){
                    printf("\nSelect - incorrect. Correct select 1,2,3.\n");
                    continue;
            }
            switch (adminInput){
            case 1:
                for ( i = 0, j = 0; i < USER; i ++, j++ ){
                    printf("Summ - %d Pin - %d\n",  arraySum[i], arrayPinCod[j]);
                }
                break;
            case 2:
                printf("Clear all posts Sum and Pin...");
                memset(arraySum, 0, sizeof(arraySum));
                memset(arrayPinCod, 0, sizeof(arrayPinCod));
                printf("Successful...\n");
                break;
            default:
                break;
            }
            }
            k = 0;
            enterNumb = 0;
            adminInput = 0;
            fflush(stdin);
        }
    }
    return 0;
}
