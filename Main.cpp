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
            system("pause");
            // Cac nhiem vu tiep theo cua giao vien



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

    } while (true);
    

    delete[] S;
    delete[] T;
    system("pause");
    return 0;
}
