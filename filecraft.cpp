#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define STRING_TEXT "data.txt"

enum class options {add = 1, view = 2};

int main();

void addtofile(string text, string filePath){
    ofstream myfile;
    myfile.open(filePath , ios::out | ios::app);
    myfile<< text + "\n";
    myfile.close();
    cout << "--> your text is added to the file !!! <--"<< endl; 
}

vector<string> readfromfile(string filePath){
    vector<string> filelines;
    string line;
    ifstream myfile(filePath);
    if (myfile.is_open()){
        while(getline(myfile, line)){
            filelines.push_back(line);
        }
    for(auto line = filelines.begin(); line != filelines.end(); line++){
            cout << *line << endl;
        }
    }else{
        cout << "unable to open file " << endl;
        exit(1);
    }
    return filelines;
}

int main(){
    string text;
    int option;
    while(true){
        cout << "\n1. write to file\n2. read from file\n3. exit\n\n>>  ";
        cin >> option;
        if (option == (int)options::add){
            cout << "enter text:\n>>  ";
            cin >> ws;
            getline(cin, text);
            addtofile(text, STRING_TEXT);
        }else if (option == (int)options::view){
            cout << "-->========= files content =========<--"<< endl;
            vector<string> filelines = readfromfile(STRING_TEXT);
        }else {
            cout << "\t\t======== thank you for using this program ========\n" << endl;
            break;
        }
        
    }

    system("pause");

    return 0;
}