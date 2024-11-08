#include"admin.h"


Admin::Admin(string userName, string passWord){
    this->userName = userName;
    this->passWord = passWord;
    isLoggedIn = false;
}

bool Admin::loginbByAdmin(){
    string inputUser, inputPass;
    cout <<"Enter username: ";
    getline(cin, inputUser);
    cout << "Enter password: ";
    getline(cin, inputPass);
    if (inputUser == this->userName && inputPass == this->passWord) {
        this->isLoggedIn = true;
        cout << "Login successful!" << endl;
        return true;
        } else {
        cout << "Incorrect username or password!" << endl;
        return false;
    }
}

void Admin::logoutByAdmin(){
    if (this->isLoggedIn) {
        this->isLoggedIn = false;
        cout << "Logout successful!" << endl;
    } else {
        cout << "You are not logged in!" << endl;
    }
}

string Admin::getPassWord(){return passWord;}

bool Admin::isAdminLoggedIn() {
    return this->isLoggedIn;
}
