#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    char c;
    c='a';
    bool d=false;
    while(!d){
    if (_kbhit()){
      c=(_getch());
    }
    cout<<c;
    }
}