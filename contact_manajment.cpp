#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

string first_name,last_name,phone_number;

void addContact();
void searchContact();
void Help();
void self_exit();
bool check_digits(string);
bool check_number(string);
void printContacts();



int main()
{
    short int choice;
    system("cls");
    system("color 0B");
    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. See All contact\n\t4. Help\n\t5. Exit\n\t > ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            printContacts();
            break;    
        case 4:
            Help();
            break;
        case 5:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            getch();
            main();                
    }
}

void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !"<<  endl;
    exit(1);
}

void Help()
{
    cout << "\n\n\n\tHelp Information is here: http://www.you-faked.com";
    cout << "\n\tPress Any Key To Continue..";
    getch();
    main();
}

void addContact()
{
    ofstream Phone("number.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name: ";
    cin >> first_name;
    cout << "\n\tEnter Last Name: ";
    cin >> last_name;
    cout << "\n\tEnter 10-Digit Phone number: ";
    cin >> phone_number;

    if(check_digits(phone_number) == true) 
    {
        if(check_number(phone_number) == true)
        {
            if(Phone.is_open())
            {
                Phone << first_name << "\t" << last_name << "\t\t" << phone_number << endl;
                Phone.close();
                cout << "\n\n\tContact Added Successfully!" << endl;
                cout << "\n\tPress Any Key To Continue..";
                getch();
                main();
            }
            else
            {
                cout << "\n\tError Opining File !";
            }
        }
        else
        {
            cout << "\n\tInvalid Phone Number!";
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must Contains 10 Digits.";
    }
    
}

void searchContact()
{
    bool found = false;  
    ifstream myFile("number.txt");
    string keyword;
    cout << "\n\tEnter a Name To Search: ";
    cin >> keyword;
    while (myFile >> first_name >> last_name >> phone_number)
    {
        if(keyword == first_name || keyword == last_name)
        {
            system("cls");
            cout << "\n\n\n\t\tContact Details...";
            cout << "\n\n\tfirst Name: " << first_name;
            cout << "\n\tLast Name: " << last_name;
            cout << "\n\tPhone Number: " << phone_number;
            found = true;
            break;
            cout << "\n\tPress Any Key To Continue..";
            getch();
            main();
        } 
    }
    if(found == false)
    cout << "\n\tNo Such Contact Found";
    cout << "\n\tPress Any Key To Continue..";
    getch();
    main();
}

bool check_digits(string x)
{
    if(x.length() == 10)
    return true;
    else
    return false;
}

bool check_number(string x)
{
    bool check = true;

    for(int i = 0; i < x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    if(check == false)
    return false;
}

void printContacts()
{
    string mytext;
    ifstream myFile("number.txt");
    while(getline(myFile, mytext))
    {
        cout <<"\t\tfirst:\tlast:\tphone:" << endl<<endl;
        cout <<"\t\t" << mytext << endl;
    } 
    cout << "\n\tPress Any Key To Continue..";
    getch();
    main();
}