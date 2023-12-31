#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <unistd.h>
using namespace std;

void self_exit();


int main() {
    short int choice ;
    system("cls");
    system("color 0A");
    Sleep(300);
    cout << "\n\n\n\t====================Student Academy Archive====================";
    Sleep(300);
    cout << "\n\n\n\t1. add new student";
    Sleep(300);
    cout << "\n\n\t2. show all students";
    Sleep(300);
    cout << "\n\n\t3. show single students";
    Sleep(300);
    cout << "\n\n\t4. edit student information";
    Sleep(300);
    cout << "\n\n\t5. delete student information";
    Sleep(300);
    cout << "\n\n\t6. exit";
    Sleep(300);
    cout << "\n\n\t > ";
    Sleep(300);
    cin >> choice;

    switch (choice)
    {
    case 6:
        self_exit();
        break;
    
    default:
        break;
    }
}

void self_exit()
{
    cout << "\n\n\n\t\tThank You For Using this Software !";
    exit(1);
}