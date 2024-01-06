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
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <unistd.h>
using namespace std;
struct student
{
char name[80];
char id[80];
int key;
float sem1,sem2,sem3,sum,reselt;
};

void intro();
void addStudent();
void showAll();
void singleStudent(int);
void updateInfo(int);
void result(int);
void deleteStudent(int);
void self_exit();

int main() {
    // intro();
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
    cout << "\n\n\t5. the results of the final";
    Sleep(300);
    cout << "\n\n\t6. delete student information";
    Sleep(300);
    cout << "\n\n\t7. exit";
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
            showAll();
            break;
        case 3:
            int t;
            cout<<"\n\tENTER YOUR KEY NUMBER : ";
            cin>>t;
            singleStudent(t);
            break;
        case 4:
            int g;
            cout<<"\n\tENTER YOUR KEY NUMBER : ";
            cin>>g;
            updateInfo(g);
            break;
        case 5:
            int j;
            cout<<"\n\tENTER YOUR KEY NUMBER : ";
            cin>>j;
            result(j);
            break;
        case 6:
            int h;
            cout<<"\n\tENTER YOUR KEY NUMBER : ";
            cin>>h;
            deleteStudent(h);
            break;
        case 7:
            self_exit();
            break;
        default:
            break;
    }
}

/* void intro()
{
    system("color 0C");
    cout << "\n\n\n";
    Sleep(500);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(500);
    system("color 0a");
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(500);
    system("color 0b");
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(500);
    system("color 0e");
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(500);
    system("color 05");
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(500);
    system("color 0C");
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\t\t       THIS IS STUDENT ACADEMY ARCHIVE"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\npress any key to continue...";
    cin.ignore();
    cin.get();
} */

