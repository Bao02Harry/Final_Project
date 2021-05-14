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
    string Date;
    int SocialID;
    string Class;
    string Pass;
};
struct Cours{

};
// Doc file CSV va luu vao cau truc 
void Color(int i );






#endif