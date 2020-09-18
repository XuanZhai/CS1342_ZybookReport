//
// Created by Xuan Zhai on 2020/9/18.
//

#ifndef CS1342_ZYBOOKREPORT_ANALYZER_H
#define CS1342_ZYBOOKREPORT_ANALYZER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <dirent.h>
#include "Student.h"


class Analyzer{
    private:
        std::vector<Student> StudentList;       // Store all the students in the lab section
        std::string OutputTitle;            // Store the header of the output file
    public:
        Analyzer();
        void ReadNameList();
        void ReadReport();
        void AnalysisReport(std::string&,std::string&,std::string&);
        void PrintOutput();
        std::vector<std::string> GetPathFile();         // Read all the files' names in the folder
    };





#endif //CS1342_ZYBOOKREPORT_ANALYZER_H
