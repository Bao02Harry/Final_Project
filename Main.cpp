#include "Header.h"

int main() {
    Student* S;
    Teacher* T;
    Courses* C;
    int n = 0;
    int m = 0;
    int t = 0;
    ReadStudent(S, n);
    ReadTeacher(T, m);
    ReadCourses(C, t);
    bool check = true;
    string user, password;
    do {
        Format("LOGIN");
        input(user, password);
        int pos = -1;
        if (CheckPassTech(T, m, pos, user, password) == true) {
            system("cls");
            Color(10);
            PrintElementTech(T, pos);
            // Cac nhiem vu tiep theo cua giao vien
            system("pause");
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
                cout << "\n\t\t*******************************************";
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
                    Format("Change password");
                    changepass(T, m, user);
                    system("pause");
                }break;
                case 2: {
                    system("cls");
                    cout << "\t1. Update your personal information." << endl;
                    UpdateInforTeach(T, m, user);
                    WriteAfterUdateTeach(T, m);
                    system("pause");
                } break;
                case 4: {
                    system("cls");
                    cout << "2. Create a course registration session." << endl;
                    cout << "Courses existed: " << endl;
                    PrintCourses(C, t);
                    system("pause");
                } break;
                case 5: {

                } break;
                case 0: {
                    check_temp = false;
                } break;
                case -1: {
                    exit(0);
                }
                }
            } while (check_temp);

            // cap nhat thong tin cua ban than

                  // Password


                  //


            // 





        }
        else if (CheckPassStu(S, n, pos, user, password) == true) {
            system("cls");
            Color(10);
            PrintElementStu(S, pos);
            system("pause");
            // Cac nhiem vu tiep theo cua sinh vien
            system("pause");
            int check_temp = true;
            int select = 0;
            do {
                system("cls");
                Format("STUDENT");
                cout << "\n\t1. Update your personal information." << endl;
                cout << "\t2. Register for the course." << endl;
                cout << "\t3. View list of course, classes and student." << endl;
                cout << "\t0. Log out." << endl;
                cout << "\t-1. Exit" << endl;
                cout << "\n\t\t*******************************************";
                cout << "\n\t Choose the option you wanna do: ";
                cin >> select;
                while ((select < -1) || (select > 3))
                {
                    cout << "The option you enter isn't suitable\nPlease choose it again: "; cin >> select;
                }
                switch (select) {
                case 1: {
                    system("cls");
                    cout << "\t1. Update your personal information." << endl;
                    UpdateInforTeach(T, m, user);
                    WriteAfterUdateTeach(T, m);
                    system("pause");
                } break;
                case 2: {
                    system("cls");
                    cout << "2. Create a course registration session." << endl;
                    cout << "Courses existed: " << endl;
                    PrintCourses(C, t);
                    system("pause");
                } break;
                case 3: {

                } break;
                case 0: {
                    check_temp = false;
                } break;
                case -1: {
                    exit(0);
                }
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
        

    } while (check );
    

    delete[] S;
    delete[] T;
    delete[] C;
    system("pause");
    return 0;
}
