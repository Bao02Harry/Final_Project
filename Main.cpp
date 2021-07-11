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
    ReadStuC(SC, p);
    string user, password;
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
                cout << "\t3. Create a course registration session." << endl;
                cout << "\t4. Add new 1st year students to 1st year classes." << endl;
                cout << "\t0. Log out." << endl;
                cout << "\t-1. Exit" << endl;
                cout << "\n\t\t*******************************************\n";
                PrintElementTech(T, pos);
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
                    Format("Register course");
                    cout << "\tCourses existed: " << t << endl;
                    PrintCourses(C, t);
                    registerCourses(C, t);
                    system("pause");
                } break;
                case 4: {

                } break;
                case 5: {

                } break;
                case 0: {
                    check_temp = false;
                } break;
                case -1: {
                    return false;
                } break;
                }
            } while (check_temp);



        }
        else if (CheckPassStu(S, n, pos, user, password) == true) {
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

                } break;
                case 0: {
                    check_temp = false;
                } break;
                case -1: {
                    return false;
                } break;
                }
            } while (check_temp);

        }
        else {
            system("cls");
            Color(4);
            cout << "\n\tKhong co tai khoan trong he thong!";
            Sleep(3000);
            system("cls");
        }


    } while (true);


    delete[] S;
    delete[] T;
    delete[] C;
    system("pause");
    return 0;
}
