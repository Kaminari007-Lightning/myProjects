#include <iostream>
using namespace std;
typedef struct
{
    string names;
    double rate;
}list;
int anser;
int choice2;
char choice3;
void start(){
    cout<<"--------------------------------------------"<<endl;
    cout << "&- Welcome to my wail anime list Official -& "<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<< "\n1- see the list of anime"<< endl;
    cout<< "\n2- exit"<<endl;
    cout<< "\nyour anser: ";
    cin >> anser;
    cout<<"--------------------------------------------"<<endl;
}
int exit(){
    exit(1);
}
int anime_list(){
    list anime_list[5];
    anime_list[0].names = "\n1- black clover";
    anime_list[0].rate = 8.15;
    anime_list[1].names = "\n2- tokyo goul";
    anime_list[1].rate = 7.79;
    anime_list[2].names = "\n3- dragon ball";
    anime_list[2].rate = 7.43;
    anime_list[3].names = "\n4- boku no hero";
    anime_list[3].rate = 7.88;
    anime_list[4].names = "\n5- attck on titan";
    anime_list[4].rate = 8.54;
    while (true){
    cout << "this is the top five in wail anime list: "<< endl;
    for (int i = 0 ; i < 5 ; i++){
        cout << anime_list[i].names << endl;
    }
        cout << "\nNOTE: to see the rating\n- chose an anime (1-5): ";
    cin >> choice2;
    
    if (choice2 == 1)
    {
        cout <<anime_list[0].names<<" rate is: "<< anime_list[0].rate<<endl;
    }
    else if (choice2 == 2)
    {
        cout <<anime_list[1].names<<" rate is: "<< anime_list[1].rate<<endl;
    }
    else if (choice2 == 3)
    {
        cout <<anime_list[2].names<<" rate is: "<< anime_list[2].rate<<endl;
    }
    else if (choice2 == 4)
    {
        cout <<anime_list[3].names<<" rate is: "<< anime_list[3].rate<<endl;
    }
    else if (choice2 == 5)
    {
        cout <<anime_list[4].names<<" rate is: "<< anime_list[4].rate<<endl;
    }
    else
    {
        cout << "i said 1-5 are you blind";
    }
    cout << "\ndo you want to quit program y/n: ";
    cin >> choice3;
    if (choice3 == 'n'){
        start();
    }
    if (choice3 == 'y'){
        exit();
    }
    }
    return 0;
}
void choice(){
    if (anser == 1){
        anime_list();
    }
    else if (anser == 2)
    {
        exit(0);
    }
}
int main(){
    start();
    choice();
    system("pause");
    return 0;
}