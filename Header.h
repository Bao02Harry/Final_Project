#ifndef Header_h
#define Header_h
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <time.h>
using namespace std;
struct Teacher{
    int* No;// so thu tu
    int* TeID;
    string Fname;
    string Lname;
    string Gen; 
    int* SocialID; // CMND
};
struct Student{
    int* No; 
    int* StuID;
    string Fname;
    string Lname;
    string Gen; 
    string Date;
    int* SocialID;
};

void Color(int i );






#endif