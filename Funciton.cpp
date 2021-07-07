#include "Header.h"
void Color(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
// Toa do 
void gotoxy(int x, int y) {
    HANDLE color;
    color = GetStdHandle;
    COORD coor = { x,y };
    SetConsoleCursorPosition(color, coor);
}
//To mau 
void Paint(int x, int y, string a, int color) {
    gotoxy(x, y);
    Color(color);
    cout << a;
}
// Dem phan tu cua danh sach hoc sinh
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
    file.close();
}

// Dem phan tu cua danh sach giao vien
int countTech() {
    int count = 0;
    ifstream infile;
    infile.open("Teachers.csv");
    if (!infile.is_open()) {
        return 0;
    }
    string line;
    getline(infile, line);
    while (infile) {
        getline(infile, line);
        count++;
    }
    infile.close();
    return count;
}

// doc file CSV cua giao vien
void ReadTeacher(Teacher*& T, int& n) {
    T = new Teacher[countTech()];
    ifstream file("Teachers.csv");
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return;
    }
    string line;
    string SNo;
    string SSocialID;
    int i = 0;
    getline(file, line);
    while (file) {
        getline(file, SNo, ',');
        getline(file, T[i].TeID, ',');
        getline(file, T[i].Fname, ',');
        getline(file, T[i].Lname, ',');
        getline(file, T[i].Gen, ',');
        getline(file, SSocialID, ',');
        getline(file, T[i].Faculty, ',');
        getline(file, T[i].Pass);

        T[i].No = change(SNo);
        T[i].SocialID= change(SSocialID);
        i++;
    }
    n = i - 1;
    file.close();
}
// Xuat toan bo file sinh vien
void PrintStu(Student* S, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien." << endl;
        cout << "So thu tu: " << S[i].No << endl;
        cout << "MSSV: " << S[i].StuID << ". Ho ten: " << S[i].Fname << " " << S[i].Lname << endl;
        cout << "Gioi tinh: " << S[i].Gen << ". Nam sinh: " << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
        cout << "CMND: "<< S[i].SocialID << ". Lop: " << S[i].Class << endl;
    }
}
// Xuat 1 phan tu sinh vien
void PrintElementStu(Student* S, int i) {
    cout << "So thu tu: " << S[i].No << endl;
    cout << "MSSV: " << S[i].StuID << ". Ho ten: " << S[i].Fname << " " << S[i].Lname << endl;
    cout << "Gioi tinh: " << S[i].Gen << ". Nam sinh: " << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
    cout << "CMND: " << S[i].SocialID << ". Lop: " << S[i].Class << endl;
}

