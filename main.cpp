#include "admin.h"
#include "customer.h"
#include "menu.h"
#include "person.h"
#include "product.h"
#include "staff.h"
#include "transaction.h"
#include "WorkSchedule.h"
#include <iostream>
#include<cctype>
#include <fstream>
// #include <limits>
// #include <cctype>
// #include <algorithm>
#include<vector>
using namespace std;
void logChange(const std::string& change) {
    std::ofstream logFile("change_log.txt", std::ios_base::app);
    logFile << change << std::endl;
}

// Function to encrypt passwords (simple example, replace with a proper encryption method)
std::string encryptPassword(const std::string& password) {
    std::string encrypted = password;
    std::transform(encrypted.begin(), encrypted.end(), encrypted.begin(), [](char c) { return c + 1; });
    return encrypted;
}


std::string centerTextInFrame(const std::string& text, int frameWidth) {
    int padding = (frameWidth - 2 - text.length()) / 2; // Trừ 2 ký tự '|' hai bên
    if (padding > 0) {
        return "|" + std::string(padding, ' ') + text + std::string(padding, ' ') + "|";
    }
    return "|" + text + "|";
}

// Hàm để căn giữa toàn bộ khung trên màn hình
void printCenteredFrame(const std::vector<std::string>& lines, int consoleWidth, int frameWidth) {
    int leftPadding = (consoleWidth - frameWidth) / 2;

    for (size_t i = 0; i < lines.size(); ++i) {
        std::string line;
        if (lines[i][0] == '|') {
            line = centerTextInFrame(lines[i].substr(1, lines[i].length() - 2), frameWidth);
        } else {
            line = lines[i];
        }
        
        if (i == lines.size() - 1) {
            // In dòng cuối "Enter selection: " mà không xuống dòng
            std::cout << std::string(leftPadding, ' ') << line;
        } else {
            std::cout << std::string(leftPadding, ' ') << line << std::endl;
        }
    }
}

vector<std::string> convertStaffVectorToString(const std::vector<STAFF>& staffList, PERSON &a) {
    std::vector<std::string> stringList;
    for (const auto& staff : staffList) {
        stringList.push_back(staff.toString(a));
    }
    return stringList;
}