void addStudent()
{
    system("cls");
    student him;
    ofstream outfile;
    outfile.open("Students.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t========== CREATE A NEW INFO ===========\n\n";
    cout<<"\n\tENTER YOUR FULL NAME : ";
    cin.ignore();
    cin.getline(him.name,80);
    cout<<"\n\tENTER YOUR ID NUMBER : 0/ ";
    cin.ignore();
    cin.get(him.id,80);
    cout<<"\n\tENTER YOUR KEY NUMBER : ";
    cin>>him.key;
    cout<<"\n\tENTER YOUR SEMASTER 1 MARK : ";
    cin>>him.sem1;
    cout<<"\n\tENTER YOUR SEMASTER 2 MARK : ";
    cin>>him.sem2;
    cout<<"\n\tENTER YOUR SEMASTER 3 MARK : ";
    cin>>him.sem3;
    him.sum=him.sem1+him.sem2+him.sem3;
    him.reselt=(him.sum/3);
    outfile.write(reinterpret_cast<char *> (&him), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
    main();
}

void showAll()
{
    system("cls");
    student him;
    ifstream infile;
    bool check=false;
    infile.open("Students.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t- ALL STUDENTS INFORMATION -"<<endl;
     cout<<"=================================================================================="<<endl;
     cout<<"\n";
    while(infile.read(reinterpret_cast<char*>(&him),sizeof(student)))
    {
        cout<<"\tSTUDENT FULL NAME : "<<him.name<<endl;
        cout<<"\tSTUDENT ID NUMBER :0/ "<<him.id<<endl;
        cout<<"\tSTUDENT Key NUMBER : "<<him.key<<endl;
        cout<<"\tSEMASTER 1 MARK : "<<him.sem1<<endl;
        cout<<"\tSEMASTER 2 MARK : "<<him.sem2<<endl;
        cout<<"\tSEMASTER 3 MARK : "<<him.sem3<<endl;
        cout<<"\tSUM : "<<him.sum<<endl<<endl;
        cout<<"\tFINAL RESELT : "<<him.reselt<<endl;
        cout<<"\n";
        cout<<"=================================================================================="<<endl;
        cout<<"\n";
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
    main();
}

void singleStudent(int s)
{
    system("cls");
    student him;
    ifstream infile;
    infile.open("Students.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";
        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"=========================VIEW A SINGLE STUDENT INFORMATION========================\n";
    while(infile.read(reinterpret_cast<char*>(&him),sizeof(student)))
    {
        if(him.key == s)
        {
        cout<<"\n";
        cout<<"\tSTUDENT FULL NAME : "<<him.name<<endl;
        cout<<"\tSTUDENT ID NUMBER :0/ "<<him.id<<endl;
        cout<<"\tSTUDENT Key NUMBER :"<<him.key<<endl;
        cout<<"\tSEMASTER 1 MARK : "<<him.sem1<<endl;
        cout<<"\tSEMASTER 2 MARK : "<<him.sem2<<endl;
        cout<<"\tSEMASTER 3 MARK : "<<him.sem3<<endl;
        cout<<"\tSUM : "<<him.sum<<endl<<endl;
        cout<<"\tFINAL RESELT : "<<him.reselt<<endl;
        cout<<"\n";
        cout<<"=================================================================================="<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
        main();    
}

void updateInfo(int x)
{
    system("cls");
    student him;
    fstream infile;
    infile.open("Students.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t============== MODIFY A REPORT CARD ==============\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&him),sizeof(student));
     {
         if(him.key==x)
         {
        cout<<"\t\t\t\tSTUDENT FULL NAME : "<<him.name<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :0/ "<<him.id<<endl;
        cout<<"\t\t\t\tSTUDENT Key NUMBER :"<<him.key<<endl;
        cout<<"\t\t\t\tSEMASTER 1 MARK : "<<him.sem1<<endl;
        cout<<"\t\t\t\tSEMASTER 2 MARK : "<<him.sem2<<endl;
        cout<<"\t\t\t\tSEMASTER 3 MARK : "<<him.sem3<<endl<<endl<<endl;
        cout<<"\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
        cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(him.name,80);
    cout<<"ENTER YOUR ID NUMBER : 0/";
    cin.ignore();
    cin.get(him.id,80);
    cout<<"ENTER YOUR Key NUMBER :";
    cin>>him.key;
    cout<<"ENTER YOUR SEMASTER 1 MARK : ";
    cin>>him.sem1;
    cout<<"ENTER YOUR SEMASTER 2 MARK : ";
    cin>>him.sem2;
    cout<<"ENTER YOUR SEMASTER 3 MARK : ";
    cin>>him.sem3;
    him.sum=him.sem1+him.sem2+him.sem3;
    him.reselt=(him.sum/3);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&him), sizeof(student));
    cout<<"==================================================="<<endl<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
        main();    
  }

void result(int y)
{
    system("cls");
    student him;
    ifstream infile;
    infile.open("Students.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&him),sizeof(student)))
    {
        if(him.key==y)
        {
        cout<<"\t\tSTUDENT FULL NAME : "<<him.name<<endl;
        cout<<"\t\tSTUDENT ID NUMBER : 0/"<<him.id<<endl<<endl;
        cout<<"\t\tSUM : "<<him.sum<<endl<<endl;
        cout<<"\t\tFINAL RESELT : "<<him.reselt<<endl<<endl;
        if(him.reselt <= 10){
            cout<<"\t\tYOU HAVE FAILED"<<endl<<endl;
        }else if(him.reselt < 20){
            cout<<"\t\tYOU HAVE PASSED"<<endl<<endl;
        }else{
            cout<<"\t\tSOMETHING WRONG PLESSE GO CHECK YOU INFO......."<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
            main();
        }
        
        cout<<"\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
        main();    
}

void deleteStudent(int w)
{
    system("cls");
    student him;
    ifstream infile;
    infile.open("Students.txt",ios::binary);
    if(!infile)
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Record.txt",ios::binary);
    infile.seekg(0,ios::beg);
    cout<<"\t\t\t\t===========DELETE A STUDENT INFO==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&him),sizeof(student)))
    {
        if(him.key!=w)
        {
             outfile.write(reinterpret_cast<char*>(&him),sizeof(student));
        }
    }
    infile.close();
    outfile.close();
    remove("Students.txt");
    rename("Record.txt","Students.txt");
    cout<<endl;
    cout<<"\t\t\t\tINFORMATION SUCCESSFULLY DELETED"<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
    main();
}

void self_exit()
{
    cout << "\n\n\n\t\tThank You For Using My Software !";
    cout << "\n\t";
    exit(1);
}