//Create Account
//Deposit
//Withdraw
//Balance Check
//File handling for storage
#include <stdio.h>
#include <stdlib.h>

struct account {
    int acc_no;
    char name[50];
    float balance;
};

void create() {
    FILE *fp = fopen("bank.txt", "ab");
    struct account a;

    printf("Enter Account No Name Balance: ");
    scanf("%d %s %f", &a.acc_no, a.name, &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    printf("Account Created!\n");
}

void display() {
    FILE *fp = fopen("bank.txt", "rb");
    struct account a;

    printf("\nAccNo\tName\tBalance\n");
    while(fread(&a, sizeof(a), 1, fp)) {
        printf("%d\t%s\t%.2f\n", a.acc_no, a.name, a.balance);
    }
    fclose(fp);
}

void deposit() {
    FILE *fp = fopen("bank.txt", "rb+");
    struct account a;
    int acc;
    float amt;

    printf("Enter Account No: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.acc_no == acc) {
            printf("Enter amount: ");
            scanf("%f", &amt);

            a.balance += amt;
            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);
            printf("Deposited!\n");
            break;
        }
    }
    fclose(fp);
}

void withdraw() {
    FILE *fp = fopen("bank.txt", "rb+");
    struct account a;
    int acc;
    float amt;

    printf("Enter Account No: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.acc_no == acc) {
            printf("Enter amount: ");
            scanf("%f", &amt);

            if(a.balance >= amt) {
                a.balance -= amt;
                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);
                printf("Withdrawn!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            break;
        }
    }
    fclose(fp);
}

void checkBalance() {
    FILE *fp = fopen("bank.txt", "rb");
    struct account a;
    int acc;

    printf("Enter Account No: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.acc_no == acc) {
            printf("Balance: %.2f\n", a.balance);
            break;
        }
    }
    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Create 2.Display 3.Deposit 4.Withdraw 5.Balance 6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); 
            break;
            case 2: display(); 
            break;
            case 3: deposit(); 
            break;
            case 4: withdraw(); 
            break;
            case 5: checkBalance(); 
            break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}