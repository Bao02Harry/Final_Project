#include "Header.h"
void Color(int i ){
    SetConsoleTextAttribute((GetStdHandle), i);
}
// doc file CSV cua sinh vien
void ReadStudent(Student*& S, int& n) {
    S = new Student[100];
    ifstream file("Students.csv");
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return;
    }
        string line;
        string SNo;
        string SStuID;
        string SSocialID;
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
            getline(file, SSocialID, ',');
            S[n].SocialID = stoi(SSocialID);
            getline(file, S[n].Date, ',');
            S[n].Date = S[n].Date.substr(0, 2) + S[n].Date.substr(3, 2) + S[n].Date.substr(6, 2);
            getline(file, S[n].Class, ',');
            getline(file, S[n].Pass, ',');
            cout << S[n].No << endl;
            cout << S[n].StuID << endl;
            cout << S[n].Fname << endl;
            cout << S[n].Lname << endl;
            cout << S[n].Gen << endl;
            cout << S[n].SocialID << endl;
            cout << S[n].Date << endl;
            cout << S[n].Class << endl;
            cout << S[n].Pass << endl;
            n++;
        }
    file.close();
}

