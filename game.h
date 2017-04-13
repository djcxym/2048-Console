#ifndef GAME_H
#define GAME_H

#include<vector>
#include<map>

const int ROW = 4;
const int COL = 4;
class Game
{
private:
    int data[ROW][COL];
    std::vector<std::pair<int,int> > position;
public:
    Game();
    ~Game();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    bool canMoveHorizontal();
    bool canMoveVertical();

    void display();
    void randomInsert();
    void clear();
};

#endif // GAME_H
