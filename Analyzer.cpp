//
// Created by Xuan Zhai on 2020/9/18.
//
#include "Analyzer.h"

using namespace std;


Analyzer::Analyzer(){

}


void Analyzer::ReadNameList(){
    ifstream NameList("NameList.csv");
    if(!NameList){
        cout << "Unable to find NameList..." << endl;
        exit(1);
    }
    string temp;
    getline(NameList, temp, '\n');
    while (!NameList.eof()){
        string Index, LastName,FirstName;
        getline(NameList, Index, ',');
        if(Index.length() == 0){
            break;
        }
        getline(NameList, FirstName, ',');
        std::transform(FirstName.begin(), FirstName.end(), FirstName.begin(),[](unsigned char c){ return std::tolower(c); });       // Change to lowercase
        getline(NameList, LastName, '\n');
        std::transform(LastName.begin(), LastName.end(), LastName.begin(),[](unsigned char d){ return std::tolower(d); });
        Student newStudent(FirstName,LastName);
        StudentList.push_back(newStudent);
    }
    NameList.close();
}


void Analyzer::ReadReport() {
    vector<string> FileNames = GetPathFile();
    for(int i = 2; i < FileNames.size(); i++){
        ifstream newReport("src/"+ FileNames.at(i));            // Read reports in the src in cmake-build-debug
        if(!newReport){
            cout << "Unable to find "<< FileNames.at(i) << "..." << endl;
            exit(1);
        }

        string templast, tempfirst, tempemail, tempsection,temp;
        bool hasSection = true;
        getline(newReport,templast,',');
        getline(newReport,tempfirst,',');
        getline(newReport,tempemail,',');
        getline(newReport,tempsection,',');
        getline(newReport,temp,'\n');
        if(tempsection != "Class section"){                 // Check if there is a Class section in the header in report
            hasSection = false;
            OutputTitle = "Lab section," + templast + "," + tempfirst + "," + tempemail + ",Class section," + tempsection + "," + temp;
        }
        else{
            OutputTitle = "Lab section," +  templast + "," + tempfirst + "," + tempemail + "," + tempsection + "," + temp;
        }
        while (!newReport.eof()){
            string FirstName,LastName,Email, Section,Data;
            getline(newReport,LastName,',');
            std::transform(LastName.begin(), LastName.end(), LastName.begin(),[](unsigned char d){ return std::tolower(d); });
            getline(newReport,FirstName,',');
            std::transform(FirstName.begin(), FirstName.end(), FirstName.begin(),[](unsigned char c){ return std::tolower(c); });
            getline(newReport,Email,',');
            getline(newReport,Section,',');
            getline(newReport,Data,'\n');
            if(hasSection == false){
                Data = Email + ",Need a Section," + Section  + "," + Data;
            }
            else{
                Data = Email  + "," + Section  + "," + Data;
            }
            AnalysisReport(FirstName,LastName,Data);
        }
    }
}


void Analyzer::PrintOutput(){
    string filename, Labsection;
    cout << "Please enter the output filename (with .csv):";
    getline(cin,filename);
    cout << "Please enter your lab section:";
    getline(cin,Labsection);

    ofstream OutPutFile(filename);
    if(!OutPutFile){
        cout << "Unable to create "<< filename << "..." << endl;
        exit(1);
    }

    OutPutFile << OutputTitle << endl;
    for(int i = 0; i < StudentList.size(); i++){
        OutPutFile << Labsection + "," << StudentList.at(i).GetLastName() + "," + StudentList.at(i).GetFirstName() + "," + StudentList.at(i).GetData() << endl;
    }
    OutPutFile.close();
}


vector<string> Analyzer::GetPathFile(){  // Read documents' names from a path
    DIR *dir;
    vector<string> filenames;
    struct dirent *ent;
    if ((dir = opendir ("src\\")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            filenames.push_back(ent->d_name);
        }
        closedir (dir);
    } else {
        cout << "Could not open the src directory" << endl;
        exit(1);
    }
    return  filenames;
}


void Analyzer::AnalysisReport(std::string& FirstName,std::string& LastName,std::string& Data){  // Final the student with same firstname and lastname, insert data.
    for(int i = 0; i < StudentList.size(); i++){
        if(StudentList.at(i).Compare(FirstName,LastName) == true){
            StudentList.at(i).SetData(Data);
            break;
        }
    }
}