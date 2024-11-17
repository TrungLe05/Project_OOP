#include"person.h"




PERSON::PERSON(){
    name = " ";
    age = 0;
    gender = " ";
}

PERSON::PERSON(string name, int age, string gender){
    this->age = age;
    this->name = name;
    this->gender = gender;
}

void PERSON::inputInformation() {
    while(true){
    cout << "Enter full name: ";
    getline(cin, this->name);
     if (!name.empty() && all_of(name.begin(), name.end(), [](char c) { return isalpha(c) || isspace(c); })) {
            break;
        } else {
            cout << "\033[31m" << "Please enter letters only, no special characters or numbers!" << "\033[0m"  << endl;
        }
    }
    while(true){
    cout << "Enter age: ";
    cin >> this->age;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<  "\033[31m" << "Invalid age!" << "\033[0m" << endl;
    }
    else if(age <= 0 || age >=100){
         cout <<  "\033[31m" << "Please re-enter age!" <<  "\033[0m"  << endl;
    }
    else{
        break;
        }
    }
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
void PERSON::setAge(int age){
    this->age = age;
}
void PERSON::setGender(string gender){
    this->gender = gender;
}

string PERSON::getName(){
    return name;
}
int PERSON::getAge(){
    return age;
}
string PERSON::getGender(){
    return gender;
}

void PERSON::outputInformation() const {
    cout << "+===================INFORMATION===================+" << endl;
    cout << "|Name\t\t\t gender\t\t Age\t  |" << endl;
    cout <<"|"<< name << "\t\t " << gender << "\t\t " << age << "\t  |" << endl; 
}