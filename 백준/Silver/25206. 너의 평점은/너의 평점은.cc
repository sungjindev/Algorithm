#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
    string str1,subject,grade;
    double totalPoint=0;
    double point;
    double gpa = 0;
    
    for(int i=0; i<20; i++) {
        getline(cin,str1);
        stringstream ss(str1);
        ss >> subject >> point >> grade;

        if(grade == "A+") {
            gpa += point * 4.5;
            totalPoint += point; 
        } else if(grade == "A0") {
            gpa += point * 4.0;
            totalPoint += point;
        } else if(grade == "B+") {
            gpa += point * 3.5;
            totalPoint += point;
        } else if(grade == "B0") {
            gpa += point * 3.0;
            totalPoint += point;
        } else if(grade == "C+") {
            gpa += point * 2.5;
            totalPoint += point;
        } else if(grade == "C0") {
            gpa += point * 2.0;
            totalPoint += point;
        } else if(grade == "D+") {
            gpa += point * 1.5;
            totalPoint += point;
        } else if(grade == "D0") {
            gpa += point * 1.0;
            totalPoint += point;
        } else if(grade == "F") {
            totalPoint += point;
        }
    }
    gpa = gpa != 0 ? gpa/totalPoint : 0;
    cout << gpa;

    return 0;
}

