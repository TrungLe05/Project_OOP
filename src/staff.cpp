#include"staff.h"



STAFF::STAFF(){
    idStaff = " ";
    salary = 0.0;
    position = " ";
    totalHoursWorked = 0.0;
    userName = " ";
}

STAFF::STAFF(string idStaff, string name, int age, string gender, string position, string userName, string passWord) : PERSON(name, age, gender){
    this->idStaff = idStaff;
    this->position = position;
    this->userName = userName;
    this->passWord = passWord;
}

void STAFF::inputInformation(){
    PERSON::inputInformation();
    cout << "create staff ID : "; cin >> this->idStaff;
    cin.ignore();
    do{
        cout << "Enter work position (Parttime/Fulltime): "; getline(cin, this->position);
        if(this->position == "parttime" || this->position == "Parttime" || this->position == "Fulltime" || this->position == "fulltime"){
            break;
        }
        else{
            cout << "\033[31m" << "Wrong work postition!" << "\033[0m"  << endl;
        }
    }while(true);
    cout << "Create a username: "; getline(cin, this->userName);
    cout << "Create Password: "; getline(cin, this->passWord);
}



bool STAFF::loginByStaff(const string& inputUserName, const string& inputPassWord) {
    if (inputUserName == this->userName && inputPassWord == this->passWord) {
        this->isLoggedIn = true;
        cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
        return true;
    }
    return false;
}

void STAFF::outputInformation()const {
        PERSON::outputInformation();
        cout << endl;
        cout << "ID\t\t\t Position" << endl;
        cout << this->idStaff << "\t\t " << this->position << endl;
}

void STAFF::updateInformationStaff(){
    cout << "Update staff information" << endl;
    PERSON::inputInformation();
    cout << "Enter staff ID: "; cin >> this->idStaff; // nên nhập id trùng với id các nhân viên còn lại để khi in ra thì đẹp hơn
    cin.ignore();
    do{
        cout << "Enter work position (Parttime/Fulltime): "; getline(cin, this->position);
        if(this->position == "parttime" || this->position == "Parttime" || this->position == "Fulltime" || this->position == "fulltime"){
            break;
        }
        else{
            cout << "\033[31m" << "Wrong work postition!" << "\033[0m" << endl;
        }
    }while(true);
    cout << "Enter username: "; getline(cin, this->userName);
    cout << "Enter password: "; getline(cin, this->passWord);
}

void STAFF::logoutByStaff() {
    if (isLoggedIn) {
        isLoggedIn = false;
        cout << "\033[32m" << "Logout successful!" << "\033[0m" << endl;
    } else {
        cout <<  "\033[31m" << "You are not logged in!" << "\033[0m" << endl;
    }
}

string STAFF::getPassWord(){return passWord;}

string STAFF::getIdStaff(){return idStaff;}

void STAFF::setIdStaff(string idStaff){
    this->idStaff = idStaff;
}
void STAFF::setPosition(string position){
    this->position = position;
}
void STAFF::setUserName(string userName){
    this->userName = userName;
}
void STAFF::setPassWord(string passWord){
    this->passWord = passWord;
}


void STAFF::checkIn(){
    checkInTime = time(0); // Lấy thời gian hiện tại
    cout << "Check-in for " << this->getName() << " at " << ctime(&checkInTime);
}

// Định nghĩa hàm checkOut
void STAFF::checkOut() {
    checkOutTime = time(0); // Lấy thời gian hiện tại
    cout << "Check-out for " << this->getName() << " at " << ctime(&checkOutTime);
    
    // Tính toán tổng giờ làm việc
    double hoursWorked = difftime(checkOutTime, checkInTime) / 3600.0; // Chuyển đổi giây thành giờ
    totalHoursWorked += hoursWorked;
}

// Định nghĩa hàm lấy tổng giờ làm việc
double STAFF::getTotalHoursWorked() const {
    return totalHoursWorked;
}

// Định nghĩa hàm hiển thị tổng giờ làm việc
void STAFF::displayTotalHours()  {
    cout << "Total hours worked by " << this->getName() << ": " << totalHoursWorked << " hours" << endl;
}

// Định nghĩa hàm tính lương
void STAFF::calculateSalary() {
    double salary;
    if (position == "Parttime" || position == "parttime") {
        salary = totalHoursWorked * 18000; // Lương Part-time
    } else if (position == "Fulltime" || position == "fulltime") {
        salary = totalHoursWorked * 23000; // Lương Full-time
    } else {
        salary = 0; // Nếu vị trí không hợp lệ
    }

    // In ra thông tin lương
    cout << "Total hours worked by " << this->getName() << ": " << totalHoursWorked << " hours" << endl;
    cout << "Salary for " << totalHoursWorked << " hours worked: " << salary << " VND" << endl;
}



STAFF::~STAFF(){

}