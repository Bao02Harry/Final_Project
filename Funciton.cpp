#include "Header.h"
void Color(int i ){
    SetConsoleTextAttribute((GetStdHandle), i);
}
// doc file CSV cua sinh vien
void ReadStudent(ifstream& file, Student*& S, int& n) 
{
    string line;
    string SNo;
    string SStuID;
    string SSocialID;
    string SDate;
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
        getline(file, SDate, ',');
        while(SDate!=NULL)
        {
            
        }
        getline(file, S[n].Class, ',');
        getline(file, S[n].Pass, ',');
        cout << S[n].No << endl;
        cout << S[n].StuID << endl;
        cout << S[n].Fname << endl;
        cout << S[n].Lname << endl;
        cout << S[n].Gen << endl;
        cout << S[n].SocialID << endl;
        cout << S[n].Data.day<<"/"<<S[n].Data.month<<"/"<<S[n].Data.year << endl;
        cout << S[n].Class << endl;
        cout << S[n].Pass << endl;
        n++;
    }
}

void WriteStudent(ofstream& file,Student* S,int n)
{
    for(int i=0;i<n;i++)
    {
    cout << S[i].No << ", ";
    cout << S[i].StuID << ", ";
    cout << S[i].Fname << ", ";
    cout << S[i].Lname << ", ";
    cout << S[i].Gen << ", ";
    cout << S[i].SocialID << ", ";
    cout << S[i].Data.day<<"/"<<S[i].Data.month<<"/"<<S[i].Data.year << ", ";
    cout << S[i].Class << ", ";
    cout << S[i].Pass << endl;
    }
}