#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std; 

int main2(){

    int i=0;
    while (i <= 3){
        cout<<"sleeping"<<endl;
        Sleep(1000);
        i++;
        cout<<"waking"<<endl;
    }
    cout<<"checking kbhit : ";
    if(_kbhit()){
        char x = _getch();
        cout<<x<<endl;
    }    cout<<"checking kbhit : ";
    if(_kbhit()){
        char x = _getch();
        cout<<x<<endl;
    }
    cout<<"checking kbhit : ";
    if(_kbhit()){
        char x = _getch();
        cout<<x+2<<endl;
    }


}