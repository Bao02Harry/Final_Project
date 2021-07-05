#include "Header.h"

int main() {
    Student* S;
    Teacher* T;
    int n = 0;
    int m = 0;
    ReadStudent(S, n);
    ReadTeacher(T, m);
    bool check = true;
    string user, password;
    do {
        Format();
        input(user, password);
        int pos = -1;
        if (CheckPassTech(T, m, pos, user, password) == true) {
            system("cls");
            Color(10);
            PrintElementTech(T, pos);
            // Cac nhiem vu tiep theo cua giao vien
     
            system("pause");
            system("cls");
            int check_temp = true;
            int select = 0;
            do {
                cout << "1. Update your personal information." << endl;
                cout << "2. Create a course registration session." << endl;
                cout << "3. Add new 1st year students to 1st year classes." << endl;
                cout << "0. Back." << endl;
                cout << "\t Your select: ";
                cin >> select;
                
                switch (select) {
                case 1: {
                    system("cls");

                    cout << "\t1. Update your personal information." << endl;
                    UpdateInforTeach(T, m, user);
                    WriteAfterUdateTeach(T, m);



                } break;
                case 2: {

                } break;
                case 3: {

                } break;
                case 0: {
                    check_temp = false;
                } break;
                }
            } while (check_temp);

            // cap nhat thong tin cua ban than

                  // Password


                  //


            // 
            
            



        }
        else {
            if (CheckPassStu(S, n, pos, user, password) == true) {
                system("cls");
                Color(10);
                PrintElementStu(S, pos);
                system("pause");
                // Cac nhiem vu tiep theo cua sinh vien


            }
            else {
                system("cls");
                Color(4);
                cout << "Khong co tai khoan trong he thong!";
                Sleep(3000);
                system("cls");
            }
        }

    } while (check );
    

    delete[] S;
    delete[] T;
    system("pause");
    return 0;
}
