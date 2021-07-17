#include "Header.h"

int main() {
    Student* S;
    Teacher* T;
    Courses* C;
    StuCourses* SC;
    int n = 0, m = 0, t = 0, p = 0;;
    ReadStudent(S, n);
    ReadTeacher(T, m);
    ReadCourses(C, t);
    WriteRegisterStuDefault(C, t, S, n, SC, p);
    WriteAfterUdateStuC(SC, p);
    string user, password;
    int schoolYear = 0;
    bool check = true;
    do {
        Format("LOGIN");
        input(user, password);
        int pos = -1;
        if (CheckPassTech(T, m, pos, user, password) == true) {
            system("cls");
            Color(10);
            int check_temp = true;
            int select = 0;
            do {
                system("cls");
                Format("TEACHER");
                cout << "\n\t1. Change password.\n";
                cout << "\t2. Update your personal information." << endl;
                cout << "\t3. Create a school year." << endl;
                cout << "\t4. Add new 1st year students to 1st year classes." << endl;
                cout << "\t5. Create a course registration session." << endl;
                cout << "\t0. Log out." << endl;
                cout << "\t-1. Exit" << endl;
                cout << "\n\t\t*******************************************\n";
                PrintElementTech(T, pos);
                cout << "\n\t Choose the option you wanna do: ";
                cin >> select;
                while ((select < -1) || (select > 5))
                {
                    cout << "The option you enter isn't suitable\nPlease choose it again: "; cin >> select;
                }
                switch (select) {
                case 1:
                {
                    system("cls");
                    Format(" Change password");
                    changepassteacher(T, m, user);
                    WriteAfterUdateTeach(T, m);
                    system("pause");
                }break;
                case 2: {
                    system("cls");
                    Format("Update personal information");
                    UpdateInforTeach(T, m, user);
                    WriteAfterUdateTeach(T, m);
                    system("pause");
                } break;
                case 3: {
                    system("cls");
                    Format("Create a school year.");
                    CreateSchoYear(schoolYear);
                    system("pause");
                } break;
                case 4: {
                    system("cls");
                    Format("Add new 1st year students to 1st year classes.");
                    if (schoolYear == 0) {
                        cout << "You need to create a new school year before Add new 1st to classes." << endl;
                    }
                    else {
                        add1stStutoClas(schoolYear, S, n);
                    }
                    system("pause");
                } break;
                case 5: {
                    system("cls");
                    Format("Register course");
                    cout << "\tCourses existed: " << t << endl;
                    PrintCourses(C, t);
                    registerCourses(C, t);
                    system("pause");
                } break;
                case 0: {
                    cin.ignore();
                    check_temp = false;
                } break;
                case -1: {
                    check_temp = false;
                    check = false;
                } break;
                }
            } while (check_temp);



        }
        else
        {
            if (CheckPassStu(S, n, pos, user, password) == true) {
                system("cls");
                Color(10);
                int check_temp = true;
                int select = 0;
                do {
                    system("cls");
                    Format("STUDENT");
                    cout << "\n\t1. Change password";
                    cout << "\n\t2. Update your personal information." << endl;
                    cout << "\t3. Register for the course." << endl;
                    cout << "\t4. View list of courses, classes and students." << endl;
                    cout << "\t5. View your scoreboard." << endl;
                    cout << "\t0. Log out." << endl;
                    cout << "\t-1. Exit" << endl;
                    cout << "\n\t\t*******************************************\n";
                    PrintElementStu(S, pos);
                    cout << "\n\t Choose the option you wanna do: ";
                    cin >> select;
                    while ((select < -1) || (select > 4))
                    {
                        cout << "The option you enter isn't suitable\nPlease choose it again: "; cin >> select;
                    }
                    switch (select) {
                    case 1:
                    {
                        system("cls");
                        Format(" Change password");
                        changepassstu(S, n, user);
                        WriteAfterUdateStu(S, n);
                        system("pause");
                    }break;
                    case 2: {
                        system("cls");
                        Format("Update personal information");
                        UpdateInforStu(S, n, user);
                        WriteAfterUdateStu(S, n);
                        system("pause");
                    } break;
                    case 3: {
                        system("cls");
                        Format("Register course");
                        cout << "Courses existed: " << endl;
                        PrintCourses(C, t);
                        registerStuC(SC, p, C, t, S, n, user);
                        system("pause");
                    } break;
                    case 4: {
                        system("cls");
                        Format("List courses");
                        int count = 0, day = 0, month = 0;
                        cout << "\n\n\tEnter Current time to view your Courses" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (CheckTimeInput(day, month) == false);
                        for (int i = 0; i < p; i++)
                        {
                            if (checkdateStuC(SC, i, day, month))
                                if (SC[i].StuID == user)
                                {
                                    PrintElementStuC(SC, i);
                                    count++;
                                }
                        }
                        if (count == 0) cout << "You haven't registered any courses in this semester\n";
                        system("pause");
                    } break;
                    case 5:
                    {
                        system("cls");
                        Format("Scoreboard");
                        int count = -1, day = 0, month = 0;
                        cout << "\n\n\tEnter Current time to view your Courses" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (CheckTimeInput(day, month) == false);
                        for (int i = 0; i < p; i++)
                        {
                            if (checkdateStuC(SC, i, day, month))
                                if (SC[i].StuID == user) count = i;
                            if (count == -1) cout << "You haven't registered any courses in this semester\n";
                            else
                            {
                                cout << "Student ID: " << SC[count].StuID << " | Name: " << SC[count].Fname << " " << SC[count].Lname << " | Other mark | Midterm mark | Final mark || Total mark\n";
                                for (int i = 0; i < p; i++)
                                    if (checkdateStuC(SC, i, day, month))
                                        if (SC[i].StuID == user)
                                        {
                                            ViewScore(SC, p, i);
                                        }
                            }
                        }
                        system("pause");
                    }break;
                    case 0: {
                        cin.ignore();
                        check_temp = false;
                    } break;
                    case -1: {
                        check_temp = false;
                        check = false;
                    } break;
                    }
                } while (check_temp);
            }
            else {
                system("cls");
                Color(4);
                cout << "\n\tKhong co tai khoan trong he thong!";
                Sleep(3000);
                cin.ignore();
                system("cls");
            }
        }
    } while (check);


    delete[] S;
    delete[] T;
    delete[] C;
    system("pause");
    return 0;
}
