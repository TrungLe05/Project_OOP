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
        cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
        return true;
        } 
        else if(inputUser == this->userName && inputPass != this->passWord) {
            cout << "\033[31m" << "wrong password!" << "\033[0m" << endl;
        }
        else if(inputUser != this->userName && inputPass == this->passWord){
            cout << "\033[31m" << "wrong username!" << "\033[0m" << endl;
        }
        else if(inputUser != this->userName && inputPass != this->passWord){
            cout << "\033[31m" << "Incorrect password and username!" <<  "\033[0m" << endl;
        }
        return false;
}

void Admin::logoutByAdmin(){
    if (this->isLoggedIn) {
        this->isLoggedIn = false;
        cout << "\033[32m" << "Logout successful!" << "\033[0m" << endl;
    } else {
        cout << "\033[31m" << "You are not logged in!" << "\033[0m"  << endl;
    }
}

string Admin::getPassWord(){return passWord;}

bool Admin::isAdminLoggedIn() {
    return this->isLoggedIn;
}
