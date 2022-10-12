#include <iostream>
#include <conio.h>
#include<windows.h>
using namespace std;

bool gameover;
int boarddimensions[1][2];
int snakePosition[1][2];
int fruitPosition[1][2];
int score = 0, tailLength = 1;
int cols = 2, rows = 1;
int snakeT[100][2];

enum Direction
{
    Pause = 0,
    Left,
    Right,
    Up,
    Down,
    NoInput
};

void snakemovement(Direction);
void gameLoop();
Direction dir;

void ClearScreen()
{	
COORD cursorPosition;	
cursorPosition.X = 0;	
cursorPosition.Y = 0;	
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void initialize()
{
    gameover = false;
    dir = Pause;
    boarddimensions[0][1] = 20;
    boarddimensions[0][0] = 20;
    snakePosition[0][1] = boarddimensions[0][1] / 2;
    snakePosition[0][0] = boarddimensions[0][0] / 2;
    fruitPosition[0][1] = rand() % boarddimensions[0][1] + 1;
    fruitPosition[0][0] = rand() % boarddimensions[0][0] + 1;
}

Direction getUserInput()
{
    Direction dir = NoInput;
    if (_kbhit())
    {
        switch (_getch())
        { // get ascii value of the character pressed
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
        case 'x':
            dir = Pause;
            break;
        }
    }
    return dir;
}

void drawBoard()
{
   
    cout << boarddimensions[0][1] << " " << boarddimensions[0][0] << endl;
    for (int i = 0; i < boarddimensions[0][1] + 1; i++)
    {
        for (int j = 0; j < boarddimensions[0][0] + 1; j++)
        {
            if (j == 0 || j == boarddimensions[0][0] || i == 0 || i == boarddimensions[0][1])
            {
                cout << "#";
            }
            else if (j == fruitPosition[0][0] && i == fruitPosition[0][1])
            {
                cout << "*";
            }
            else if (i == snakePosition[0][1] && j == snakePosition[0][0])
            {
                cout << "O";
            }
            else
            {
                bool print=false;
                 for(int k=0; k<tailLength; k++){
                   if(i == snakeT[k][1] && j== snakeT[k][0]){
                	cout<<"o";
                    print=true;
                 }
                }
                if(!print)
                cout << " ";
            }
        }
        cout << endl;
    }
}

void snakecoordinates(){

}

void increaseSnakeSize(int snakeposition[1][2], int tail)
{
   
    int temp[1][2], temp2[1][2];
    temp[0][0] = snakeT[0][0];
    temp[0][1] = snakeT[0][1];
    snakeT[0][0] = snakeposition[0][0];
    snakeT[0][1] = snakeposition[0][1];
    for (int i = 1; i < tail; i++)
    {
        temp2[0][0] = snakeT[i][0];
        temp2[0][1] = snakeT[i][1];
        snakeT[i][0] = temp[0][0];
        snakeT[i][1] = temp[0][1];
        temp[0][0] = temp2[0][0];
        temp[0][1] = temp2[0][1];
    }
}

void scorechange()
{
    
    score = score + 10; 
    
}

void CheckIfSnakeEatFruit(int snakeposition[1][2], int fruitposition[1][2])
{

    if (snakeposition[0][1] == fruitposition[0][1] && snakeposition[0][0] == fruitposition[0][0])
    {
        tailLength++;
        fruitposition[0][1] = rand() % boarddimensions[0][1] + 1;
        fruitposition[0][0] = rand() % boarddimensions[0][0] + 1;
       scorechange();
       
        
    }
}

bool CheckIfSnakeDied(int a[][2],int tlen)
{
    
    for(int i=1;i<tlen;i++){
        if(a[0][0]==a[i][0]&&a[0][1]==a[i][0]){
            return false;
        }
    }
    return true;
}

void snakemovement(Direction dir1)
{
    switch (dir1)
    {
        cout << "1" << endl;
    case Up:
        snakePosition[0][1]--;
        break;
    case Down:
        snakePosition[0][1]++;
        break;
    case Left:
        snakePosition[0][0]--;
        break;
    case Right:
        snakePosition[0][0]++;
        break;
    }
    CheckIfSnakeEatFruit(snakePosition, fruitPosition);
    //CheckIfSnakeDied();
}

bool checkPlayAgain()
{
    char shouldPlayAgain = 0;
    cout << "Press R to play again, any other key to exit." << endl;
    cin >> shouldPlayAgain;
    return (shouldPlayAgain == 'r' || shouldPlayAgain == 'R');
}

/*void gameLoop()
{
    int loopCtr = 0;
    Direction currDirection = NoInput, inputDirection = NoInput;
    while (loopCtr <= 10)
    {
        cout << "Game loop iteration # " << loopCtr << endl;
        drawBoard();
         inputDirection = getUserInput();
        if (inputDirection != NoInput)
        {
            currDirection = inputDirection;
        }
     //   snakemovement();
        loopCtr++;
    }
}*/

void displayGameStartMessage()
{
    cout << "1";
    cout << "Game Starts" << endl;
    cout << "How To Play" << endl;
    cout << "- Use w/a/s/d to move the snake" << endl;
    cout << "- Every Second adds 1 point to the score" << endl;
    cout << "- Eat fruit to earn 10x more points" << endl;
}

void displayGameOverMessage()
{
    cout << "Game Over" << endl;
    cout << "Result : " << endl;
    cout << "Score : " << endl;
}

int main()
{
    snakeT[0][0]=1000;
    snakeT[0][1]=1000;
  label1:  initialize();

    bool runForever = true;
    for (; runForever;)
    {


         gameLoop();
        //   displayGameOverMessage();
        //  runForever = checkPlayAgain();
    }
}

void gameLoop()
{
    bool gameover = false;
    while (!gameover)
    {
        ClearScreen();
        displayGameStartMessage();
        
        drawBoard();
        dir=getUserInput();
        snakemovement(dir);
         increaseSnakeSize(snakePosition, tailLength);
        cout<<tailLength<<endl;
         cout << score << endl;
    }
}