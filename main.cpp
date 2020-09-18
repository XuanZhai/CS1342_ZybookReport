#include "Analyzer.h"


int main() {
    Analyzer newAnalyzer;

    newAnalyzer.ReadNameList();
    newAnalyzer.ReadReport();
    newAnalyzer.PrintOutput();
    
    return 0;
}
