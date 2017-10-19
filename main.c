#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int pinAdmin=1000;
const int pinUser=1002;
const int user=20;

int main()
{
    int scannum,pinKod,let,userInput,ch;
    int CashInput;
    int i,j;
    int n = 3;
    int k = 20;
    int arr[k];
    int arr1[k];
    pinKod=0;
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

            arr[j]  = rand()%10000;
        }

    for ( i = 0; i < user; i++){
    printf("[%d] [%d]\t", i, arr1[i]);
    }

    for ( j = 0; j < user; j++ ){
    printf("[%d] [%d]\t", j, arr[j]);
   }
        for (;;){
        int i=0;
        for (;;){
            printf("\n Enter Pin : ");
            let = scanf("%4d", &scannum);
            if (scannum<0){
                printf("\n It's negative Numbers\n");
                continue;
            }

            if (let == 0) {
            printf("\n It's letter input number... \n");
            fflush(stdin);
            continue;
            }
        break;
        }

        for ( j = 0; j < user; j ++){
            if (scannum ==  arr[j]){
            goto userSelect;
            //printf("Detect ");
            //printf("%d %d" ,j , arr1[j]);
            }
        }

        if (scannum == pinUser)
            {
            userSelect:
            printf(" User detected....\n");
            printf("1. Account balance.... \n");
            printf("2. Cash money.... \n");
            printf("3. Fund your balance...\n");
            printf("4. Exit take Card....\n");
            printf("Operation selected: ");
            scanf("%d",&userInput);
            switch (userInput){
            case 1:
                printf("Balance %d\n", arr1[j]);
                goto userSelect;
            case 2:
                printf("Enter sum: ");
                scanf("%d",&CashInput);
                printf("Cash - %d\n", CashInput);
                CashInput = arr1[j] - CashInput;
                arr1[j] = CashInput;
                printf("Operation successful...\n");
                goto userSelect;
            case 3:
                printf("Enter sum: ");
                scanf("%d",&CashInput);
                printf("Cash + %d\n", CashInput);
                CashInput = arr1[j] + CashInput;
                arr1[j] = CashInput;
                printf("Operation successful...\n");
                goto userSelect;
            case 4:
                break;
                fflush(stdin);
            }
        }
        if (scannum == 1000){
        printf("Supervisor main Select....\n");
        printf("1. View all data.... \n");
        printf("2. Clear all data.... \n");
        printf("3. Exit main Supervisor....\n");
        printf("Operation selected: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            for ( i = 0, j = 0; i < user; i ++, j++ ){
                printf("[%d][%d]\t",  arr1[i], arr[j]);
            }
            break;
        case 2:
            printf("Clear all array...");
            memset(arr1, 0, sizeof(arr1));
            memset(arr, 0, sizeof(arr));
            printf("Successful...\n");
            break;
        case 3:
            break;
            continue;
        }
        }
    }
}
