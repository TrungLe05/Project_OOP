#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
#include <cctype>
#include <algorithm>
using namespace std;
// Class PERSON
// tạo lớp person để staff và customer kế thừa thay vì phải thêm các thuộc tính name, age, sex vào từng class staff và customer
class PERSON{
    private:
        string name;
        int day;
        int month;
        int year;
        string gender;
    public:
        PERSON();
        PERSON(string name, int age, int month, int year, string gender);
        PERSON(int day, int month,int year,string gender);
        void inputInformation();
        void setName(string name);
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        void setGender(string gender);
        string getName()const;
        int getDay();
        int getMonth();
        int getYear();
        string getGender();
        virtual void outputInformation() const;

};
#endif