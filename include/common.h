#ifndef COMMON_H         // Kiểm tra nếu COMMON_H chưa được định nghĩa thì mới biên dịch khối bên dưới
#define COMMON_H         // Định nghĩa COMMON_H để chống lỗi định nghĩa lặp lại khi include nhiều lần
#define SUCCESS 1                  // Thực hiện thành công
#define ERROR_INVALID_DATA 0       // Dữ liệu không hợp lệ (Trùng số tài khoản, số âm,...)[cite: 1, 2]
#define ERROR_MEMORY_FULL -1       // Lỗi cấp phát bộ nhớ động (realloc/malloc thất bại)[cite: 1, 2]
#define ERROR_INSUFFICIENT_BALANCE -2

typedef struct {         // Khai báo cấu trúc Account (Đại diện cho một Tài khoản ngân hàng)
    char accountNumber[20]; // Mảng ký tự lưu mã tài khoản (Ví dụ: "ACC001")
    char holderName[50];    // Mảng ký tự lưu họ tên đầy đủ của chủ tài khoản
    char accountType[20];   // Mảng ký tự lưu loại tài khoản ("Savings" hoặc "Checking")
    double balance;         // Biến kiểu số thực lưu số dư hiện tại của tài khoản
    char openingDate[15];   // Mảng ký tự lưu ngày mở tài khoản theo định dạng YYYY-MM-DD
} Account;               // Đặt tên tắt cho kiểu dữ liệu struct này là Account

typedef struct {         // Khai báo cấu trúc AccountManager (Quản lý danh sách mảng động tài khoản)
    Account *accounts;   // Con trỏ trỏ tới mảng động chứa danh sách các Account
    int count;           // Biến số nguyên lưu tổng số tài khoản thực tế đang có trong hệ thống
} AccountManager;        // Đặt tên tắt cho kiểu dữ liệu struct này là AccountManager

typedef struct {         // Khai báo cấu trúc Transaction (Đại diện cho một Giao dịch ngân hàng)
    char transactionID[20]; // Mảng ký tự lưu mã định danh giao dịch duy nhất
    char sourceAcc[20];     // Mảng ký tự lưu mã tài khoản nguồn (gửi/rút/chuyển đi)
    char destAcc[20];       // Mảng ký tự lưu mã tài khoản đích (nhận tiền)
    char type[15];          // Loại giao dịch ("Deposit": nạp, "Withdraw": rút, "Transfer": chuyển)
    double amount;          // Số tiền thực hiện trong giao dịch
    char timestamp[25];     // Thời gian chi tiết diễn ra giao dịch (Ngày giờ)
} Transaction;           // Đặt tên tắt cho kiểu dữ liệu struct này là Transaction

#endif                   // Kết thúc phạm vi bảo vệ header của #ifndef COMMON_H