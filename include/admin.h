#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include<string>
using namespace std;
class Admin {
    private:
        string userName; // tên admin đăng nhập vào
        string passWord; // mật khẩu của admin
        bool isLoggedIn; // kiểm tra xem đã đăng nhập hay chưa

    public:
        Admin(string userName, string passWord);
        bool loginbByAdmin();
        void logoutByAdmin();
        string getPassWord();
        bool isAdminLoggedIn();// giống với việc hàm getisLoggedIn để trả biểt răng đã đăng xuất thành công hay chưa
};
#endif