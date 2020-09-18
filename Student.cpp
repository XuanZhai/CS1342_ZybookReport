//
// Created by Xuan Zhai on 2020/9/18.
//
#include "Student.h"

using namespace std;

Student::Student(){
    FirstName = "NULL";
    LastName = "NULL";
    Data = "NULL";
}

Student::Student(string& newFirst,string& newLast){
    FirstName = newFirst;
    LastName = newLast;
    Data = "NULL";
}

bool Student::Compare(std::string& newFirstName,std::string& newLastName) const{
    if(newFirstName == FirstName && newLastName == LastName)
        return true;
    else
        return false;
}

std::string Student::GetLastName(){
    return LastName;
}

std::string Student::GetFirstName(){
    return FirstName;
}

std::string Student::GetData(){
    return Data;
}

void Student::SetData(std::string newData){
    Data = newData;
}
