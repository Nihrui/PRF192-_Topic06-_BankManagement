#ifndef TRANSACTION_H    // Kiểm tra nếu TRANSACTION_H chưa được định nghĩa thì mới biên dịch khối bên dưới
#define TRANSACTION_H    // Định nghĩa TRANSACTION_H để chống lỗi định nghĩa lặp lại khi include nhiều lần
 
#include "common.h"      // Dùng các kiểu Account, AccountManager, Transaction trong common.h
 
#define TRANSFER_FEE 0.0                         // Phí chuyển khoản
#define TRANSACTION_LOG_FILE "transactions.txt"  // Tên tệp lưu nhật ký giao dịch