//---------------------------------------------Ma hoa mat khau khi dang nhap---------------------------------------
void encode(string& s) {
    char ch;
    int dem = 0;
    while ((ch = _getch()) != 13) {
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
    cout << s << endl;
}
// kiem tra tai khoan dang nhap sinh vien
bool CheckPassStu(Student* S, int n, int& pos, string user, string Pass) {
    for (int i = 0; i < n; i++) {
        pos = i;
        if (S[i].StuID == user && S[i].Pass == Pass)
            return true;
    }
    return false;
}

// kiem tra tai khoan dang nhap giao vien
bool CheckPassTech(Teacher* T, int m, int& pos, string user, string Pass) {
    for (int i = 0; i < m; i++) {
        pos = i;
        if (T[i].TeID == user && T[i].Pass == Pass)
            return true;
    }
    return false;
}

// Xuat toan bo file giao vien
void PrintTech(Teacher * T, int m) {
    for (int i = 0; i < m; i++) {
        cout << "Giao vien." << endl;
        cout << "So thu tu: " << T[i].No << endl;
        cout << "MSGV: " << T[i].TeID << ". Ho ten: " << T[i].Fname << " " << T[i].Lname << endl;
        cout << "Gioi tinh: " << T[i].Gen << ". CMND: " << T[i].SocialID << ". Khoa: " << T[i].Faculty << endl;
    }
}
// Xuat 1 phan tu giao vien
void PrintElementTech(Teacher* T, int i) {
    cout << "Giao vien." << endl;
    cout << "So thu tu: " << T[i].No << endl;
    cout << "MSGV: " << T[i].TeID << ". Ho ten: " << T[i].Fname << " " << T[i].Lname << endl;
    cout << "Gioi tinh: " << T[i].Gen << ". CMND: " << T[i].SocialID << ". Khoa: " << T[i].Faculty << endl;
}
// Dinh dang
void Format(string s) {
    system("cls");
    Color(14);
    cout << "\n\t\t\t ****************************" << endl;
    cout << "\t\t\t\t      ";
    Color(10);
    cout << s << endl;
    Color(14);
    cout << "\t\t\t ****************************" << endl;
}

// Nhap du lieu vao
void input(string& user, string& pass) {
    cin.ignore();
    Paint(15, 20, "ID of User: ", 10);
    getline(cin, user);
    cin.ignore();
    Paint(15, 20, "Password: ", 10);
    getline(cin, pass);
}
 // cap nhat thong tin ca nhan giao vien
void UpdateInforTeach(Teacher*& T,int m, string ID) {
    Teacher Temp;
    Format("Update information");
    cin.ignore();
    cout << "+ Please, Input your personal information." << endl;
    cout << "Your ID: ";
    getline(cin, Temp.TeID);
    cout << "Your first name: ";
    getline(cin, Temp.Fname);
    cout << "Your last name: ";
    getline(cin, Temp.Lname);
    cout << "Your Gender: ";
    getline(cin, Temp.Gen);
    cout << "Your Faculty: ";
    getline(cin, Temp.Faculty);
    cout << "Your social id: ";
    cin >> Temp.SocialID;
    for (int i = 0; i < m; i++) {
        if (T[i].TeID == ID) {
            T[i].TeID = Temp.TeID;
            T[i].Fname = Temp.Fname;
            T[i].Lname = Temp.Lname;
            T[i].Gen = Temp.Gen;
            T[i].Faculty = Temp.Faculty;
            T[i].SocialID = Temp.SocialID;
        }
    }
}

void changepass(Teacher*& T, int m, string ID)
{
    Teacher Temp;
    cin.ignore();
    Paint(15, 20, "Enter your password: ", 10);
    getline(cin, Temp.Pass);
    for (int i = 0; i < m; i++)
        if (T[i].TeID == ID)
        {
            if (Temp.Pass == T[i].Pass)
            {
                cin.ignore();
                Paint(15, 20, "Enter new password: ", 10);
                getline(cin, Temp.Pass);
                T[i].Pass = Temp.Pass;
            }
            else cout << "Wrong password\n";
        }

}

// ghi lai file sau khi cap nhap
void WriteAfterUdateTeach(Teacher* T, int m) {
    ofstream outfile;
    outfile.open("Teacher1.csv");
    if (!outfile.is_open()) {
        cout << "Can not open file" << endl;
        return;
    }
    outfile << "No" << "," << "Teacher ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Social ID" << "," << "Faculty" << "," << "Password" << endl;
    for (int i = 0; i < m; i++) {
        outfile << T[i].No << "," << T[i].TeID << "," << T[i].Fname << "," << T[i].Lname << "," << T[i].Gen << "," << T[i].SocialID << "," << T[i].Faculty << "," << T[i].Pass << endl;
    }
    outfile.close();
}
// Dem phan tu cua danh sach khoa hoc
int countCourses() {
    int count = 0;
    ifstream infile;
    infile.open("course.csv");
    if (!infile.is_open()) {
        return 0;
    }
    string line;
    getline(infile, line);
    while (infile) {
        getline(infile, line);
        count++;
    }
    infile.close();
    return count;
}

// doc file courses
void ReadCourses(Courses*& C, int& t) {
    t = countCourses();
    C = new Courses[t];
    ifstream infile;
    infile.open("course.csv");
    if (!infile.is_open()) {
        return;
    }
    int i = 0;
    string line;
    getline(infile, line);
    while (infile) {
        getline(infile, C[i].ID, ',');
        getline(infile, C[i].CName, ',');
        getline(infile, C[i].TName, ',');
        string tempCredit;
        getline(infile, tempCredit, ',');
        C[i].Credits = change(tempCredit);
        string tempMax;
        getline(infile, tempMax, ',');
        C[i].MaxMem = change(tempMax);
        string tempday1;
        getline(infile, tempday1, ',');
        C[i].day1 = change(tempday1);
        getline(infile, C[i].session1, ',');
        string tempday2;
        getline(infile, tempday2, ',');
        C[i].day2 = change(tempday2);
        getline(infile, C[i].session2);
        i++;
    }
    infile.close();
}
void PrintCourses(Courses* C, int t) {
    for (int i = 0; i < t; i++) {
        cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].CName << endl;
    }
}