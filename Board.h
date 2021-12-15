#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>

struct Board
{
    public:
    Board();

    void MarkNumber(int n);

    bool HasWon();

    void AddNumber(int n);

    struct Number
    {
        int row = 0;
        int col = 0;
        int num = 0;
        bool marked = false;
        Number(int n, int r, int c) {
            num = n;
            row = r;
            col = c;
            marked = false;
        }
    };

    std::vector<Board::Number> numbers;
    std::vector<int> colMarked;
    std::vector<int> rowMarked;
};

#endif