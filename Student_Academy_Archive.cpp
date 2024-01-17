#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <unistd.h>
#include <list>
using namespace std;
#define FILE_PATH_BIN "Students.bin"
#define FILE_PATH_RECORD "Record.bin"
class Student{
    public:
    string name;
    string sex;
    int id;
    int lvl;
    float sem1,sem2,sem3,sum,reselt;
    void sumCalcu(){
        sum=sem1+sem2+sem3;
        reselt=(sum/3);
    }
};
void intro();
void addStudent(Student him, string filePath);
void singleStudent(int);
void updateInfo(int);
void result(int);
void deleteStudent(int);
void self_exit();
void MainMenu();
int main() {
    // intro();
    MainMenu();
}
// void intro()
// {
//     system("color 0C");
//     cout << "\n\n\n";
//     Sleep(300);
//     cout << "\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
//     Sleep(300);
//     system("color 0a");
//     cout << "\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
//     Sleep(300);
//     system("color 0b");
//     cout << "\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
//     Sleep(300);
//     system("color 0e");
//     cout << "\t\t\t * * * *     *     *     *   * * * * *         " << endl;
//     Sleep(300);
//     system("color 05");
//     cout << "\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
//     Sleep(300);
//     system("color 0C");
//     cout<<endl;
//     cout<<"\t\t\t============================================="<<endl;
//     Sleep(300);
//     system("color 0b");
//     cout<<"\t\t\t       THIS IS STUDENT ACADEMY ARCHIVE"<<endl;
//     Sleep(300);
//     system("color 0e");
//     cout<<"\t\t\t============================================="<<endl;
//     Sleep(300);
//     system("color 0A");
//     cout<<"\npress any key to continue...";
//     cin.ignore();
//     cin.get();
// }

list<Student*> readbinfile(string filePath){
    list<Student*> fileStudent;
    ifstream myfile(filePath, ios::in | ios::binary | ios::ate);
    if (myfile.is_open()){
        streampos size = myfile.tellg();
        char* memblock = new char[size];
        myfile.seekg(0, ios::beg);
        myfile.read(memblock, size);
        myfile.close(); 

        long long byteIndex = 0;
        while(byteIndex < size){
            Student* student = (Student*)(memblock + byteIndex);
            fileStudent.push_back(student);
            byteIndex += sizeof(Student);
        }
    }else{
        cout << "UNABLE TO OPEN FILE !!!" << endl;
        cin.ignore();
        cin.get();
        MainMenu();
    }
    return fileStudent;
}

