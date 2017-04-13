#include<iostream>
#include<vector>
#include<stack>
#include<ctime>
#include<cstdlib>
#include "game.h"

using namespace std;

Game::Game()
{
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
        {
            position.push_back(make_pair(i,j));
            data[i][j] = 0;
        }
}

Game::~Game()
{

}

void Game::randomInsert()
{
    position.clear();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(data[i][j] == 0)
                position.push_back(make_pair(i,j));
    //随机插入2或4
    if(position.empty() && !canMoveHorizontal() && !canMoveVertical())
    {
        display();
        cout<<"Game Over!"<<endl;
        exit(0);
    }
    if(position.empty())
    {
        display();
        return;
    }
    int insertNum = 2;
    srand((unsigned)time(0));
    if(rand()%2)
        insertNum = 4;
    pair<int,int> insertPos = position[rand()%position.size()];
    data[insertPos.first][insertPos.second] = insertNum;
    display();
}

void Game::display()
{
    for(int i = 0; i < ROW; i++)
    {
        cout<<"| - - - | - - - | - - - | - - - |"<<endl;
        cout<<"|";
        for(int j = 0; j < COL; j++)
        {
            cout.width(7);
            if(data[i][j] != 0)
                cout<<data[i][j]<<"|";
            else
                cout<<"      "<<"|";
        }
        cout<<endl;
    }
    cout<<"| - - - | - - - | - - - | - - - |"<<endl;
}

void Game::moveUp()
{
    for(int i = 0; i < COL; i++)
    {
        stack<int> numberStack;
        for(int j = ROW - 1; j >= 0; j--)
        {
            if(data[j][i] != 0)
            {
                numberStack.push(data[j][i]);
                data[j][i] = 0;
            }
        }

        int index = 0;
        while(!numberStack.empty())
        {
            int first = numberStack.top();
            numberStack.pop();
            if(numberStack.empty())
            {
                data[index][i] = first;
                break;
            }
            else
            {
                int second = numberStack.top();
                if(first == second)
                {
                    data[index++][i] = first * 2;
                    numberStack.pop();
                }
                else
                {
                    data[index++][i] = first;
                }
            }
        }
    }
    randomInsert();
}

void Game::moveDown()
{
    for(int i = 0; i < COL; i++)
    {
        stack<int> numberStack;
        for(int j = 0; j < ROW; j++)
        {
            if(data[j][i] != 0)
            {
                numberStack.push(data[j][i]);
                data[j][i] = 0;
            }
        }

        int index = ROW - 1;
        while(!numberStack.empty())
        {
            int first = numberStack.top();
            numberStack.pop();
            if(numberStack.empty())
            {
                data[index][i] = first;
                break;
            }
            else
            {
                int second = numberStack.top();
                if(first == second)
                {
                    data[index--][i] = first * 2;
                    numberStack.pop();
                }
                else
                {
                    data[index--][i] = first;
                }
            }
        }
    }
    randomInsert();
}

void Game::moveLeft()
{
    for(int i = 0; i < ROW; i++)
    {
        stack<int> numberStack;
        for(int j = COL - 1; j >= 0; j--)
        {
            if(data[i][j] != 0)
            {
                numberStack.push(data[i][j]);
                data[i][j] = 0;
            }
        }

        int index = 0;
        while(!numberStack.empty())
        {
            int first = numberStack.top();
            numberStack.pop();
            if(numberStack.empty())
            {
                data[i][index] = first;
                break;
            }
            else
            {
                int second = numberStack.top();
                if(first == second)
                {
                    data[i][index++] = first * 2;
                    numberStack.pop();
                }
                else
                {
                    data[i][index++] = first;
                }
            }
        }
    }
    randomInsert();
}

void Game::moveRight()
{
    for(int i = 0; i < ROW; i++)
    {
        stack<int> numberStack;
        for(int j = 0; j < COL; j++)
        {
            if(data[i][j] != 0)
            {
                numberStack.push(data[i][j]);
                data[i][j] = 0;
            }
        }

        int index = COL - 1;
        while(!numberStack.empty())
        {
            int first = numberStack.top();
            numberStack.pop();
            if(numberStack.empty())
            {
                data[i][index] = first;
                break;
            }
            else
            {
                int second = numberStack.top();
                if(first == second)
                {
                    data[i][index--] = first * 2;
                    numberStack.pop();
                }
                else
                {
                    data[i][index--] = first;
                }
            }
        }
    }
    randomInsert();
}

bool Game::canMoveHorizontal()
{
    for(int i = 0; i < ROW; i++)
    {
        vector<int> rowNumbers;
        for(int j = 0; j < COL; j++)
        {
            if(rowNumbers.empty())
                rowNumbers.push_back(data[i][j]);
            else
            {
                if(data[i][j] == rowNumbers.back())
                    return true;
                else
                    rowNumbers.push_back(data[i][j]);
            }
        }
    }
    return false;
}

bool Game::canMoveVertical()
{
    for(int i = 0; i < COL; i++)
    {
        vector<int> rowNumbers;
        for(int j = 0; j < ROW; j++)
        {
            if(rowNumbers.empty())
                rowNumbers.push_back(data[j][i]);
            else
            {
                if(data[j][i] == rowNumbers.back())
                    return true;
                else
                    rowNumbers.push_back(data[j][i]);
            }
        }
    }
    return false;
}
