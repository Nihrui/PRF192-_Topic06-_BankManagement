#ifndef COMMON_H         
#define COMMON_H         
#define SUCCESS 1                  
#define ERROR_INVALID_DATA 0       
#define ERROR_MEMORY_FULL -1       
#define ERROR_INSUFFICIENT_BALANCE -2
#define ERROR_DUPLICATE_ACCOUNT -3      
#define ERROR_NOT_FOUND -4              

typedef struct {         
    char accountNumber[20]; 
    char holderName[50];   
    char accountType[20];   
    double balance;        
    char openingDate[15];   
} Account;               

typedef struct {         
    Account *accounts;   
    int count;           
} AccountManager;  
typedef struct {        
    char transactionID[20]; 
    char sourceAcc[20];    
    char destAcc[20];      
    char type[15];          
    double amount;          
    char timestamp[25];     
} Transaction;          

#endif                   