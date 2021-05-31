#ifndef Header_h
#define Header_h
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <string.h>
#include <cmath>
#include <time.h>
using namespace std;
struct Teacher {
    int No;// so thu tu
    int TeID;
    string Fname;
    string Lname;
    string Gen;
    int SocialID; // CMND
    string pass;
};

struct Student {
    int No;
    string StuID;
    string Fname;
    string Lname;
    string Gen;
    int day, month, year;
    int SocialID;
    string Class;
    string Pass;
};

struct Cours {

};
void Color(int i);
void gotoxy(int x, int y);
void Paint(int x, int y, string a, int color);
int change(string s);
void ReadStudent(Student*& S, int& n);
void PrintStudent(Student* S, int n);
void PrintElement(Student* S, int i);
void encode(string& s);
bool CheckPass(Student* S, int n, int& pos, string user, string Pass);

// Doc file CSV va luu vao cau truc 







#endif
