#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
#include <utility>
#include"person.h"
#include<vector>
#include"menu.h"
#include"menuItem.h"
#include"transaction.h"
#include<iostream>
using namespace std;

class CUSTOMER : public PERSON{
    private:
    vector<pair<MENUITEM, int>> orderList; // danh sách đơn đặt hàng của customer
    public:
        CUSTOMER();
        void orderItems(MENU &menu); // thêm đơn hàng
        void checkout(int &id,const string &paymentMethod); // thanh toán
        int generateTransactionID();
};
#endif