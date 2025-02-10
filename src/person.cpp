#include"person.h"



PERSON::PERSON(){
    name = " ";
    day = month = year = 0;
    gender = " ";
}

PERSON::PERSON(string name, int day, int month, int year, string gender){
    this->name = name;
    this->day = day;
    this->gender = gender;
    this->month = month;
    this->year = year;
}
void PERSON::inputInformation() {
    while(true){
    cout << "Enter full name: ";
        getline(cin, name);
        if (!name.empty() && all_of(name.begin(), name.end(), [](char c) { return isalpha(c) || isspace(c); })) {
            bool newWord = true;
            for (size_t i = 0; i < name.size(); ++i) {
                if (isalpha(name[i])) {
                    if (newWord) {
                        name[i] = toupper(name[i]);  
                        newWord = false;  
                    }
                } else {
                    newWord = true;  
                }
            }
            break;
        } else {
            cout << "\033[31m" << "Please enter letters only, no special characters or numbers!" << "\033[0m" << endl;
        }
    }
    do{
        cout << "Enter day of birth (day/month/year): ";
        cin >> day >> month >> year;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout <<  "\033[31m" << "Invalid age!" << "\033[0m" << endl;
        }
        bool check = year%400;
        if(check==0){
            if(month == 2){
                if(day >= 29 || day <= 0){
                    cout <<  "\033[31m" << "Please re-enter age!" <<  "\033[0m"  << endl;
                }
                else{
                    break;
                }
            }
        }
        else if(month <= 0 || month >= 12){
            cout <<  "\033[31m" << "Please re-enter age!" <<  "\033[0m"  << endl;
        }
        else if(day >= 31 || day <= 0){
            cout <<  "\033[31m" << "Please re-enter age!" <<  "\033[0m"  << endl;
        }
    }while((month <= 0 || month >= 12) || (day >= 31 || day <= 0));
    cin.ignore();
    do {
        cout << "Enter gender (Male/Female/Other): ";
        getline(cin, this->gender);
        if (this->gender == "Male" || this->gender == "Female" || this->gender == "male" || this->gender == "female" || this->gender == "Other" || this->gender == "other") {
            break;
        }
        else {
            cout << "\033[31m" << "Invalid gender! Please re-enter." << "\033[0m" << endl;
        }
    } while (true);
}

void PERSON::setName(string name){
    this->name = name;
}
void PERSON::setDay(int day){
    this->day = day;
}
void PERSON::setMonth(int month){
    this->month = month;
}
void PERSON::setYear(int year){
    this->year = year;
}
void PERSON::setGender(string gender){
    this->gender = gender;
}

string PERSON::getName()const{
    return name;
}
int PERSON::getDay(){
    return day;
}
int PERSON::getMonth(){
    return month;
}
int PERSON::getYear(){
    return year;
}
string PERSON::getGender(){
    return gender;
}

void PERSON::outputInformation() const {
    cout << "+=======================INFORMATION=======================+" << endl;
    cout << "|Name\t\t\t gender\t\t day of birth\t  |" << endl;
    cout <<"|"<< name << "\t\t " << gender << "\t\t " << day << "/" << month << "/" << year << "\t  |" << endl; 
}
