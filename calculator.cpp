#include <iostream>
#include <synchapi.h>
using namespace std;

void calculator(int a, int b){
    cout << "\nthe sum of the numbers is:" << endl << endl;
    Sleep(500);
    cout << a << " + " << b << " = " << a + b << endl;
    Sleep(500);
    cout << "\nthe na9s of the numbers is:" << endl << endl;
    Sleep(500);
    cout << a << " - " << b << " = " << a - b << endl;
    Sleep(500);
    cout << "\nthe darb of the numbers is:" << endl << endl;
    Sleep(500);
    cout << a << " * " << b << " = " << a * b << endl;
    Sleep(500);
    cout << "\nthe 9isma of the numbers is:" << endl << endl;
    Sleep(500);
    cout << a << " / " << b << " = " << a / b << endl;
    Sleep(500);
    cout << "\nthe ba9i of the numbers is:" << endl << endl;
    Sleep(500);
    cout << a << " % " << b << " = " << a % b << endl << endl;
    Sleep(500);
}

void start(){
    int a, b;
    cout << "\n\n\tType the first number: ";
    Sleep(500);
    cout << "\n\n\t> ";
    Sleep(500);
    cin >> a;
    cout << "\n\n\tType the second number: ";
    Sleep(500);
    cout << "\n\n\t> ";
    Sleep(500);
    cin >> b;
    Sleep(500);
    calculator(a, b);
    Sleep(500);
}

void welcome(){
    cout << "\n\n\tHello";
    Sleep(500);
    cout << "\n\t\tAnd";
    Sleep(500);
    cout << "\n\t\t\tWelcome to my calculator";
    Sleep(500);
}

void welcome_again(){
    cout << "\n\n\tHello";
    Sleep(500);
    cout << "\n\t\tAnd";
    Sleep(500);
    cout << "\n\t\t\tWelcome to again my calculator";
    Sleep(500);
}

void again(){
    cout << "================================================================" << endl;
    string anser;
    cout << "\tDo you want to calculate again: " << endl;
    Sleep(500);
    cout << "\n\t> ";
    Sleep(500);
    cin >> anser;
    if (anser == "yes" || anser == "y"){
        Sleep(500);
        welcome_again();
        start();
        again();
    }else{
        Sleep(500);
        cout << "\n\tOki by have nice day!" << endl << endl;
        exit(1);
    }
}

int main() {
    system("color 0a");
    welcome();
    start();
    again();
    return 0;
}
