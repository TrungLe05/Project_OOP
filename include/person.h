#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
using namespace std;
// Class PERSON
// tạo lớp person để staff và customer kế thừa thay vì phải thêm các thuộc tính name, age, sex vào từng class staff và customer
class PERSON{
    private:
        string name;
        int age;
        string gender;
    public:
        PERSON();
        PERSON(string name, int age, string gender);
        void inputInformation();
        void setName(string name);
        void setAge(int age);
        void setGender(string gender);
        string getName();
        int getAge();
        string getGender();
        virtual void outputInformation() const;

};

#endif