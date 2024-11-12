#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<string>
#include<vector>
#include<ctime>
#include<iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
};
typedef struct Date date;
// class TRANSACTION
class TRANSACTION {
    private:
        int idTransaction; // mã hóa đơn
        string paymentMethod; // phương thức thanh toán (tiền mặt/TKNH)
        date dateTransaction;
        long long totalAmount; // tổng tiền thanh toán
        vector<pair<double, int>> items; // danh sách các mặt hàng, mỗi phần tử gồm giá và số lượng

    public:
        TRANSACTION(string paymentMethod);
        TRANSACTION(int id, string method);
        void addItem(double price, int quantity); // thêm sản phẩm vào hóa đơn
        void calculateOrder(); // tính tổng tiền thanh toán
        void displayTransactionDetails(); // hiển thị chi tiết hóa đơn
        void setCurrentDateAndTime(); // đặt ngày và giờ hiện tại
        string convertToWords(long long amount); // chuyển số thành chữ
};

#endif