int main(){
    srand(std::time(0));
    int consoleWidth = 180;  
    MENU menu("Main menu");
    Admin ad("admin", "1234");
    //khởi tạo danh sách nhân viên 
    vector<STAFF> staffList = {
        STAFF("CQ.64.CNTT1", "Le Quoc Trung", 05, 05, 2005, "Nam", "Parttime", "user1", "1234"),
        STAFF("CQ.64.CNTT2", "Anh Nguyen", 06, 04, 2005, "Nam", "Parttime", "user2", "5678"),
        STAFF("CQ.64.CNTT3", "Bui Dai Nghia", 07, 03, 2005, "Nam", "Parttime", "user3", "0123"),
    };
    WorkSchedule::Shift s1 = {"Le Quoc Trung  ","Monday", "Morning", true};
    WorkSchedule employeeSchedule(s1);
    employeeSchedule.addSchedule("Le Quoc Trung  " ,"Tuesday", "Evening", true);
    employeeSchedule.addSchedule("Le Quoc Trung  ", "Wednesday", "Morning", false);
    employeeSchedule.addSchedule("Le Quoc Trung    " ,"Thursday", "Afternoon", true);
    employeeSchedule.addSchedule("Nguyen Anh Nguyen" ,"Friday", "Morning", true);
    employeeSchedule.addSchedule("Nguyen Anh Nguyen" ,"Saturday", "Day Off", false);
    employeeSchedule.addSchedule( "Le Quoc Trung","Sunday", "Night", true);

    // employeeSchedule.displaySchedule();
    // vector<std::string> stringList = convertStaffVectorToString(staffList);
    int choice;
    do {
        // cout << "+======USER OPTIONS======+" << endl;
        // cout << "|\t1. Manager\t |" << endl;
        // cout << "+------------------------+" << endl;
        // cout << "|\t2. Staff\t |" << endl;
        // cout << "+------------------------+" << endl;
        // cout << "|\t3. Order\t |" << endl;
        // cout << "+------------------------+" << endl;
        // cout << "|\t4. Exit \t |" << endl;
        // cout << "+========================+" << endl;
        vector<string> userOptions = {
            "+======USER OPTIONS======+",
            "|1. Manager              |" ,
            "|2. Staff                |" ,
            "|3. Order                |",
            "|4. Exit                 |",
            "+========================+",
            "Enter selection: ",
        };
        int frameWidthUserOptions = 20;
        printCenteredFrame(userOptions, consoleWidth, frameWidthUserOptions);
        while(true){
            cin >> choice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\033[31mInvalid selection! \033[0m" << endl;
            }
            else{
                break;
            }
        }
        cin.ignore(); 
        switch (choice) {
            case 1:{
                // system("cls");
                if (!ad.isAdminLoggedIn()) {
                    bool loginSuccess = ad.loginbByAdmin();
                    if(!loginSuccess){
                        break;
                    }
                    int choiceByAdmin;
                    do {
                          // Giả sử chiều rộng console là 80 ký tự
                        vector<string> Choice = {
                            "+===============EDIT STAFF================+",
                            "|                                         |",
                            "| 1. Add staff                            |",
                            "| 2. Delete staff                         |",
                            "| 3. Edit staff information               |",
                            "| 4. Show staff list                      |",
                            "|                                         |",
                            "+===============EDIT MENU=================+",
                            "|                                         |",
                            "| 5. Add products to menu                 |",
                            "| 6. Show full menu                       |",
                            "| 7. Find products by ID                  |",
                            "| 8. Update product price                 |",
                            "|                                         |",
                            "+=========================================+",
                            "| 9. Log out                              |",
                            "+=========================================+",
                            "Enter selection: "
                        };
                        int frameWidthChoice = 40;
                        // printCentered(Choice, consoleWidth);
                        while(true){
                            // cout << "Enter selection: ";
                            printCenteredFrame(Choice, consoleWidth, frameWidthChoice);
                            cin >> choiceByAdmin;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "\033[31mInvalid selection! \033[0m" << endl;
                            }
                            else{
                                break;
                            }
                        }
                        cin.ignore(); 
                        switch (choiceByAdmin) {
                            case 1: {
                                system("cls");
                                cout << "Enter information for new staff " << endl;
                                STAFF newStaff;
                                newStaff.inputInformation();
                                staffList.push_back(newStaff);
                                cout << "\033[32m" << "New staff added successfully. " << "\033[0m" << endl; 
                                break;
                            }
                            case 2: {
                                system("cls");
                                cout << "+============Employee ID List===========+"<< endl;
                                int count = 0;
                                for(STAFF &staff : staffList){
                                    count++;
                                    cout << "|\t\t"<< staff.getIdStaff() << "\t\t|" << endl;
                                    if(staffList.size()!=static_cast<size_t>(count)){
                                        cout << "+---------------------------------------+" << endl;
                                    }
                                    
                                }
                                cout << "+=======================================+"<< endl;
                                cout << "Enter the staff ID to delete: ";
                                string idStaff;
                                getline(cin, idStaff);

                                bool deleted = false;

                                for (auto it = staffList.begin(); it != staffList.end(); ++it) {
                                    if (it->getIdStaff() == idStaff) {
                                        // Hiển thị thông tin nhân viên
                                        it->outputInformation();
                                        deleted = true;

                                        // Xác nhận xóa
                                        char c;
                                        cout << "Are you sure you want to delete that staff (Y/N)? ";
                                        cin >> c;
                                        cin.ignore(1000, '\n'); // Xóa bộ đệm

                                        if (c == 'y' || c == 'Y') {
                                            staffList.erase(it);
                                            cout << "\033[32mStaff deleted successfully.\033[0m" << endl;
                                        } else {
                                            cout << "\033[33mDeletion cancelled.\033[0m" << endl;
                                        }

                                        break; // Ngắt vòng lặp sau khi xử lý
                                    }
                                }

                                if (!deleted) {
                                    cout << "\033[31mThe ID entered does not exist!\033[0m" << endl;
                                }
                                break;
                            }
                            case 3: {
                                system("cls");
                                cout << "+============Employee ID List===========+"<< endl;
                                int count = 0;
                                for(STAFF &staff : staffList){
                                    count++;
                                    cout << "|\t\t"<< staff.getIdStaff() << "\t\t|" << endl;
                                    if(staffList.size()!=static_cast<size_t>(count)){
                                        cout << "+---------------------------------------+" << endl;
                                    }
                                    
                                }
                                cout << "+=======================================+"<< endl;
                                 cout << "Enter the staff ID whose information needs to be edited: ";
                                string IDStaff;
                                getline(cin, IDStaff);
                                bool found = false;

                                for (STAFF &updateStaff : staffList) {
                                    if (updateStaff.getIdStaff() == IDStaff) { 
                                        found = true;
                                        int updateChoice;
                                        do {
                                            cout << "\n\n+=========UPDATE OPTION=========+" << endl;
                                            cout << "|1. Update ID\t\t\t|" << endl;
                                            cout << "+-------------------------------+" << endl;
                                            cout << "|2. Update name\t\t\t|" << endl;
                                            cout << "+-------------------------------+" << endl;
                                            cout << "|3. Update day of birth\t\t|" << endl;
                                            cout << "+-------------------------------+" << endl;
                                            cout << "|4. Update gender\t\t|" << endl;
                                            cout << "+-------------------------------+" << endl;
                                            cout << "|5. Update job position\t\t|" << endl;
                                            cout << "+-------------------------------+" << endl;
                                            cout << "|6. Update login name\t\t|" << endl;
                                            cout << "+-------------------------------+" << endl;
                                            cout << "|7. Update Password\t\t|" << endl;
                                            cout << "+-------------------------------+" << endl;
                                            cout << "|8. Exit update\t\t\t|" << endl;
                                            cout << "+===============================+\n\n";
                                            while(true){
                                                cout << "Enter selection: ";
                                                cin >> updateChoice;
                                                if(cin.fail()){
                                                    cin.clear();
                                                    cin.ignore(1000, '\n');
                                                    cout << "\033[31m Invalid selection!\033[0m" << endl;
                                                }else{
                                                    break;
                                                }
                                            }
                                            cin.ignore(); 
                                            switch (updateChoice) {
                                                case 1:{
                                                    system("cls");
                                                    string newID;
                                                    while (true) {
                                                        cout << "Enter new staff ID: ";
                                                        cin >> newID;
                                                        if (newID.empty()) {
                                                            cout << "\033[31mID cannot be empty!\033[0m" << endl;
                                                            continue;
                                                        }
                                                        if (newID.length() < 8) {
                                                            cout << "\033[31mID must be at least 8 characters long!\033[0m" << endl;
                                                            continue;
                                                        }
                                                        bool valid = true, isAllDigits = true;
                                                        for (char c : newID) {
                                                            if (!isalnum(c) && c != '_' && c != '.') { 
                                                                valid = false;
                                                            }
                                                            if (!isdigit(c)) { 
                                                                isAllDigits = false;
                                                            }
                                                        }
                                                        if (!valid) {
                                                            cout << "\033[31mInvalid ID! Please enter an ID without special characters.\033[0m" << endl;
                                                            continue;
                                                        }
                                                        if (isAllDigits) {
                                                            cout << "\033[31mID cannot be all digits!\033[0m" << endl;
                                                            continue;
                                                        }
                                                        bool isDuplicate = false;
                                                        for (const STAFF& staff : staffList) {
                                                            if (staff.getIdStaff() == newID) {
                                                                isDuplicate = true;
                                                                break;
                                                            }
                                                        }
                                                        if (isDuplicate) {
                                                            cout << "\033[31mDuplicate Staff ID!\033[0m" << endl;
                                                            continue;
                                                        }
                                                        cout << "\033[32mID updated successfully!\033[0m" << endl;
                                                        updateStaff.setIdStaff(newID);
                                                        break;
                                                    }
                                                    break;
                                                }
                                                case 2: {
                                                    system("cls");
                                                    string newName;

                                                    while (true) {
                                                        cout << "Enter new name: ";
                                                        getline(cin, newName);
                                                        if (newName.empty()) {
                                                            cout << "\033[31m" << "Name cannot be empty!" << "\033[0m" << endl;
                                                            continue;
                                                        }
                                                        bool newWord = true;
                                                        for (size_t i = 0; i < newName.size(); ++i) {
                                                            if (isalpha(newName[i])) {
                                                                if (newWord) {
                                                                    newName[i] = toupper(newName[i]);  
                                                                    newWord = false;                  
                                                                } else {
                                                                    newName[i] = tolower(newName[i]); 
                                                                }
                                                            } else {
                                                                newWord = true; 
                                                            }
                                                        }
                                                        bool isDuplicate = false;
                                                        for (const STAFF& staff : staffList) {
                                                            if (newName == staff.getName()) {
                                                                isDuplicate = true;
                                                                break;
                                                            }
                                                        }
                                                        bool isValid = all_of(newName.begin(), newName.end(),[](char c) { return isalpha(c) || isspace(c); });
                                                        if (!isValid) {
                                                            cout << "\033[31m" << "Please enter letters only, no special characters or numbers!" << "\033[0m" << endl;
                                                        } else if (isDuplicate) {
                                                            cout << "\033[31m" << "Staff name is duplicated!" << "\033[0m" << endl;
                                                        } else {
                                                            updateStaff.setName(newName);
                                                            cout << "\033[32m" << "Name updated successfully!" << "\033[0m" << endl;
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    system("cls");
                                                    int newDay;
                                                    int newMonth;
                                                    int newYear;
                                                    do{
                                                        cout << "Enter day of birth (day/month/year): ";
                                                        cin >> newDay >> newMonth >> newYear;
                                                        if(cin.fail()){
                                                            cin.clear();
                                                            cin.ignore(1000, '\n');
                                                            cout <<  "\033[31m" << "Invalid Day Of Birth!" << "\033[0m" << endl;
                                                        }
                                                        bool check = newYear%4;
                                                        if(check==0){
                                                            if(newMonth == 2){
                                                                if(newDay > 29 || newDay <= 0){
                                                                    cout <<  "\033[31m" << "Please re-enter Day!" <<  "\033[0m"  << endl;
                                                                }
                                                                else{
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                        else if(newMonth <= 0 || newMonth > 12){
                                                            cout <<  "\033[31m" << "Please re-enter Month!" <<  "\033[0m"  << endl;
                                                        }
                                                        else if(newDay > 31 || newDay <= 0){
                                                            cout <<  "\033[31m" << "Please re-enter Day!" <<  "\033[0m"  << endl;
                                                        }
                                                    }while((newMonth <= 0 || newMonth > 12) || (newDay > 31 || newDay <= 0));
                                                    cin.ignore();
                                                    updateStaff.setDay(newDay); 
                                                    updateStaff.setDay(newMonth);
                                                    updateStaff.setDay(newYear);
                                                    cout << "\033[32m" << "Successful Day Of Birth Update." << "\033[0m" << endl; 
                                                    break;
                                                }
                                                case 4: {
                                                    system("cls");
                                                    string newGender;
                                                    do {
                                                        cout << "Enter new gender (Male/Female/Other): ";
                                                        getline(cin, newGender);
                                                        transform(newGender.begin(), newGender.end(), newGender.begin(), ::tolower);
                                                        if (newGender == "male" || newGender == "female" || newGender == "other") {
                                                            break;
                                                        } else {
                                                            cout << "\033[31m" << "Invalid gender! Please re-enter." << "\033[0m" << endl;
                                                        }
                                                    } while (true);
                                                    updateStaff.setGender(newGender);
                                                    logChange("Gender updated to: " + newGender);
                                                    cout << "\033[32m" << "Gender update successful." << "\033[0m" << endl;
                                                    break;
                                                }
                                                case 5: {
                                                    system("cls");
                                                    string newPosition;
                                                    do{
                                                        cout << "Enter new job position (Parttime/Fulltime): "; getline(cin, newPosition);
                                                        transform(newPosition.begin(), newPosition.end(), newPosition.begin(), ::tolower);
                                                        if(newPosition == "parttime" || newPosition == "fulltime"){
                                                            break;
                                                        }
                                                        else{
                                                            cout << "\033[31m" << "Wrong work position!" << "\033[0m" << endl;
                                                        }
                                                    }while(true);
                                                    updateStaff.setPosition(newPosition);
                                                    logChange("Job position updated to: " + newPosition);
                                                    cout << "\033[32m" << "Job position updated successfully." << "\033[0m" << endl;
                                                    break;
                                                }
                                                case 6: {
                                                    system("cls");
                                                    cout << "Enter new login name: ";
                                                    string newUserName;
                                                    getline(cin, newUserName);
                                                    updateStaff.setUserName(newUserName);
                                                    logChange("Login name updated to: " + newUserName);
                                                    cout << "\033[32m" << "Login name updated successfully." << "\033[0m" << endl;
                                                    break;
                                                }
                                                case 7: {
                                                    system("cls");
                                                    cout << "Enter new password: ";
                                                    string newPassWord;
                                                    getline(cin, newPassWord);
                                                    string encryptedPassword = encryptPassword(newPassWord);
                                                    updateStaff.setPassWord(encryptedPassword);
                                                    logChange("Password updated.");
                                                    cout << "\033[32m" << "Password updated successfully." << "\033[0m" << endl;
                                                    break;
                                                }
                                                case 8:
                                                    system("cls");
                                                    cout << "\033[31mExit information update.\033[0m" << endl;
                                                    break;
                                                default:
                                                    cout << "\033[31m" << "Invalid selection!" << "\033[0m" << endl;
                                            }
                                        } while (updateChoice != 8);

                                        break;
                                    }
                                }

                                if (!found) {
                                    cout << "\033[31m" << "The ID entered does not exist.!" << "\033[0m" << endl;
                                }
                                break;
                            }
                            case 4: {
                                system("cls");
                                if(staffList.empty()){
                                    cout << "\033[31mStaff list is empty!\033[0m" << endl;
                                }
                                for (const STAFF &temp : staffList) {
                                    temp.outputInformation();
                                    
                                }
                                break;
                            }
                            case 5:
                                system("cls");
                                // Them san pham vao menu
                                menu.additemInMenuListFromInput();
                                break;
                            case 6:
                                system("cls");
                                cout << "===========================MENU===========================" << endl;
                                menu.displayMenu();
                                break;
                            case 7:{
                                system("cls");
                                // Tìm sản phẩm bằng id
                                string id;
                                cout << "Enter the product ID you want to find: ";
                                cin >> id;
                                menu.findItemInMenuListById(id);
                                break;
                            }
                            case 8:{
                                system("cls");
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
                                system("cls");
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
                system("cls");
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
                    system("pause");
                    system("cls");
                    int choiceByStaff;
                    do{
                        cout << "\n\n+======== STAFF ========+" << endl;
                        cout << "|1. Checkin hour  \t|" << endl; 
                        cout << "+-----------------------+" << endl;
                        cout << "|2. Checkout hour  \t| " << endl;
                        cout << "+-----------------------+" << endl;
                        cout << "|3. View hours worked \t| " << endl;
                        cout << "+-----------------------+" << endl;
                        cout << "|4. View current salary\t| " << endl;
                        cout << "+-----------------------+" << endl;
                        cout << "|5. Log out \t\t|" << endl;
                        cout << "+-----------------------+" << endl;
                        while(true){
                            cout << "Enter selection: ";
                            cin >> choiceByStaff;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "\033[31m Invalid selection! \033[0m" << endl;
                            }else{
                                break;
                            }
                        }
                        switch(choiceByStaff){
                                case 1:
                                    system("cls");
                                    staff->checkIn();
                                    break;
                                case 2:
                                    system("cls");
                                    staff->checkOut();
                                    break;
                                case 3:
                                    system("cls");
                                    staff->displayTotalHours();
                                    break;
                                case 4:
                                    system("cls");
                                    staff->calculateSalary();
                                    break;
                                case 5:{
                                    system("cls");
                                    cout << "\033[32m" << "Logout successful. " << "\033[0m" << endl; 
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
                system("cls");
                cout << "=======================MENU======================" << endl;
                menu.displayMenu();
                CUSTOMER customer;          
                customer.orderItems(menu);
                int transactionCode = customer.generateTransactionID();
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
