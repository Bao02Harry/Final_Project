
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
void ReadStudent(Student * &S, int& n) {
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
void ReadTeacher(Teacher * &T, int& n) {
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
        T[i].SocialID = change(SSocialID);
        i++;
    }
    n = i - 1;
    file.close();
}
// Xuat toan bo file sinh vien
void PrintStu(Student * S, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien." << endl;
        cout << "So thu tu: " << S[i].No << endl;
        cout << "MSSV: " << S[i].StuID << ". Ho ten: " << S[i].Fname << " " << S[i].Lname << endl;
        cout << "Gioi tinh: " << S[i].Gen << ". Nam sinh: " << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
        cout << "CMND: " << S[i].SocialID << ". Lop: " << S[i].Class << endl;
    }
}
// Xuat 1 phan tu sinh vien
void PrintElementStu(Student * S, int i) {
    cout << "So thu tu: " << S[i].No << endl;
    cout << "MSSV: " << S[i].StuID << ". Ho ten: " << S[i].Fname << " " << S[i].Lname << endl;
    cout << "Gioi tinh: " << S[i].Gen << ". Nam sinh: " << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
    cout << "CMND: " << S[i].SocialID << ". Lop: " << S[i].Class << endl;
}

//---------------------------------------------Ma hoa mat khau khi dang nhap---------------------------------------
void encode(string & s) {
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
bool CheckPassStu(Student * S, int n, int& pos, string user, string Pass) {
    for (int i = 0; i < n; i++) {
        pos = i;
        if (S[i].StuID == user && S[i].Pass == Pass)
            return true;
    }
    return false;
}

// kiem tra tai khoan dang nhap giao vien
bool CheckPassTech(Teacher * T, int m, int& pos, string user, string Pass) {
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
void PrintElementTech(Teacher * T, int i) {
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
void input(string & user, string & pass) {
    Paint(15, 20, "ID of User: ", 10);
    getline(cin, user);
    Paint(15, 20, "Password: ", 10);
    getline(cin, pass);
}
// cap nhat thong tin ca nhan giao vien
void UpdateInforTeach(Teacher * &T, int m, string ID) {
    Teacher Temp;
    Format("Update personal information");
    cin.ignore();
    cout << "+ Please, Input your personal information." << endl;
    cout << "Your ID: ";
    getline(cin, Temp.TeID);
    cout << "Your First name: ";
    getline(cin, Temp.Fname);
    cout << "Your Last name: ";
    getline(cin, Temp.Lname);
    cout << "Your Gender: ";
    getline(cin, Temp.Gen);
    cout << "Your Faculty: ";
    getline(cin, Temp.Faculty);
    cout << "Your Social id: ";
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

void UpdateInforStu(Student * &S, int n, string ID) {
    Student Temp;
    Format("Update personal information");
    cin.ignore();
    cout << "+ Please, Input your personal information." << endl;
    cout << "Your ID: ";
    getline(cin, Temp.StuID);
    cout << "Your First name: ";
    getline(cin, Temp.Fname);
    cout << "Your Last name: ";
    getline(cin, Temp.Lname);
    cout << "Your Gender: ";
    getline(cin, Temp.Gen);
    cout << "Your date of birth:\nDay: "; cin >> Temp.day;
    cout << "Month: "; cin >> Temp.month;
    cout << "Year: "; cin >> Temp.year;
    cout << "Your Social id: ";
    cin >> Temp.SocialID;
    cout << "Your Class: ";
    getline(cin, Temp.Class);
    for (int i = 0; i < n; i++) {
        if (S[i].StuID == ID) {
            S[i].StuID = Temp.StuID;
            S[i].Fname = Temp.Fname;
            S[i].Lname = Temp.Lname;
            S[i].Gen = Temp.Gen;
            S[i].day = Temp.day;
            S[i].month = Temp.month;
            S[i].year = Temp.year;
            S[i].Class = Temp.Class;
            S[i].SocialID = Temp.SocialID;
        }
    }
}

void changepassteacher(Teacher * &T, int m, string ID)
{
    Teacher Temp;
    cin.ignore();
    Paint(15, 20, "Enter your old password: ", 10);
    getline(cin, Temp.Pass);
    for (int i = 0; i < m; i++)
        if (T[i].TeID == ID)
        {
            if (Temp.Pass == T[i].Pass) {
                Paint(15, 20, "Enter new password: ", 10);
                getline(cin, Temp.Pass);
                T[i].Pass = Temp.Pass;
            }
            else {
                cout << "Your password is wrong.\n";
            }
        }
}

void changepassstu(Student * &S, int n, string ID)
{
    Student Temp;
    cin.ignore();
    Paint(15, 20, "Enter your old password: ", 10);
    getline(cin, Temp.Pass);
    for (int i = 0; i < n; i++)
        if (S[i].StuID == ID)
        {
            if (Temp.Pass == S[i].Pass) {
                Paint(15, 20, "Enter new password: ", 10);
                getline(cin, Temp.Pass);
                S[i].Pass = Temp.Pass;
            }
            else {
                cout << "Your password is wrong.\n";
            }
        }
}

// ghi lai file sau khi cap nhap
void WriteAfterUdateTeach(Teacher * T, int m) {
    ofstream outfile;
    outfile.open("Teacher.csv");
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

void WriteAfterUdateStu(Student * S, int n) {
    ofstream outfile;
    outfile.open("Students.csv");
    if (!outfile.is_open()) {
        cout << "Can not open file" << endl;
        return;
    }
    outfile << "No" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Date of birth" << "," << "Social ID" << "," << "Class" << "," << "Password" << endl;
    for (int i = 0; i < n; i++) {
        outfile << S[i].No << "," << S[i].StuID << "," << S[i].Fname << "," << S[i].Lname << "," << S[i].Gen << "," << S[i].day << "/" << S[i].month << "/" << S[i].year << "," << S[i].SocialID << "," << S[i].Class << "," << S[i].Pass << endl;
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
void ReadCourses(Courses * &C, int& t) {
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
        getline(infile, C[i].day1, ',');
        getline(infile, C[i].session1, ',');
        getline(infile, C[i].day2, ',');
        getline(infile, C[i].session2, ',');
        string tempdaystart;
        getline(infile, tempdaystart, '/');
        C[i].daystart = change(tempdaystart);
        string tempmonthstart;
        getline(infile, tempmonthstart, ',');
        C[i].monthstart = change(tempmonthstart);
        string tempdayend;
        getline(infile, tempdayend, '/');
        C[i].dayend = change(tempdayend);
        string tempmonthend;
        getline(infile, tempmonthend);
        C[i].monthend = change(tempmonthend);

        i++;
    }
    t -= 1;
    infile.close();
}

void PrintCourses(Courses * C, int t) {
    for (int i = 0; i < t; i++) {
        cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].CName << endl;
    }
}

bool CheckTimeInput(int day, int month) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: {
        if (day > 31 || day < 1)
            return false;
    } break;
    case 4:
    case 6:
    case 9:
    case 11: {
        if (day > 30 || day < 1)
            return false;
    } break;
    case 2: {
        if (day > 39 || day < 1)
            return false;
    } break;
    }
    return true;
}


bool checkdate(Courses * C, int i, int day, int month) {
    if (month > C[i].monthstart && month < C[i].monthend) {
        return true;
    }
    else {
        if (month == C[i].monthstart) {
            if (day >= C[i].daystart)
                return true;
            else
                return false;
        }
        if (month == C[i].monthend) {
            if (day <= C[i].dayend)
                return true;
            else
                return false;
        }
    }
    return false;
}

bool checkdateStuC(StuCourses * SC, int i, int day, int month) {
    if (month > SC[i].monthstart && month < SC[i].monthend) {
        return true;
    }
    else {
        if (month == SC[i].monthstart) {
            if (day >= SC[i].daystart)
                return true;
            else
                return false;
        }
        if (month == SC[i].monthend) {
            if (day <= SC[i].dayend)
                return true;
            else
                return false;
        }
    }
    return false;
}
// create new course
void CreateCourse(Courses * &C, int& t) {
    Courses temp;
    cout << "Please, Enter new course's information:" << endl;
    cin.ignore();
    cout << "Course Id: ";
    getline(cin, temp.ID);
    cout << "Course Name: ";
    getline(cin, temp.CName);
    cout << "Teacher Name: ";
    getline(cin, temp.TName);
    cout << "Number of Credits: ";
    cin >> temp.Credits;
    cout << "The maximum number of students in the course: ";
    cin >> temp.MaxMem;
    cin.ignore();
    cout << "Day1 of the week: ";
    getline(cin, temp.day1);
    cout << "Session1: ";
    getline(cin, temp.session1);
    cout << "Day2 of the week: ";
    getline(cin, temp.day2);
    cout << "Session2: ";
    getline(cin, temp.session2);
    cout << "Start day: ";
    cin >> temp.daystart;
    cout << "Start month: ";
    cin >> temp.monthstart;
    cout << "End day: ";
    cin >> temp.dayend;
    cout << "End month: ";
    cin >> temp.monthend;

    Courses* Cnew = new Courses[t + 1];
    copy(C, C + t, Cnew);
    Cnew[t].ID = temp.ID;
    Cnew[t].CName = temp.CName;
    Cnew[t].TName = temp.TName;
    Cnew[t].Credits = temp.Credits;
    Cnew[t].MaxMem = temp.MaxMem;
    Cnew[t].day1 = temp.day1;
    Cnew[t].session1 = temp.session1;
    Cnew[t].day2 = temp.day2;
    Cnew[t].session2 = temp.session2;
    Cnew[t].daystart = temp.daystart;
    Cnew[t].monthstart = temp.monthstart;
    Cnew[t].dayend = temp.dayend;
    Cnew[t].monthend = temp.monthend;
    t++;
    delete[]C;
    C = Cnew;

}
// Write new course
void WriteCourse(Courses * C, int t) {
    ofstream outfile;
    outfile.open("course.csv");
    if (!outfile.is_open()) {
        return;
    }
    outfile << "Course id" << "," << "Course name" << "," << "Teacher name" << "," << "Number of credits" << "," << "The maximum number of students in the course" <<
        "," << "Day1 of the week" << "," << "Session1" << "," << "Day2 of the week" << "," << "Session2" << "," << "Start date" << "," << "End date" << endl;
    for (int i = 0; i < t; i++) {
        outfile << C[i].ID << "," << C[i].CName << "," << C[i].TName << "," << C[i].Credits << "," << C[i].MaxMem << "," << C[i].day1 << "," << C[i].session1 << "," << C[i].day2 << "," <<
            C[i].session2 << "," << C[i].daystart << "/" << C[i].monthstart << "," << C[i].dayend << "/" << C[i].monthend << endl;
    }
    outfile.close();
}
// Update courses
void UpdateCourse(Courses * &C, int t) {
    string CId;
    cin.ignore();
    cout << "Input the Course ID that need to update.";
    getline(cin, CId);
    int count = 0;
    for (int i = 0; i < t; i++) {
        if (C[i].ID == CId) {
            count++;
            Courses Temp;
            system("cls");
            Format("Update Course");
            cout << "+ Please, Input new course's information:" << endl;
            cout << "Course ID: ";
            getline(cin, Temp.ID);
            cout << "Course name: ";
            getline(cin, Temp.CName);
            cout << "Teacher name: ";
            getline(cin, Temp.TName);
            cout << "Number of Credits: ";
            cin >> Temp.Credits;
            cout << "The maximum number of students in the course:";
            cin >> Temp.MaxMem;
            cin.ignore();
            cout << "Day1 of the week:";
            getline(cin, Temp.day1);
            cout << "Session1:";
            getline(cin, Temp.session1);
            cout << "Day2 of the week:";
            getline(cin, Temp.day2);
            cout << "Session2:";
            getline(cin, Temp.session2);
            cout << "Start day:";
            cin >> Temp.daystart;
            cout << "Start month:";
            cin >> Temp.monthstart;
            cout << "End day:";
            cin >> Temp.dayend;
            cout << "End month:";
            cin >> Temp.monthend;
            C[i].ID = Temp.ID;
            C[i].CName = Temp.CName;
            C[i].TName = Temp.TName;
            C[i].Credits = Temp.Credits;
            C[i].MaxMem = Temp.MaxMem;
            C[i].day1 = Temp.day1;
            C[i].session1 = Temp.session1;
            C[i].day2 = Temp.day2;
            C[i].session2 = Temp.session2;
            C[i].daystart = Temp.daystart;
            C[i].monthstart = Temp.monthstart;
            C[i].dayend = Temp.dayend;
            C[i].monthend = Temp.monthend;
        }
    }
    if (count == 0)
        cout << "Course do not exist" << endl;
}

void registerCourses(Courses * &C, int& t)
{
    int day = 0, month = 0, option = 0;
    cout << "\n\n\tEnter Current time to register Course" << endl;
    do {
        cout << "Day: "; cin >> day;
        cout << "Month: "; cin >> month;
    } while (CheckTimeInput(day, month) == false);
    while (true)
    {
        system("cls");
        Format("\tCourses Registration");
        cout << "\n\t1. View list of courses";
        cout << "\n\t2. Create a new course";
        cout << "\n\t3. Update course's information";
        cout << "\n\t4. Delete a course";
        cout << "\n\t0. Back forward";
        cout << "\n\t**************************************";
        cout << "\n\t Choose the option you wanna do: "; cin >> option;
        while ((option < 0) || (option > 4))
        {
            cout << "The number you enter isn't suitble\nPlease choose it again: "; cin >> option;
        }
        switch (option)
        {
        case 1:
        {
            system("cls");
            Format("List courses");
            cout << "\t List of courses existing: \n";
            cout << "Current Time: " << day << "/" << month << endl;
            for (int i = 0; i < t; i++) {
                if (checkdate(C, i, day, month)) {
                    cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].CName << ", Time start: " << C[i].daystart << "/" << C[i].monthstart << ", Time end: " <<
                        C[i].dayend << "/" << C[i].monthend << endl;
                }
            }
            system("pause");
        }break;
        case 2:
        {
            system("cls");
            Format("List courses");
            CreateCourse(C, t);
            WriteCourse(C, t);
            system("pause");
        }break;
        case 3:
        {
            system("cls");
            Format("Update courses");
            UpdateCourse(C, t);
            WriteCourse(C, t);
            system("pause");
        }break;
        case 4:
        {
            system("cls");
            Format("Delete course");

            system("pause");
        }break;
        case 0:
        {
            return;
        } break;
        }
    }
}
//////////////////////////////////////////Student register course

void registerStuC(StuCourses * &SC, int& p, Courses * &C, int t, Student * &S, int n, string ID)
{
    int day = 0, month = 0, option = 0;
    cout << "\n\n\tEnter Current time to register Course" << endl;
    do {
        cout << "Day: "; cin >> day;
        cout << "Month: "; cin >> month;
    } while (CheckTimeInput(day, month) == false);
    while (true)
    {
        system("cls");
        Format("\tCourses Registration");
        cout << "\n\t1. View list of courses";
        cout << "\n\t2. Register course";
        cout << "\n\t3. List courses you have registered";
        cout << "\n\t4. Delete a course you have registered";
        cout << "\n\t0. Back forward";
        cout << "\n\t**************************************";
        cout << "\n\t Choose the option you wanna do: "; cin >> option;
        while ((option < 0) || (option > 4))
        {
            cout << "The number you enter isn't suitble\nPlease choose it again: "; cin >> option;
        }
        switch (option)
        {
        case 1:
        {
            system("cls");
            Format("List courses");
            cout << "\t List of courses existing: \n";
            cout << "Current Time: " << day << "/" << month << endl;
            for (int i = 0; i < t; i++) {
                if (checkdate(C, i, day, month)) {
                    cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].CName << ", Time start: " << C[i].daystart << "/" << C[i].monthstart << ", Time end: " <<
                        C[i].dayend << "/" << C[i].monthend << endl;
                }
            }
            system("pause");
        }break;
        case 2:
        {
            system("cls");
            Format("Register course");
            int count = 0;
            for (int i = 0; i < p; i++)
            {
                if (checkdateStuC(SC, i, day, month))
                {
                    if (SC[i].StuID == ID) count++;
                    if (count == 5) continue;
                }
            }
            if (count >= 5)  cout << "You can't register course because you have registered 5 courses\n";
            else addStuC(SC, p, C, t, S, n, ID);
            WriteAfterUdateStuC(SC, p);
            system("pause");
        }break;
        case 3:
        {
            system("cls");
            Format("List courses");
            for (int i = 0; i < p; i++)
            {
                if (checkdateStuC(SC, i, day, month))
                    if (SC[i].StuID == ID) PrintElementStuC(SC, i);
            }
            system("pause");
        }break;
        case 4:
        {
            system("cls");
            Format("Delete course");

            system("pause");
        }break;
        case 0:
        {
            return;
        } break;
        }
    }
}

void addStuC(StuCourses * &SC, int& p, Courses * C, int t, Student * S, int n, string ID)
{
    int position = 0;
    string temp;
    do {
        cout << "Please enter exactly the course ID of the course you wanna register: ";
        getline(cin, temp);
        position = ExistCourse(C, t, temp);
    } while ((position < 0) || (unduplicated(SC, p, C, t, ID, position) == false));
    StuCourses* SCnew = new StuCourses[p + 1];
    copy(SC, SC + p, SCnew);
    SCnew[p].No = p;
    SCnew[p].StuID = ID;
    for (int i = 0; i < n; i++)
        if (S[i].StuID == ID)
        {
            SCnew[p].Fname = S[i].Fname;
            SCnew[p].Lname = S[i].Lname;
            SCnew[p].Gen = S[i].Gen;
            SCnew[p].Class = S[i].Class;
            continue;
        }
    SCnew[p].CouID = C[position].ID;
    SCnew[p].Cname = C[position].CName;
    SCnew[p].credits = C[position].Credits;
    SCnew[p].Tname = C[position].TName;
    SCnew[p].day1 = C[position].day1;
    SCnew[p].session1 = C[position].session1;
    SCnew[p].day2 = C[position].day2;
    SCnew[p].session2 = C[position].session2;
    SCnew[p].daystart = C[position].daystart;
    SCnew[p].monthstart = C[position].monthstart;
    SCnew[p].dayend = C[position].dayend;
    SCnew[p].monthend = C[position].monthend;
    p++;
    delete[] SC;
    SC = SCnew;
}

bool unduplicated(StuCourses * SC, int p, Courses * C, int t, string ID, int position)
{
    for (int i = 0; i < p; i++)
        if (SC[i].StuID == ID)
        {
            if (SC[i].day1 == C[position].day1)
                if (SC[i].session1 == C[position].session1) return false;
            if (SC[i].day2 == C[position].day2)
                if (SC[i].session2 == C[position].session2) return false;
        }
    return true;
}

int ExistCourse(Courses * C, int t, string ID)
{
    for (int i = 0; i < t; i++)
        if (C[i].ID == ID) return i;
    return -1;
}
//Ghi file danh sach sinh vien dang ky hoc phan
int countStuC() {
    int count = 0;
    ifstream infile;
    infile.open("Stucourses.csv");
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

void ReadStuC(StuCourses * &SC, int& p) {
    p = countCourses();
    SC = new StuCourses[p];
    ifstream infile;
    infile.open("Stucourses.csv");
    if (!infile.is_open()) {
        return;
    }
    int i = 0;
    string line, No, credits, ds, ms, de, me;
    getline(infile, line);
    while (infile) {
        getline(infile, No, ',');
        getline(infile, SC[i].StuID, ',');
        getline(infile, SC[i].Fname, ',');
        getline(infile, SC[i].Lname, ',');
        getline(infile, SC[i].Gen, ',');
        getline(infile, SC[i].Class, ',');
        getline(infile, SC[i].CouID, ',');
        getline(infile, SC[i].Cname, ',');
        getline(infile, credits, ',');
        getline(infile, SC[i].Tname, ',');
        getline(infile, SC[i].day1, ',');
        getline(infile, SC[i].session1, ',');
        getline(infile, SC[i].day2, ',');
        getline(infile, SC[i].session2, ',');
        getline(infile, ds, ',');
        getline(infile, ms, ',');
        getline(infile, de, ',');
        getline(infile, me, ',');
        SC[i].No = change(No);
        SC[i].credits = change(credits);
        SC[i].daystart = change(ds);
        SC[i].monthstart = change(ms);
        SC[i].dayend = change(de);
        SC[i].monthend = change(me);

        i++;
    }
    p = i - 1;
    infile.close();
}

void PrintStuC(StuCourses * SC, int p) {
    for (int i = 0; i < p; i++) {
        cout << "Student ID: " << SC[i].Fname << " " << SC[i].Lname << " | Class: " << SC[i].Class << " | Course: " << SC[i].Cname << " | Semester: " << SC[i].daystart << "/" << SC[i].monthstart << " - " << SC[i].dayend << "/" << SC[i].monthend << endl;
    }
}

void PrintElementStuC(StuCourses * SC, int i) {
    cout << "Student ID: " << SC[i].Fname << " " << SC[i].Lname << " | Class: " << SC[i].Class << " | Course: " << SC[i].Cname << " | Semester: " << SC[i].daystart << "/" << SC[i].monthstart << " - " << SC[i].dayend << "/" << SC[i].monthend << endl;
}

void WriteAfterUdateStuC(StuCourses * SC, int p) {
    ofstream outfile;
    outfile.open("Stucourses.csv");
    if (!outfile.is_open()) {
        cout << "Can not open file" << endl;
        return;
    }
    outfile << "No" << "," << "Student ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Class" << "," << "Course ID" << "," << "Course Name" << "," << "Credits" << "," << "Teacher Name" << "," << "day1" << "," << "session1" << "," << "day2" << "," << "session2" << "," << "day start" << "," << "month start" << "," << "day end" << "," << "month end" << endl;
    for (int i = 0; i < p; i++) {
        outfile << SC[i].No << "," << SC[i].StuID << "," << SC[i].Fname << "," << SC[i].Lname << "," << SC[i].Gen << "," << SC[i].Class << "," << SC[i].CouID << "," << SC[i].Cname << "," << SC[i].credits << "," << SC[i].Tname << "," << SC[i].day1 << "," << SC[i].session1 << "," << SC[i].day2 << "," << SC[i].session2 << "," << SC[i].daystart << "/" << SC[i].monthstart << "," << SC[i].dayend << "/" << SC[i].monthend << endl;
    }
    outfile.close();
}
