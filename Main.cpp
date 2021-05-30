#include "Header.h"

int main() {
    Student* S;
    int n = 0;
    ReadStudent(S, n);
    bool check = true;
    string user, password;
    do {
        system("cls");
        Paint(15, 4, "**************************************", 14);
        Paint(15, 6, "**", 14);
        Paint(25, 6, "     LOGIN", 10);
        Paint(50, 6, "**", 14);
        Paint(15, 8, "**************************************", 14);
        cin.ignore();
        Paint(15, 12, "ID of User: ", 10);
        getline(cin, user);
        cin.ignore();
        Paint(15, 15, "Password: ", 10);
        encode(password);
        int pos = -1;
        if (CheckPass(S, n, pos, user, password) == true) {
            system("cls");
            PrintElement(S, pos);
            // Cac nhiem vu tiep theo cua sinh vien



        }
        else {
            system("cls");
            Color(4);
            cout << "Khong co tai khoan trong he thong!";
            Sleep(3000);
            system("cls");
        }


    } while (true);


    delete[] S;
    system("pause");
    return 0;
}
