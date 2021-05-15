#include "Header.h"
void Color(int i ){
    SetConsoleTextAttribute((GetStdHandle), i);
}
// doc file CSV cua sinh vien
void ReadStudent(ifstream& file, Student*& S, int& n) 
{
    char* line=nullptr;
    char* SNo=nullptr;
    char* SStuID=nullptr;
    char* SDate=nullptr;
    char* SSocialID=nullptr;
    n = 0;
    getline(file, line);
    S = (student*)malloc(1*sizeof(student));
    while(file.eof()==false)
    {
        S =(student*)realloc(S,(n+1)*sizeof(student));
        if (S==nullptr) return;
        getline(file,line);
        SNo=strtok(line,",");
        S[n].No=atoi(SNo);
        SStuID=strtok(NULL,",");
        S[n].StuID=atoi(SStuID);
        S[n].Fname=strtok(NULL,",");
        S[n].Lname=strtok(NULL,",");
        S[n].Gen=strtok(NULL,",");
        SDate=strtok(NULL,",");
        while(SDate!=NULL)
        {
            char* Sday=nullptr;
            char* Smonth=nullptr;
            char* Syear=nullptr;
            Sday= strtok(NULL,"/");
            S[n].Data.day = atoi(Sday);
            Smonth=strtok(NULL,"/");
            S[n].Data.month = atoi(Smonth);
            Syear=strtok(NULL,",/ ");
            S[n].Data.year=atoi(Syear); 
        }
        SSocialID=strtok(NULL,",");
        S[n].SocialID=atoi(SSocialID);
        S[n].Class=strtok(NULL,",");
        S[n].Pass=strtok(NULL,",");
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