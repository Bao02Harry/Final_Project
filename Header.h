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
#include <malloc.h>

using namespace std;
struct Teacher {
    int No;// so thu tu
    string TeID;
    string Fname;
    string Lname;
    string Gen;
    int SocialID; // CMND
    string Faculty;
    string Pass;
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

struct Courses {
    int Credits;
    int MaxMem;
    int daystart;
    int monthstart;
    int dayend;
    int monthend;
    string ID;
    string CName;
    string TName;
    string day1;
    string session1;
    string day2;
    string session2;
};

struct StuCourses {
    int No;
    string StuID;
    string Fname;
    string Lname;
    string Gen;
    string Class;
    string CouID;
    string Cname;
    int credits;
    string Tname;
    string day1;
    string session1;
    string day2;
    string session2;
    int daystart;
    int monthstart;
    int dayend;
    int monthend;
};

void Color(int i);
void gotoxy(int x, int y);
void Paint(int x, int y, string a, int color);
int change(string s);


int countStu();
void ReadStudent(Student*& S, int& n);
void PrintStu(Student* S, int n);
void PrintElementStu(Student* S, int i);


int countTech();
void ReadTeacher(Teacher*& T, int& n);
void PrintTech(Teacher* T, int m);
void PrintElementTech(Teacher* T, int i);


void encode(string& s);


bool CheckPassTech(Teacher* T, int m, int& pos, string user, string Pass);
bool CheckPassStu(Student* S, int n, int& pos, string user, string Pass);

// Cap nhat thong tin giao vien
void UpdateInforTeach(Teacher*& T, int m, string ID);
void WriteAfterUdateTeach(Teacher* T, int m);
void changepassteacher(Teacher*& T, int m, string ID);

void Format(string s);
void input(string& user, string& pass);
// Doc file CSV courses 
int countCourses();
void ReadCourses(Courses*& C, int& t);
void PrintCourses(Courses* C, int t);
bool CheckTimeInput(int day, int month);
bool checkdate(Courses* C, int i, int day, int month);
void CreateCourse(Courses*& C, int& t);
void registerCourses(Courses* &C, int& t);
void WriteCourse(Courses* C, int t);
void UpdateCourse(Courses*& C, int t);

//Cap nhap thong tin sinh vien
void UpdateInforStu(Student*& S, int n, string ID);
void changepassstu(Student*& S, int n, string ID);
void WriteAfterUdateStu(Student* S, int n);

//Cap nhat khoa hoc sinh vien
int countStuC();
void ReadStuC(StuCourses*& SC, int& p);
void PrintStuC(StuCourses* SC, int p);
void PrintElementStuC(StuCourses* SC, int i);
void WriteAfterUdateStuC(StuCourses* SC, int p);


#endif
