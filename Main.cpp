#include "Header.h"

int main(){
    system("cls");
    Student*S;
    int n=0;
    ifstream f1;
    ofstream f2;
    f1.open("Student.csv",ios_base::in);
    if(f1.fail())
    {
        cout <<"Cannot read file"<<endl;
        return 0;
    }
    ReadStudent(f1,S,n);
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
    f1.close();

    system("pause");
    return 0;
}
