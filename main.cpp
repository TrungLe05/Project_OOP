#include "admin.h"
#include "customer.h"
#include "menu.h"
#include "person.h"
#include "product.h"
#include "staff.h"
#include "transaction.h"
#include <iostream>
// #include <limits>
// #include <cctype>
// #include <algorithm>
#include<vector>
using namespace std;
int main(){
    MENU menu("Main menu");
    Admin ad("admin", "1234");
    //khởi tạo danh sách nhân viên 
    vector<STAFF> staffList = {
        STAFF("CQ.64.CNTT1", "Le Quoc Trung", 19, "Nam", "Parttime", "user1", "1234"),
        STAFF("CQ.64.CNTT2", "Anh Nguyen", 19, "Nam", "Parttime", "user2", "5678"),
        STAFF("CQ.64.CNTT3", "Bui Dai Nghia", 19, "Nam", "Parttime", "user3", "0123"),
    };
    //hiển thị menu khi mới vào chương trình
    cout << "===========================MENU===========================" << endl;
    menu.displayMenu();
    int choice;
    do {
        cout << "\n1 .Manager " << endl;
        cout << "2. Staff" << endl;
        cout << "3. Order " << endl;
        cout << "4. Exit" << endl;
        cout << "Enter selection: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:{
                if (!ad.isAdminLoggedIn()) {
                    bool loginSuccess = ad.loginbByAdmin();
                    if(!loginSuccess){
                        break;
                    }
                    int choiceByAdmin;
                    do {
                        cout << "===========EDIT STAFF==========" << endl;
                        cout << "1. Add staff " << endl;
                        cout << "2. Delete staff " << endl;
                        cout << "3. Edit staff information " << endl;
                        cout << "4. Show staff list " << endl;
                        cout << "===========EDIT MENU===========" << endl;
                        cout << "5. Add products to menu " << endl;
                        cout << "6. Show full menu " << endl;
                        cout << "7. Find products by ID " << endl;
                        cout << "8. Update product price " << endl;
                        cout << "9. Log out " << endl;
                        cout << "Enter selection: ";
                        cin >> choiceByAdmin;
                        cin.ignore(); 
                        switch (choiceByAdmin) {
                            case 1: {
                                cout << "Enter information for new staff " << endl;
                                STAFF newStaff;
                                newStaff.inputInformation();
                                staffList.push_back(newStaff);
                                cout << "\033[32m" << "New staff added successfully. " << "\033[0m" << endl; 
                                break;
                            }
                            case 2: {
                                cout << "Enter the staff ID to delete: ";
                                string idStaff;
                                getline(cin, idStaff);
                                bool deleted = false;
                                for (auto it = staffList.begin(); it != staffList.end(); it++) {
                                    if (it->getIdStaff() == idStaff) { 
                                        staffList.erase(it);
                                        deleted = true;
                                        cout << "\033[32m" << "Staff deleted successfully" << "\033[0m" << endl;
                                        break;
                                    }
                                }
                                if (!deleted) {
                                    cout << "\033[31m"  << "The ID entered does not exist!" << "\033[0m" << endl;
                                }
                                break;
                            }
                            case 3: {
                                 cout << "Enter the staff ID whose information needs to be edited: ";
                                string IDStaff;
                                getline(cin, IDStaff);
                                bool found = false;

                                for (STAFF &updateStaff : staffList) {
                                    if (updateStaff.getIdStaff() == IDStaff) { 
                                        found = true;
                                        int updateChoice;
                                        do {
                                            cout << "\nSelect the information to update:" << endl;
                                            cout << "1. Update name" << endl;
                                            cout << "2. Update age" << endl;
                                            cout << "3. Update gender" << endl;
                                            cout << "4. Update job position" << endl;
                                            cout << "5. Update login name" << endl;
                                            cout << "6. Update Password" << endl;
                                            cout << "7. Exit update" << endl;
                                            cout << "Enter selection: ";
                                            cin >> updateChoice;
                                            cin.ignore(); 
                                            switch (updateChoice) {
                                                case 1: {
                                                    string newName;
                                                    while(true){
                                                        cout << "Enter new name: ";
                                                        getline(cin, newName);
                                                        if (!newName.empty() && all_of(newName.begin(), newName.end(), [](char c) { return isalpha(c) || isspace(c); })) {
                                                                break;
                                                            } else {
                                                                cout <<  "\033[31m" << "Please enter letters only, no special characters or numbers!" <<  "\033[0m" << endl;
                                                            }
                                                        }
                                                    updateStaff.setName(newName); 
                                                    cout << "\033[32m" << "Name updated successfully!" << "\033[0m" << endl;
                                                    break;
                                                }
                                                case 2: {
                                                    int newAge;
                                                    while(true){
                                                        cout << "Enter new age: ";
                                                        cin >> newAge;
                                                        if(cin.fail()){
                                                            cin.clear();
                                                            cin.ignore(1000, '\n');
                                                            cout << "\033[31m" << "Invalid age!" <<  "\033[0m" << endl;
                                                        }
                                                        else if(newAge <= 0 || newAge >=100){
                                                            cout <<  "\033[31m" << "Please re-enter new age!" <<  "\033[0m" << endl;
                                                        }
                                                        else{
                                                            break;
                                                            }
                                                        }
                                                    // cin.ignore();
                                                    updateStaff.setAge(newAge); 
                                                    cout << "\033[32m" << "Successful age update." << "\033[0m" << endl; 
                                                    break;
                                                }
                                                case 3: {
                                                    string newGender;
                                                    do {
                                                        cout << "Enter new gender (Male/Female/Other): ";
                                                         getline(cin, newGender);
                                                        if (newGender == "Male" || newGender == "Female" || newGender == "male" || newGender == "female" || newGender == "Other" || newGender == "other") {
                                                            break;
                                                        }
                                                        else {
                                                            cout <<  "\033[31m" << "Invalid gender! Please re-enter." << "\033[0m" << endl;
                                                        }
                                                    } while (true);
                                                    updateStaff.setGender(newGender); 
                                                    cout << "\033[32m" << "Gender update successful." << "\033[0m" << endl; 
                                                    break;
                                                }
                                                case 4: {
                                                    string newPosition;
                                                    do{
                                                        cout << "Enter new job position (Parttime/Fulltime): "; getline(cin, newPosition);
                                                        if(newPosition == "parttime" || newPosition == "Parttime" || newPosition == "Fulltime" || newPosition == "fulltime"){
                                                            break;
                                                        }
                                                        else{
                                                            cout << "\033[31m" << "Wrong work postition!" <<  "\033[0m" << endl;
                                                        }
                                                    }while(true);
                                                    updateStaff.setPosition(newPosition); 
                                                    cout << "\033[32m" << "Job position updated successfully." << "\033[0m" << endl; 
                                                    break;
                                                }
                                                case 5: {
                                                    cout << "Enter new login name: ";
                                                    string newUserName;
                                                    getline(cin, newUserName);
                                                    updateStaff.setUserName(newUserName); 
                                                    cout << "\033[32m" << "Login name updated successfully." << "\033[0m" << endl; 
                                                    break;
                                                }
                                                case 6: {
                                                    cout << "Enter new password: ";
                                                    string newPassWord;
                                                    getline(cin, newPassWord);
                                                    updateStaff.setPassWord(newPassWord); 
                                                    cout << "\033[32m" << "Password updated successfully." << "\033[0m" << endl; 
                                                    break;
                                                }
                                                case 7:
                                                    cout << "Exit information update." << endl;
                                                    break;
                                                default:
                                                    cout <<  "\033[31m" << "Invalid selection!" << "\033[0m" << endl;
                                                    break;
                                            }
                                        } while (updateChoice != 7);

                                        break;
                                    }
                                }

                                if (!found) {
                                    cout << "\033[31m" << "The ID entered does not exist.!" << "\033[0m" << endl;
                                }
                                break;
                            }
                            case 4: {
                                for (const STAFF &temp : staffList) {
                                    temp.outputInformation();
                                }
                                break;
                            }
                            case 5:
                                // Them san pham vao menu
                                menu.additemInMenuListFromInput();
                                break;
                            case 6:
                                cout << "===========================MENU===========================" << endl;
                                menu.displayMenu();
                                break;
                            case 7:{
                                // Tìm sản phẩm bằng id
                                string id;
                                cout << "Enter the product ID you want to find " << endl;
                                cin >> id;
                                menu.findItemInMenuListById(id);
                                break;
                            }
                            case 8:{
                                // Cập nhật giá sản phẩm
                                string id;
                                char size;
                                double newPrice;
                                while(true){
                                cout << "Enter the product ID to update: "; getline(cin, id);
                                    if(menu.findItemInMenuListById(id)){
                                        break;
                                    }
                                }
                                 do{
                                    cout << "Enter the product size to update (M or L): ";
                                    cin >> size;
                                    if(size =='M' || size =='m' || size == 'L' || size == 'l') {
                                        break;
                                    }
                                    else{
                                        cout << "\033[31m" << "Invalid size! Please enter 'M' or 'L' only." <<  "\033[0m" << endl;
                                        cin.clear();  
                                        cin.ignore(1000, '\n');
                                    }

                                }while(true);
                                while (true) {
                                        cout << "Enter the product price to be updated: ";
                                        if (cin >> newPrice) { 
                                            if (newPrice > 0) {
                                                break; 
                                            } else {
                                                cout << "\033[31m" << "Invalid price! Please enter a positive number." << "\033[0m" << endl;
                                            }
                                        } else {
                                            cout << "\033[31m" << "Invalid input! Please enter a numeric value." << "\033[0m" << endl;
                                            cin.clear();               
                                        }
                                        cin.ignore(1000, '\n');        
                                    }
                                cout << "\nProduct before update" << endl;
                                if(menu.updatePrice(id,size,newPrice)){
                                    cout << "\033[32m" << "\nProduct update successful." << "\033[0m" << endl; // chữ xanh
                                    menu.findItemInMenuListById(id);
                                }else{
                                    cout <<  "\033[31m" <<  "Product update failed!" <<  "\033[0m" << endl;
                                }
                                break;
                            }
                            case 9:{
                                ad.logoutByAdmin();
                                break;
                            }
                            default:
                                cout <<  "\033[31m" << "Invalid selection!" << "\033[0m" << endl;
                                break;
                        }
                    } while (choiceByAdmin != 9);
                }else{
                    cout <<  "\033[31m" << "You need to log in first! " << "\033[0m" << endl;
                }
                break;
                }
            case 2: {
                string inputUserName, inputPassWord;
                cout << "Enter username: ";
                cin >> inputUserName;
                cout << "Enter password: ";
                cin >> inputPassWord;
                bool check = false;
                STAFF* staff;
                for(auto it = staffList.begin(); it != staffList.end(); it++){
                if (it->loginByStaff(inputUserName, inputPassWord)){
                        it->outputInformation();
                        check = true;
                        staff = &(*it);
                        break;
                    }
                }
                if(!check){
                    cout <<  "\033[31m" << "Incorrect username or password!" <<  "\033[0m" << endl;
                    break;
                }

                    int choiceByStaff;
                    do{
                        cout << "1. Checkin hour " << endl; 
                        cout << "2. Checkout hour  " << endl;
                        cout << "3. View hours worked " << endl;
                        cout << "4. View current salary " << endl;
                        cout << "5. Log out " << endl;
                        cout << "Enter selection: ";
                        cin >> choiceByStaff;
                        switch(choiceByStaff){
                                case 1:
                                    staff->checkIn();
                                    break;
                                case 2:
                                    staff->checkOut();
                                    break;
                                case 3:
                                    staff->displayTotalHours();
                                    break;
                                case 4:
                                    staff->calculateSalary();
                                    break;
                                case 5:{
                                    cout << "\033[32m" << "Logout successful. " << "\033[0m" << endl; // chữ xanh
                                    break;
                                }
                                default:
                                    cout <<  "\033[31m" << "Invalid selection!" << "\033[0m" << endl;
                                    break;
                            }
                    }while(choiceByStaff != 5);
                break;
            }
            case 3:{
                CUSTOMER customer;
                customer.orderItems(menu);
                int transactionCode;
                cout << "Enter transaction ID: "; cin >> transactionCode;
                customer.checkout(transactionCode,"Cash");
                break;
            }
            case 4:
                cout << "\033[31m" << "End program!" << "\033[0m" << endl;
                break;
            default:
                cout <<  "\033[31m" << "Invalid selection!" << "\033[0m" << endl;
                break;
        }
    } while (choice != 4);
    return 0;
}
