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
    cout << "Enter full name: ";
    getline(cin, this->name);
    cout << "Enter age: ";
    cin >> this->age;
    cin.ignore();
    do {
        cout << "Enter gender (Male/Female/Other): ";
        getline(cin, this->gender);
        if (this->gender == "Male" || this->gender == "Female" || this->gender == "male" || this->gender == "female" || this->gender == "Other" || this->gender == "other") {
            break;
        }
        else {
            cout << "Invalid gender! Please re-enter." << endl;
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
    cout << "=========================INFORMATION=========================" << endl;
    cout << "Name\t\t\t gender\t\t Age\t\t" << endl;
    cout << name << "\t\t " << gender << "\t\t " << age << endl; 
}