#include "Header.h"
void Color(int i) {
    SetConsoleTextAttribute((GetStdHandle), i);
}
// Toa do 
void gotoxy(int x, int y) {
    HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coor = { x,y };
    SetConsoleCursorPosition(color, coor);
}
//To mau 
void Paint(int x, int y, string a, int color) {
    gotoxy(x, y);
    Color(color);
    cout << a;
    Color(7);
}
// Dem phan tu cua danh sach hco sinh
int countStu() {
    int count = 0;
    errno_t err;
    FILE* file;
    err = fopen_s(&file, "Students.csv", "r");
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
}

// chuyen chuoi sang so
int change(string s) {
    int n = s.length();
    int re = 0;
    for (int i = 0; i < n; i++) {
        switch (s[n - 1 - i]) {
        case '0': re += 0 * pow(10, i); break;
        case '1': re += 1 * pow(10, i); break;
        case '2': re += 2 * pow(10, i); break;
        case '3': re += 3 * pow(10, i); break;
        case '4': re += 4 * pow(10, i); break;
        case '5': re += 5 * pow(10, i); break;
        case '6': re += 6 * pow(10, i); break;
        case '7': re += 7 * pow(10, i); break;
        case '8': re += 8 * pow(10, i); break;
        case '9': re += 9 * pow(10, i); break;
        }
    }
    return re;
}
// doc file CSV cua sinh vien
void ReadStudent(Student*& S, int& n) {
    S = new Student[countStu()];
    ifstream file("Students.csv");
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return;
    }
    string line;
    string SNo;
    string SSocialID;
    string SDate;
    string day;
    string month;
    string year;
    int i = 0;
    getline(file, line);
    while (file) {
        getline(file, SNo, ',');
        getline(file, S[i].StuID, ',');
        getline(file, S[i].Fname, ',');
        getline(file, S[i].Lname, ',');
        getline(file, S[i].Gen, ',');
        getline(file, day, '/');
        getline(file, month, '/');
        getline(file, year, ',');
        getline(file, SSocialID, ',');
        getline(file, S[i].Class, ',');
        getline(file, S[i].Pass);

        S[i].No = change(SNo);
        S[i].day = change(day);
        S[i].month = change(month);
        S[i].year = change(year);
        S[i].SocialID = change(SSocialID);
        i++;
    }
    n = i - 1;
    cout << n << endl;
    file.close();
}
// Xuat toan bo file

void Print(Student* S, int n) {
    for (int i = 0; i < n; i++) {
        cout << S[i].No << endl;
        cout << S[i].StuID << endl;
        cout << S[i].Fname << endl;
        cout << S[i].Lname << endl;
        cout << S[i].Gen << endl;
        cout << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
        cout << S[i].SocialID << endl;
        cout << S[i].Class << endl;
        cout << S[i].Pass << endl;
    }
}
// Xuat 1 phan tu 
void PrintElement(Student* S, int i) {
    cout << S[i].No << endl;
    cout << S[i].StuID << endl;
    cout << S[i].Fname << endl;
    cout << S[i].Lname << endl;
    cout << S[i].Gen << endl;
    cout << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
    cout << S[i].SocialID << endl;
    cout << S[i].Class << endl;
    cout << S[i].Pass << endl;
}

//---------------------------------------------Ma hoa mat khau khi dang nhap---------------------------------------
void encode(string& s) {
    char ch;
    int dem = 0;
    while ((ch = getch()) != 13) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            cout << "*";
            s[dem++] = ch;

        }
        else
            if (ch == 8)
                if (dem > 0) {
                    cout << "\b \b";
                    dem--;
                }

    }
    s[dem] = 0;
}
// kiem tra tai khoan dang nhap
bool CheckPass(Student* S, int n, int& pos, string user, string Pass) {
    for (int i = 0; i < n; i++) {
        pos = i;
        if (S[i].StuID == user && S[i].Pass == Pass)
            return true;
    }
    return false;
}