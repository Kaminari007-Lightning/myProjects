#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    system("cls");
    system("color 09");
    string Hanser;
    string anser1;
    string anser2;
    string name;
    cout << "\n\n\tWhat is your name?: ";
    cin >> name;
    cout << "\n\n\tHello " << name ;
    cout << "\n\ti am wail ";
    cout << "\n\tCan i ask you something: ";
    cin >> anser2;
    if (anser2 == "yes")
    {
        cout << "\nNOTE: you can use \"good ,fine ,bad ,help ,crazy\"";
        cout << "\n\n\tHow are you feeling today?: ";
        cin >> anser1;
        if (anser1 == "good")
        {
            cout << "\n\n\tgreat";
            cout << "\n\thave a good day then. ";
            getch();
        }
        else if (anser1 == "fine")
        {
            cout << "\n\n\tokey";
            cout << "\n\tWe Can Work On That ";
            getch();
        }
        else if (anser1 == "bad")
        {
            cout << "\n\n\tsorry to hear that";
            cout << "\n\t just smile it looks better in your face :) ";
            getch();
        }
        else if (anser1 == "help")
        {
            cout << "\n\n\tspeak to me: ";
            cin >> Hanser;
            cout << "\n\n\tYou Can Do It Just Believe on Your self ";
            getch();
        }
        else if (anser1 == "crazy")
        {
            cout << "\n\n\tyou have to calm yourself down or";
            cout << "\n\tI WILL BE CRAZY tooooooooooooooo ";
            getch();
        }
        else
        {
            cout << "\n\n\tI don't understand";
            cout << "\n\tPress Any Key To Continue.. ";
            getch();
            main();
        }
    }
    else if (anser2 == "no")
    {
        cout << "\n\n\tokey thank you anyways! ";
        getch(); 
        exit(1);
    }
    else
    {
        cout << "\n\n\tI don't understand You must answer using yes or no";
        cout << "\n\tPress Any Key To Continue.. ";
            getch();
            main();
    }

    return 0;
    
}