#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "common.h" 
//========================================== OPEN ACCOUNT ==========================================
int am_openAccount(AccountManager* am, Account newAcc) {
    for (int i = 0; i < am->count; i++) {
        if (strcmp(am->accounts[i].accountNumber, newAcc.accountNumber) == 0) {
            printf("Error: Duplicate account number! (%s)\n", newAcc.accountNumber);
            return ERROR_INVALID_DATA; 
        }
    }
    
    if (newAcc.balance < 0) {
        printf("Error: Initial balance cannot be negative!\n");
        return ERROR_INVALID_DATA;
    }

    Account* temp = (Account*) realloc(am->accounts, (am->count + 1) * sizeof(Account));
    if (temp == NULL) {
        printf("Error: Memory full! Could not allocate memory.\n");
        return ERROR_MEMORY_FULL;
    }
    
    am->accounts = temp; 

    am->accounts[am->count] = newAcc;

    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    strftime(am->accounts[am->count].openingDate,
             sizeof(am->accounts[am->count].openingDate),
             "%Y-%m-%d", local);

    am->count++;

    printf("Account opened successfully! (Opened on: %s)\n",
           am->accounts[am->count - 1].openingDate);
    return SUCCESS;
}

//=====================================================================================


//========================================== UPDATE HOLDER INFO ==========================================
int am_updateHolderInfo(AccountManager* am, const char* accNum) {
    if (am == NULL || accNum == NULL) return ERROR_INVALID_DATA;

    int foundIndex = -1;
    for (int i = 0; i < am->count; i++) {
        if (strcmp(am->accounts[i].accountNumber, accNum) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Error: Account number %s not found!\n", accNum);
        return ERROR_INVALID_DATA;
    }

    printf("Enter new holder name: ");
    getchar(); 
    fgets(am->accounts[foundIndex].holderName, sizeof(am->accounts[foundIndex].holderName), stdin);
    am->accounts[foundIndex].holderName[strcspn(am->accounts[foundIndex].holderName, "\n")] = 0;

    printf("Account holder information updated successfully!\n");
    return SUCCESS;
}
//===================================================================================


//========================================== SEARCH ACCOUNT ==========================================
int am_searchAccount(const AccountManager* am, const char* keyword) {
    if (am == NULL || keyword == NULL) return ERROR_INVALID_DATA;

    int countFound = 0;
    printf("\n--- SEARCH RESULTS ---\n");
    for (int i = 0; i < am->count; i++) {
        if (strstr(am->accounts[i].accountNumber, keyword) != NULL || 
            strstr(am->accounts[i].holderName, keyword) != NULL) {
            printf("Acc No: %s | Name: %s | Type: %s | Balance: %.2f | Date: %s\n",
                   am->accounts[i].accountNumber,
                   am->accounts[i].holderName,
                   am->accounts[i].accountType,
                   am->accounts[i].balance,
                   am->accounts[i].openingDate);
            countFound++;
        }
    }

    if (countFound == 0) {
        printf("No matching accounts found.\n");
        return ERROR_INVALID_DATA;
    }
    return SUCCESS;
}

void am_freeAccounts(AccountManager* am) {
    if (am != NULL && am->accounts != NULL) {
        free(am->accounts);
        am->accounts = NULL;
        am->count = 0;
    }
}
//===================================================================================
