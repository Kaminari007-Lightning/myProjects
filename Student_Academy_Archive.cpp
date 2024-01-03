#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <unistd.h>
using namespace std;
/* Student Council Archive: 
Console app that can : 
-Add student's 
-Edit existing Student 
-Delete student's 
-Read student 
-Search for students
---------------------------------------------------
Main functions: Save the students to a text or other format file so you dont Loss data when
the app closed Can search for both names or last names The app won't exit unless the user 
chooses to The app will receive the students name and last name and Three seamstress marks 
and will automatically count the year mark and set the student to pass or failed Set setting
function that can delete all the data if the user want or set password to access the app
----------------------------------------------------
Things that you may add: " give extra credit" Order the students when read by user choice for 
by name last name or marks */

void self_exit();
void addStudent();


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
        case 1:
            addStudent();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            self_exit();
            break;
        default:
            break;
    }
}

void addStudent()
{
    system("cls");
    system("color 0A");
    Sleep(300);
}

void self_exit()
{
    cout << "\n\n\n\t\tThank You For Using this Software !";
    exit(1);
}