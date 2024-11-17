#ifndef STAFF_H
#define STAFF_H
#include<string>
#include"person.h"
#include<iostream>
#include<ctime>
using namespace std;

class STAFF : public PERSON{
    private:
        string idStaff;
        double salary;
        string position;
        time_t checkInTime; // Lưu thời gian check-in
        time_t checkOutTime; // Lưu thời gian check-out
        double totalHoursWorked; // Thuộc tính tổng số giờ làm việc
        string userName;
        string passWord;
        bool isLoggedIn;
    public:
        STAFF();
        STAFF(string idStaff, string name, int age, string gender, string position, string userName, string passWord);
        void inputInformation(); // phương thức nhập thông tin nhân viên khi được admin chọn vào mục thêm nhân viên
        void outputInformation() const;
        void updateInformationStaff();
        void checkIn(); // hàm để nhân viên check-in giờ đi làm ( chấm công )
        void checkOut();   // hàm để nhân viên check-out 
        void calculateSalary(); // hàm đựa vào tgian check-in và check-out để tính lương cho nhân viên
        double getTotalHoursWorked() const; // Khai báo hàm lấy tổng giờ làm việc
        void displayTotalHours() ; // Khai báo hàm hiển thị tổng giờ làm việc
        STAFF(string userName, string passWord);
        bool loginByStaff(const string& inputID, const string& inputPassWord);
        void logoutByStaff();
        bool isStaffLoggedIn();
        string getPassWord();
        string getIdStaff();
        void setIdStaff(string idStaff);
        void setPosition(string position);
        void setUserName(string userName);
        void setPassWord(string passWord);
        virtual ~STAFF();
};


#endif