void MainMenu(){
    short int choice; 
    system("cls");
    system("color 0A");
    Sleep(300);
    cout << "\n\n\n\t====================Student Academy Archive====================";
    Sleep(300);
    cout << "\n\n\n\t1. Add new student";
    Sleep(300);
    cout << "\n\n\t2. Show all students";
    Sleep(300);
    cout << "\n\n\t3. Show single students";
    Sleep(300);
    cout << "\n\n\t4. Edit student information";
    Sleep(300);
    cout << "\n\n\t5. The results of the final";
    Sleep(300);
    cout << "\n\n\t6. Delete student information";
    Sleep(300);
    cout << "\n\n\t7. Exit";
    Sleep(300);
    cout << "\n\n\t > ";
    Sleep(300);
    cin >> choice;
    if (choice == 1) {
        Student him;
        cout<<"\n\n";
        cout<<"\t=============== CREATE A NEW INFO ================\n";
            cout<<"\n\tEnter Your ID Number : #";
            cin>>him.id;
            if(him.id > 9999){cout<<"\n\tChoose A Number Dont Surpass \"9999\" ";addStudent(him, FILE_PATH_BIN);}
            cout<<"\n\tEnter Your Full Name : ";
            cin.ignore();
            getline(cin, him.name);
            cout<<"\n\tEnter Your Sex : ";
            cin>>him.sex;
            if(him.sex == "male"){}else if(him.sex == "female"){}else{cout<<"\n\tPlease Be Realistic Whoever You Are";addStudent(him, FILE_PATH_BIN);} 
            cout<<"\n\tEnter Your Year Level : ";
            cin>>him.lvl;
            if(him.lvl > 5){cout<<"\n\twhere Are You Going To. There 5 Levels In University ";sleep(5);addStudent(him, FILE_PATH_BIN);}
            cout<<"\n\tEnter Your Semaster 1 Mark : ";
            cin>>him.sem1;
            cout<<"\n\tEnter Your Semaster 2 MARK : ";
            cin>>him.sem2;
            cout<<"\n\tEnter Your Semaster 3 MARK : ";
            cin>>him.sem3;
            him.sumCalcu();
            addStudent(him, FILE_PATH_BIN);
    }else if(choice == 2){
        cout<<"\n\n";
        cout<<"\t\t\t- ALL STUDENTS INFORMATION -"<<endl;
        cout<<"=================================================================================="<<endl;
        cout<<"\n";
        list<Student*> filelines = readbinfile(FILE_PATH_BIN);
        bool check=false;
        for(auto line = filelines.begin(); line != filelines.end(); line++){
            Student* student = *line;
            cout<<"\tStudent ID Number : #"<<student->id<<endl;
            cout<<"\tStudent Full Name : "<<student->name<<endl;
            cout<<"\tStudent Sex : "<<student->sex<<endl;
            cout<<"\tStudent Year Level : "<<student->lvl<<endl;
            cout<<"\tSemaster 1 Mark : "<<student->sem1<<endl;
            cout<<"\tSemaster 2 Mark : "<<student->sem2<<endl;
            cout<<"\tSemaster 3 Mark : "<<student->sem3<<endl;
            cout<<"\n";
            cout<<"=================================================================================="<<endl;
            cout<<"\n";
            check=true;
        }
        if(check==false){
        cout<<"\t\t\t\tNO INFORMATION FOUND..."<<endl<<endl;
        cout<<"press any key to continue....";
        cin.ignore();
        cin.get();
        MainMenu();
        }
        cout<<"press any key to continue....";
        cin.ignore();
        cin.get();
        MainMenu();
    }else if(choice == 3){
        int t;
        cout<<"\n\tEnter Your ID Number To Be Search : #";
        cin>>t;
        singleStudent(t);
    }else if(choice == 4){
        int g;
        cout<<"\n\tEnter Your ID Number To Be Search : #";
        cin>>g;
        updateInfo(g);
    }else if(choice == 5){
        int j;
        cout<<"\n\tEnter Your ID Number To Be Search : #";
        cin>>j;
        result(j);
    }else if(choice == 6){
        int h;
        cout<<"\n\tEnter Your ID Number To Be Search : #";
        cin>>h;
        deleteStudent(h);
    }else if(choice == 7){
        self_exit();
    }else{
        cout<<"\n\tERROR";
        sleep(1);
        main();
    }
}

void addStudent(Student him, string filePath)
{
    system("cls");
    ofstream myfile;
    myfile.open(filePath , ios::out | ios::app | ios::binary);
    myfile.write((char*)&him,sizeof(him));
    myfile.close();
    cout<<"\n\t=================================================="<<endl;
    cout<<endl;
    cout<<"\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
    MainMenu();
}

