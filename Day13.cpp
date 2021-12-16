#include "Day13.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;
int day13::part1()
{
    ifstream infile("../test13.txt");
    string line;
    bool isInstructions = false;
    paper.push_back(vector<char>(1, '.'));
    while (getline(infile, line))
    {
        if (line == "")
        {
            isInstructions = true;
            continue;
        }
        else if (isInstructions)
        {
            stringstream ss(line);
            string axis;
            int num;
            getline(ss, axis, '=');
            ss >> num;
            paper = FoldPaper(num, axis.back());
            //break;
        }
        else
        {
            stringstream ss(line);
            string tmp;
            int x, y;
            getline(ss, tmp, ',');
            y = stoi(tmp);
            ss >> x;

            if (x >= paper.size())
            {
                vector<char> v(paper[0].size(), '.');
                paper.resize(x + 1, v);
            }
            if (y >= paper.back().size())
            {
                for (int i = 0; i < paper.size(); i++)
                {
                    paper[i].resize(y + 1, '.');
                }
            }

            paper[x][y] = '#';
        }
    }

    int dots = 0;
    for (int i = 0; i < paper.size(); i++)
    {
        for (int j = 0; j < paper[i].size(); j++)
            if (paper[i][j] == '#')
                dots++;
    }

    printf("\nThe total dots are: %i\n", dots);

    return 1;
}

int day13::part2()
{
    return 1;
}

vector< vector<char> > day13::FoldPaper(int num, char axis)
{
    // [y][x] for output sake.
    vector< vector<char> > foldedPaper;
    if (axis == 'y')
    {
        vector<char> tmp(paper[0].size(), '.');
        foldedPaper.resize(num, tmp);

        int it = foldedPaper.size() - 1;
        for (int i = paper.size()/2 + 1; i < paper.size() && it >= 0; i++, it--)
        {
            for (int j = 0; j < paper[i].size(); j++)
            {
                foldedPaper[it][j] = paper[i][j];
            }
        }
        for (int i = foldedPaper.size() - num; i < foldedPaper.size(); i++)
        {
            for (int j = 0; j < foldedPaper[i].size(); j++)
            {
                if(paper[i][j] == '#')
                    foldedPaper[i][j] = '#';
            }
        }

        for (int i = 0; i < foldedPaper.size(); i++)
        {
            for (int j = 0; j < foldedPaper[i].size(); j++)
                cout << foldedPaper[i][j] << "";
            cout << "\n";
        }
        cout << "\n";
    }
    else if (axis == 'x')
    {
        vector<char> tmp(num, '.');
        foldedPaper.resize(paper.size(), tmp);

        int it = foldedPaper[0].size() - 1;
        for (int i = paper[0].size() - num; i < paper[0].size() && it >= 0; i++, it--)
        {
            for (int j = 0; j < foldedPaper[0].size(); j++)
            {
                foldedPaper[j][it] = paper[j][i];
            }
        }
        for (int i = foldedPaper.size() - num; i < foldedPaper.size(); i++)
        { // Something wrong here
            for (int j = 0; j < foldedPaper[i].size(); j++)
            {
                if (paper[i][j] == '#')
                    foldedPaper[i][j] = '#';
            }
        }

        for (int i = 0; i < foldedPaper.size(); i++)
        {
            for (int j = 0; j < foldedPaper[i].size(); j++)
                cout << foldedPaper[i][j] << "";
            cout << "\n";
        }
        cout << "\n";
    }

    return foldedPaper;
}