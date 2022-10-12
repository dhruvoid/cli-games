// snake2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width = 20, length=20;
enum Direction { Stop = 0, Left, Right, Up, Down };
Direction dir;
int x, y, fruitx, fruity,score=0,score2=0,snakelen[100],m,n;
int tailx[100],taily[100];
int taillength=0,kx,ky,lx,ly;//temp variables
void Setup() {
	gameover = false;
	dir = Stop;
	x = width / 2;
	y = length / 2;
	fruitx = rand() % width+1;
   	fruity = rand() % length+1;
	
}
void draw() {
	system("cls");
	cout << fruitx << " " << fruity << endl;
	for (int i = 0; i < length+1; i++) {
		for (int j = 0; j < width+1; j++) {
			if (j == 0 || j == length  || i == 0 || i == width) {
				cout << "#";
			}
			else if(j == fruitx && i == fruity) {
				cout << "*";

			}
			else if (i == y && j == x) {
				cout << "O";
			}
			else  {
				for(int k=1; i<taillength; k++){
                    if(i==taily[k]&&j==tailx[k]){
						cout<<"o";
					}
				}
				cout << " ";
			}
		}
		cout << endl;
	}
	
}

void makeBoard(){
	// init empty matrix
	// fill boundries
	// fill fruit 
	// fill snake
	// print on console
}

void drawSnake(int board[length][width], int snake[][2]){

}

void moveSnake(int snake[][2], int dir){
	
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) { //get ascii value of the character pressed
		case 'a':
			dir = Left;
			break;
		case 'w':
			dir = Up;
			break;
		case 's':
			dir = Down;
			break;
		case 'd':
			dir = Right;
			break;
		case'x':
			dir = Stop;
			break;
		}
	}
}

void logic() {
	kx=tailx[0];
	ky=taily[0];
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<taillength;i++){
		lx=tailx[i];
		ly=taily[i];
		tailx[i]=kx;
		taily[i]=ky;
		kx=lx;
		ky=ly;
	}
	switch (dir) { 
	case Up:
		y--;
		break;
	case Down:
		y++;
		break;
	case Left:
		x--;
		break;
	case Right:
		x++;
		break;
	default:
		break;
    }
	if (x >= width || x <= 0 || y >= length || y <= 0) {
		gameover = true;
		cout << "GAMEOVER";
	}cout << x << " " << y << endl;
	if (x == fruitx && y == fruity) {
		score += 10;
		fruitx = rand() % width+1;
		fruity = rand() % length+1;
		cout << fruitx << " " << fruity;
		taillength++;
	}
	cout << score << endl;
}

int main2() {
	tailx[0]=1000;
	taily[0]=1000;
        Setup();
	while (!gameover) {
		Sleep(100);
		draw();
		Input();
		logic();
		
		
	}
	char a;
	cout<< "press  r to replay  ";
       cin>> a;
	   if( a == 'r' ){
		main();
	   }
	
}

