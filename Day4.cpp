#include "Day4.h"
#include "Board.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
int day4::part1()
{
    ifstream infile("../day4.txt");
    string line;
    getline(infile, line);
    stringstream bingoNumbers(line);

    vector<Board> boards;
    int row = 0;
    // Create the boards.
    int n;
    while (getline(infile, line))
    {
        if (line == "")
        {
            Board next;
            boards.push_back(next);
        }

        stringstream rowss(line);
        while (rowss >> n)
        {
            boards.back().AddNumber(n);
        }
    }

    string bingo;
    Board winner;
    bool won = false;
    while (getline(bingoNumbers, bingo, ','))
    {
        for (int i = 0; i < boards.size(); i++)
        {
            boards[i].MarkNumber(stoi(bingo));

            if (boards[i].HasWon())
            {
                winner = boards[i];
                won = true;
                break;
            }
        }

        if (won)
            break;
    }

    if (won)
    {
        int sum = 0;
        for (int j = 0; j < winner.numbers.size(); j++)
        {
            cout << winner.numbers[j].num << " ";
            if (!winner.numbers[j].marked)
            {
                sum += winner.numbers[j].num;
                cout << "|";
            }
            if (j % 5 == 0)
                cout << "\n";
        }

        cout << "The winning board score is " << sum * stoi(bingo) << ".\n";
    }
    else
        cout << "No winner was found.\m";

    return 1;
}

int day4::part2()
{
    ifstream infile("../day4.txt");
    string line;
    getline(infile, line);
    stringstream bingoNumbers(line);

    vector<Board> boards;
    int row = 0;
    // Create the boards.
    int n;
    while (getline(infile, line))
    {
        if (line == "")
        {
            Board next;
            boards.push_back(next);
        }

        stringstream rowss(line);
        while (rowss >> n)
        {
            boards.back().AddNumber(n);
        }
    }

    string bingo;
    Board winner;
    int lastBingo;
    int totalWon = 0;
    bool won = false;
    while (getline(bingoNumbers, bingo, ','))
    {
        totalWon = 0;
        for (int i = 0; i < boards.size(); i++)
        {
            boards[i].MarkNumber(stoi(bingo));

            if (boards[i].HasWon())
            {
                winner = boards[i];
                boards[i] = boards.back();
                boards.pop_back();
                lastBingo = stoi(bingo);
                totalWon++;
                won = true;
            }
        }
        if (totalWon == boards.size())
            break;
    }

    if (won)
    {
        int sum = 0;
        for (int j = 0; j < winner.numbers.size(); j++)
        {
            if (!winner.numbers[j].marked)
            {
                sum += winner.numbers[j].num;
            }
        }

        cout << "\nThe winning board score is " << sum * lastBingo << ".\n";
    }
    else
        cout << "\nNo winner was found.\m";

    return 1;
}

