#include "Header.h"

int main() {
    Student* S;
    Teacher* T;
    Courses* C;
    StuCourses* SC;
    Classes* Clas;
    int n = 0, m = 0, t = 0, p = 0, k = 1;
    ReadStudent(S, n);
    ReadTeacher(T, m);
    ReadCourses(C, t);
    WriteRegisterStuDefault(C, t, S, n, SC, p);
    WriteAfterUdateStuC(SC, p);
    string user, password;
    int schoolYear = 0;
    bool check = true;
    int count = 0;
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
                cout << "\t6. Export list of students in a course." << endl;
                cout << "\t7. Enter and view the scoreboard of a course." << endl;
                cout << "\t8. View the scoreboard of a course." << endl;
                cout << "\t9. Import the scoreboard of a course." << endl;
                cout << "\t10. Update a student result." << endl;
                cout << "\t11. View the scoreboard of a class." << endl;
                cout << "\t0. Log out." << endl;
                cout << "\t-1. Exit" << endl;
                cout << "\n\t\t*******************************************\n";
                PrintElementTech(T, pos);
                cout << "\n\t Choose the option you wanna do: ";
                cin >> select;
                while ((select < -1) || (select > 11))
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
                case 6:
                {
                    system("cls");
                    Format("Export list of students in a course");
                    ExportStu(SC, p);
                    system("pause");
                } break;

                case 7: {
                    system("cls");
                    Format("Enter the scoreboard of a course.");
                    EnterscoreboardACour(SC, p, pos, C, T);
                    WriteAfterUdateStuC(SC, p);
                    count = 7;
                    system("pause");
                } break;

                case 8: {
                    system("cls");
                    if (count != 7) {
                        cout << "You need enter the scoreboard of your course before!" << endl;
                    }
                    else {
                        Format("View the scoreboard of a course.");
                        PrintElementTech(T, pos);
                        ViewScoreBoard(SC, p, pos, C);
                    }
                    system("pause");
                } break;
                case 9:
                {
                    system("cls");
                    if (count != 7) {
                        cout << "You need enter the scoreboard of your course before!" << endl;
                    }
                    else {
                        Format("Import the scoreboard of a course.");
                        ImportScoreBoard(SC, p, pos, C);
                    }
                    system("pause");
                } break;

                case 10: {
                    system("cls");
                    Format("Update a student result.");
                    ViewScoreBoard(SC, p, pos, C);
                    UpdateStuResult(SC, p);
                    WriteAfterUdateStuC(SC, p);
                    system("pause");
                } break;

                case 11: {
                    system("cls");
                    Format("View the scoreboard of a class.");
                    ScoreBoardClass(SC, p);
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
                    cout << "\t4. View your schedule." << endl;
                    cout << "\t5. View your scoreboard." << endl;
                    cout << "\t6. View list of students in a course." << endl;
                    cout << "\t7. View  of classes" << endl;
                    cout << "\t8. View list of students in a class" << endl;
                    cout << "\t0. Log out." << endl;
                    cout << "\t-1. Exit" << endl;
                    cout << "\n\t\t*******************************************\n";
                    PrintElementStu(S, pos);
                    cout << "\n\t Choose the option you wanna do: ";
                    cin >> select;
                    while ((select < -1) || (select > 8))
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
                        Format("Schedule");
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
                                    printStuCour(SC, i);
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
                        int count = 0, day = 0, month = 0;
                        cout << "\n\n\tEnter Current time to view your Courses" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (CheckTimeInput(day, month) == false);
                        for (int i = 0; i < p; i++)
                        {
                            if (checkdateStuC(SC, i, day, month)) {
                                if (SC[i].StuID == user) {
                                    ViewScore(SC, p, i);
                                }
                            }
                        }
                        system("pause");
                    }break;
                    case 6: {
                        system("cls");
                        Format("List students in a course");
                        string ID;
                        int count = 0, day = 0, month = 0;
                        cout << "\tEnter Current time to view your Courses" << endl;
                        do {
                            cout << "Day: "; cin >> day;
                            cout << "Month: "; cin >> month;
                        } while (CheckTimeInput(day, month) == false);
                        cout << "\tEnter ID of courses to view list students: ";
                        cin.ignore();
                        getline(cin, ID);
                        for (int i = 0; i < p; i++)
                        {
                            if (checkdateStuC(SC, i, day, month)) {
                                if (SC[i].CouID == ID) {
                                    printStuCour(SC, i);
                                }
                            }
                        }
                        system("pause");

                    } break;
                    case 7:
                    {
                        system("cls");
                        Format("list of classes");
                        viewClasses(Clas, k, S, n);
                        for (int i = 0; i < k; i++)
                        {
                            cout << "\n\t Class: " << Clas[i].name << " | " << Clas[i].num << " Students "<< endl;
                        }
                        system("pause");
                    } break;
                    case 8:
                    {
                        system("cls");
                        Format("list student in a class");
                        string ID;                       
                        cout << "\tEnter ID of class to view list students: ";
                        cin.ignore();
                        getline(cin, ID);
                        for (int i = 0; i < p; i++)
                        {
                            if (SC[i].Class == ID) {
                                printStuCour(SC, i);
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
