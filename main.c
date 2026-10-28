#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

// --- KHAI BÁO NGUYÊN MẪU HÀM TỪ CÁC MODULE ---
// 1. Phân hệ Account Vũ Mai Anh Đạt
int am_openAccount(AccountManager* am, Account newAcc);
int am_updateHolderInfo(AccountManager* am, const char* accNum);
int am_searchAccount(AccountManager* am, const char* keyword);

// 2. Phân hệ Transaction (Nguyễn Nhật An) -
// int tm_withdraw(AccountManager* am, const char* accNum, double amount);
// int tm_transfer(AccountManager* am, const char* src, const char* dest, double amt);
// void tm_sortByBalance(AccountManager* am);

// 3. Phân hệ File I/O (Phạm Nguyễn Tiến Phát)
// int file_saveAccounts(const AccountManager* am, const char* filename);
// int file_loadAccounts(AccountManager* am, const char* filename);

void ui_displayMainMenu() {
    printf("\n=========================================\n");
    printf("   BANK ACCOUNT & TRANSACTION SYSTEM     \n");
    printf("=========================================\n");
    printf("1. Open New Account\n");
    printf("2. Update Account Holder Info\n");
    printf("3. Search Account\n");
    printf("4. Sort Accounts by Balance\n");
    printf("5. Save Accounts to File\n");
    printf("6. Load Accounts from File\n");
    printf("0. Exit System\n");
    printf("=========================================\n");
    printf("Select option: ");
}

int main() {
    AccountManager am;
    am.accounts = NULL;
    am.count = 0;

    int choice;
    do {
        ui_displayMainMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                Account newAcc;
                printf("Enter Account Number: ");
                scanf("%s", newAcc.accountNumber);
                printf("Enter Holder Name: ");
                getchar();
                fgets(newAcc.holderName, sizeof(newAcc.holderName), stdin);
                newAcc.holderName[strcspn(newAcc.holderName, "\n")] = 0;
                
                printf("Enter Account Type (Savings/Checking): ");
                scanf("%s", newAcc.accountType);
                printf("Enter Initial Balance: ");
                scanf("%lf", &newAcc.balance);

                am_openAccount(&am, newAcc);
                break;
            }
            case 2: {
                char accNum[20];
                printf("Enter Account Number to update: ");
                scanf("%s", accNum);
                am_updateHolderInfo(&am, accNum);
                break;
            }
            case 3: {
                char keyword[50];
                printf("Enter keyword (Account Number or Name): ");
                scanf("%s", keyword);
                am_searchAccount(&am, keyword);
                break;
            }
            case 4:
                // tm_sortByBalance(&am);
                printf("Feature under development by team member.\n");
                break;
            case 5:
                // file_saveAccounts(&am, "accounts.txt");
                printf("Feature under development by team member.\n");
                break;
            case 6:
                // file_loadAccounts(&am, "accounts.txt");
                printf("Feature under development by team member.\n");
                break;
            case 0:
                if (am.accounts != NULL) {
                    free(am.accounts);
                }
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Choice not available yet!\n");
        }
    } while (choice != 0);

    return 0;
}