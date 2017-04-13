#include <iostream>
#include"game.h"
using namespace std;

int data[4][4];
int main()
{
    Game g;
    g.randomInsert();

    bool stop = false;
    while(!stop)
    {
        cout<<"Move Direction: ";
        char direction;
        cin>>direction;
        system("cls");
        if(direction == 'U')
            g.moveUp();
        else if(direction == 'D')
            g.moveDown();
        else if(direction == 'L')
            g.moveLeft();
        else if(direction == 'R')
            g.moveRight();
        else
            stop = true;
    }
    return 0;
}
