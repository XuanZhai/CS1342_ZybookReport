//
// Created by Xuan Zhai on 2020/9/18.
//

#ifndef CS1342_ZYBOOKREPORT_STUDENT_H
#define CS1342_ZYBOOKREPORT_STUDENT_H

#include <iostream>
#include <string>

class Student{
    private:
        std::string LastName;
        std::string FirstName;
        std::string Data;
    public:
        Student();
        Student(std::string&,std::string&);
        bool Compare(std::string&,std::string&) const;
        std::string GetLastName();
        std::string GetFirstName();
        std::string GetData();
        void SetData(std::string);
};

#endif //CS1342_ZYBOOKREPORT_STUDENT_H
