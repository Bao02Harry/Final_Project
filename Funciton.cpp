#include "Header.h"
void Color(int i ){
    SetConsoleTextAttribute((GetStdHandle), i);
}
// doc file CSV cua sinh vien
int countStu() {
    int count = 0;
    errno_t err;
    FILE* file = nullptr;
    err = fopen_s(&file, "Students.csv" , "r");
    if (file == NULL) {
        return 0;
    }
    else {
        while (!feof(file)) {
            char c;
            c = fgetc(file);
            if (c == ',') count++;
        }
    }
    return count / 8;
}/*
void ReadStudent(ifstream& file, Student*& S, int& n)
{
    string line;
    string SNo = nullptr;
    string  SStuID;
    string  SDate ;
    string SSocialID ;
    n = 0;
    getline(file, line);
    S = (Student*)malloc(1 * sizeof(Student));
    while (file.eof() == false)
    {
        S = (Student*)realloc(S, (n + 1) * sizeof(Student));
        if (S == nullptr) return;
        getline(file, line);
        SNo = strtok(line, ",");
        S[n].No = atoi(SNo);
        SStuID = strtok(NULL, ",");
        S[n].StuID = atoi(SStuID);
        S[n].Fname = strtok(NULL, ",");
        S[n].Lname = strtok(NULL, ",");
        S[n].Gen = strtok(NULL, ",");
        SDate = strtok(NULL, ",");
        while (SDate != NULL)
        {
            char* Sday = nullptr;
            char* Smonth = nullptr;
            char* Syear = nullptr;
            Sday = strtok(NULL, "/");
            S[n].Date.day = atoi(Sday);
            Smonth = strtok(NULL, "/");
            S[n].Data.month = atoi(Smonth);
            Syear = strtok(NULL, ",/ ");
            S[n].Data.year = atoi(Syear);
        }
        SSocialID = strtok(NULL, ",");
        S[n].SocialID = atoi(SSocialID);
        S[n].Class = strtok(NULL, ",");
        S[n].Pass = strtok(NULL, ",");
        n++;
    }
}

void WriteStudent(ofstream& file, Student* S, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << S[i].No << ", ";
        cout << S[i].StuID << ", ";
        cout << S[i].Fname << ", ";
        cout << S[i].Lname << ", ";
        cout << S[i].Gen << ", ";
        cout << S[i].SocialID << ", ";
        cout << S[i].Date.day << "/" << S[i].Date.month << "/" << S[i].Date.year << ", ";
        cout << S[i].Class << ", ";
        cout << S[i].Pass << endl;
    }
}*/

void ReadStudent(Student*& S, int& n) {
    S = new Student[countStu()];
    ifstream file("Students.csv");
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return;
    }
        string line;
        string SNo;
        string SStuID;
        string SSocialID;
        string SDate;
        string day;
        string month;
        string year;
        n = 0;
        getline(file, line);
        while (!file.eof()) {
            getline(file, SNo, ',');
            S[n].No = stoi(SNo);
            getline(file, SStuID, ',');
            S[n].StuID = stoi(SStuID);
            getline(file, S[n].Fname, ',');
            getline(file, S[n].Lname, ',');
            getline(file, S[n].Gen, ',');
            getline(file, day, '/');
            getline(file, month, '/');
            getline(file, year, ',');
            S[n].day = stoi(day);
            S[n].month = stoi(month);
            S[n].year = stoi(year);
            getline(file, SSocialID, ',');
            S[n].SocialID = stoi(SSocialID);
            getline(file, S[n].Class, ',');
            getline(file, S[n].Pass, ',');
            cout << S[n].No << endl;
            cout << S[n].StuID << endl;
            cout << S[n].Fname << endl;
            cout << S[n].Lname << endl;
            cout << S[n].Gen << endl;
            cout << S[n].day << "/" << S[n].month << "/" << S[n].year << endl;
            cout << S[n].SocialID << endl;
            cout << S[n].Class << endl;
            cout << S[n].Pass << endl;
            n++;
        }
        n--;
        cout << n << endl;
    file.close();
}