#ifndef Header_h
#define Header_h
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cmath>
#include <time.h>
#include <sstream>
using namespace std;
struct Date{
    int day,month,year;
};
struct Teacher{
    int No;// so thu tu
    int TeID;
    string Fname;
    string Lname;
    string Gen; 
    int SocialID; // CMND
    string pass;
};
struct Student{
    int No; 
    int StuID;
    string Fname;
    string Lname;
    string Gen; 
    Date Data;
    int SocialID;
    string Class;
    string Pass;
};
struct Cours{

};
void ReadStudent(ifstream& file, Student*& S, int& n); 
void WriteStudent(ofstream& file,Student* S,int n);
// Doc file CSV va luu vao cau truc 
void Color(int i );






#endif