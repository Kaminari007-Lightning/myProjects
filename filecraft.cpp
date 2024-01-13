#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

#define STRING_BIN "data.bin"

enum class options {add = 1, view = 2};

typedef struct {
    string name;
    double value;
    string level; 
} Student;

int main();

void addtobin(Student student, string filePath){
    ofstream myfile;
    myfile.open(filePath , ios::out | ios::app | ios::binary);
    myfile.write((char*)&student,sizeof(student));
    myfile.close();
    cout << "--> your text is added to the file !!! <--"<< endl;    
}

list<Student*> readbinfile(string filePath){
    list<Student*> filelines;
    string line;
    ifstream myfile(filePath, ios::binary | ios::ate);
    if (myfile.is_open()){
        streampos size = myfile.tellg();
        char* block = new char[size];
        myfile.seekg(0, ios::beg);
        myfile.read(block, size);
        myfile.close();

        long long biteIndex = 0;
        while(biteIndex < size){
            Student* student = (Student*)(block + biteIndex);
            filelines.push_back(student);
            biteIndex += sizeof(Student);
        }
    }else{
        cout << "unable to open file " << endl;
        exit(1);
    }
    return filelines;
}

void addtotextbin(){
    string text;
    int option;
    while(true){
        cout << "\n1. write to file\n2. read from file\n3. exit\n\n>>  ";
        cin >> option;
        if (option == (int)options::add){
            Student student;
           
            cout << "enter name:\n>>  ";
            cin >> ws;
            getline(cin, student.name);

            cout << "enter level:\n>>  ";
            getline(cin, student.level);

            cout << "enter value:\n>>  ";
            cin >> student.value;

            addtobin(student , STRING_BIN);
        }else if (option == (int)options::view){
            cout << "-->========= files content =========<--"<< endl;
            list<Student*> filelines = readbinfile(STRING_BIN);
            for(auto line = filelines.begin(); line != filelines.end(); line++){
                Student* student = *line;
                cout << "Student name: " << student->name << endl;
                cout << "Student level: " << student->level << endl;
                cout << "Student value: " << student->value << endl;
                cout <<"\n--------------------\n"; 

        }
        }else {
            cout << "\t\t======== thank you for using this program ========\n" << endl;
            break;
        }
        
    }

    system("pause");
}

int main(){
    addtotextbin();
    return 0;
}