void singleStudent(int s)
{
    system("cls");
    Student him;
    ifstream infile;
    infile.open(FILE_PATH_BIN,ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";
        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"=========================VIEW A SINGLE STUDENT INFORMATION========================\n";
    while(infile.read(reinterpret_cast<char*>(&him),sizeof(Student)))
    {
        if(him.id == s)
        {
        cout<<"\n";
        cout<<"\tStudent ID Number : #"<<him.id<<endl;
        cout<<"\tStudent Full Name : "<<him.name<<endl;
        cout<<"\tStudent Sex : "<<him.sex<<endl;
        cout<<"\tStudent Year Level : "<<him.lvl<<endl;
        cout<<"\tSemaster 1 Mark : "<<him.sem1<<endl;
        cout<<"\tSemaster 2 Mark : "<<him.sem2<<endl;
        cout<<"\tSemaster 3 Mark : "<<him.sem3<<endl;
        cout<<"\n";
        cout<<"=================================================================================="<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\n"; 
            cout<<"\t\t\t\tINFORMATION NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
        MainMenu();   
}

void updateInfo(int x)
{
    system("cls");
    Student him;
    fstream infile;
    infile.open(FILE_PATH_BIN,ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t============== MODIFY A STUDENT INFORMATION ==============\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&him),sizeof(Student));
     {
        if(him.id==x)
        {
            cout<<"\t\t\t\tStudent ID Number : #"<<him.id<<endl;
            cout<<"\t\t\t\tStudent Full Name : "<<him.name<<endl;
            cout<<"\t\t\t\tStudent Sex : "<<him.sex<<endl;
            cout<<"\t\t\t\tStudent Year Level : "<<him.lvl<<endl;
            cout<<"\t\t\t\tSemaster 1 Mark : "<<him.sem1<<endl;
            cout<<"\t\t\t\tSemaster 2 Mark : "<<him.sem2<<endl;
            cout<<"\t\t\t\tSemaster 3 Mark : "<<him.sem3<<endl<<endl<<endl;
        cout<<"\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
        cout<<"What Do You Want To Change:\n1. Your ID\n2. Your Name\n3. Your Sex\n4. Your Year level\n5. Your Semaster 1 Mark\n6. Your Semaster 2 Mark\n7. Your Semaster 3 Mark";
        short int choice2;
        cout<<"\n\n> ";
        cin>>choice2;
        switch (choice2)
        {
        case 1:
            cout<<"Enter Your New ID Number : #";
            cin>>him.id; 
            if(him.id > 9999){cout<<"\n\tChoose A Number Dont Surpass \"9999\" ";sleep(5);addStudent(him, FILE_PATH_BIN);}
            break;
        case 2:
            cout<<"Enter Your Full Name : ";
            cin.ignore();
            getline(cin, him.name);
            break;
        case 3:
            cout<<"Enter Your Sex : ";
            cin>>him.sex;  
            if(him.sex == "male"){}else if(him.sex == "female"){}else{cout<<"\n\tPlease Be Realistic Whoever You Are";sleep(5);addStudent(him, FILE_PATH_BIN);} 
            break;
        case 4:
            cout<<"Enter Your Year Level : ";
            cin>>him.lvl;
            if(him.lvl > 5){cout<<"\n\twhere Are You Going To. There 5 Levels In University ";sleep(5);addStudent(him, FILE_PATH_BIN);}
            break;
        case 5:
            cout<<"Enter Your Semaster 1 Mark : ";
            cin>>him.sem1;
            break;
        case 6:
            cout<<"Enter Your Semaster 2 Mark : ";
            cin>>him.sem2;
            break;
        case 7:    
            cout<<"Enter Your Semaster 3 Mark : ";
            cin>>him.sem3;
        default:
            cout<<"\n\tERROR";
            sleep(1);
            void updateInfo();
            break;
        }
    him.sumCalcu(); 
    int pos=(-1)*static_cast<int>(sizeof(Student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&him), sizeof(Student));
    cout<<"==================================================="<<endl<<endl;
    cout<<"\t\tThe File Is Successfully Updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tINFORMATION NOT FOUND"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
        MainMenu();   
  }

void result(int y)
{
    system("cls");
    Student him;
    ifstream infile;
    infile.open(FILE_PATH_BIN,ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&him),sizeof(Student)))
    {
        if(him.id==y)
        {
        cout<<"\t\tSTUDENT FULL NAME : "<<him.name<<endl;
        cout<<"\t\tSTUDENT ID NUMBER : #"<<him.id<<endl;
        cout<<"\t\tStudent Sex : "<<him.sex<<endl;
        cout<<"\t\tStudent Year Level : "<<him.lvl<<endl<<endl;
        cout<<"\t\tSUM : "<<him.sum<<endl<<endl;
        cout<<"\t\tFINAL RESELT : "<<fixed<<setprecision(2)<<him.reselt<<endl<<endl;
        if(him.reselt <= 10){
            cout<<"\t\tYOU HAVE FAILED"<<endl<<endl;
        }else if(him.reselt < 20){
            cout<<"\t\tYOU HAVE PASSED"<<endl<<endl;
        }else{
            cout<<"\t\tSOMETHING WRONG PLESSE GO CHECK YOUR INFO......."<<endl;
            cout<<"\n";
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
            MainMenu();
        }
        cout<<"\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tINFORMATION NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
        MainMenu();   
}

void deleteStudent(int w)
{
    system("cls");
    Student him;
    ifstream infile;
    infile.open(FILE_PATH_BIN,ios::binary);
    if(!infile)
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open(FILE_PATH_RECORD,ios::binary);
    infile.seekg(0,ios::beg);
    cout<<"\t\t\t\t===========DELETE A STUDENT INFO==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&him),sizeof(Student)))
    {
        if(him.id!=w)
        {
            outfile.write(reinterpret_cast<char*>(&him),sizeof(Student));
        }
    }
    infile.close();
    outfile.close();
    remove(FILE_PATH_BIN);
    rename(FILE_PATH_RECORD,FILE_PATH_BIN);
    cout<<endl;
    cout<<"\t\t\t\tINFORMATION SUCCESSFULLY DELETED"<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
    MainMenu();
}

void self_exit()
{
    cout << "\n\n\n\t\tThank You For Using My Software !";
    cout << "\n\t";
    exit(1);
}
