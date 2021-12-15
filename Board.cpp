#include "Board.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

Board::Board()
{
    colMarked.assign(5, 0);
    rowMarked.assign(5, 0);
}

void Board::MarkNumber(int n)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (n == numbers[i].num && !numbers[i].marked)
        {
            numbers[i].marked = true;
            colMarked[numbers[i].col]++;
            rowMarked[numbers[i].row]++;
        }
    }
}

bool Board::HasWon()
{
    for (int i = 0; i < 5; i++) {
        if (colMarked[i] == 5 || rowMarked[i] == 5)
            return true;
    }
    return false;
}

void Board::AddNumber(int n)
{
    if (numbers.size() == 25)
        return;

    int r = numbers.size() / 5;
    int c = numbers.size() % 5;
    Number num(n, r, c);
    numbers.push_back(num);
}

vector<Board::Number> numbers;
vector<int> colMarked;
vector<int> rowMarked;