#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define STRING_TEXT "data.txt"

void addtofile(string text, string filePath){
    ofstream myfile;
    myfile.open(filePath , ios::out | ios::app);
    myfile<< text + "\n";
    myfile.close();
}

int main(){
    string text;
    while(true){
        getline(cin, text);
        addtofile(text, STRING_TEXT);
    }

    system("pause");

    return 0;
}