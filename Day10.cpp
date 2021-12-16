#include "Day10.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int day10::part1()
{
    ifstream infile("../day10.txt");
    string line;
    vector<int> corruption(4, 0);
    while (getline(infile, line))
    {
        vector<char> caves;
        bool corrupted = false;
        for (int i = 0; i < line.size(); i++)
        {
            switch (line[i])
            {
            case '(':
            case '[':
            case '{':
            case '<':
                caves.push_back(line[i]);
                break;
            case ')':
                if (caves.back() != '(')
                {
                    corruption[0]++;
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            case ']':
                if (caves.back() != '[')
                {
                    corruption[1]++;
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            case '}':
                if (caves.back() != '{')
                {
                    corruption[2]++;
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            case '>':
                if (caves.back() != '<')
                {
                    corruption[3]++;
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            }

            if (corrupted)
            {
                break;
            }
        }
    }

    // Calculate error score.
    int score = 0;
    score += (corruption[0] * 3);
    score += (corruption[1] * 57);
    score += (corruption[2] * 1197);
    score += (corruption[3] * 25137);

    printf("The total syntax error score is: %i\n", score);

    return 1;
}

int day10::part2()
{
    ifstream infile("../day10.txt");
    string line;
    vector<string> lines;
    while (getline(infile, line))
    {
        vector<char> caves;
        bool corrupted = false;
        for (int i = 0; i < line.size(); i++)
        {
            switch (line[i])
            {
            case '(':
            case '[':
            case '{':
            case '<':
                caves.push_back(line[i]);
                break;
            case ')':
                if (caves.back() != '(')
                {
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            case ']':
                if (caves.back() != '[')
                {
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            case '}':
                if (caves.back() != '{')
                {
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            case '>':
                if (caves.back() != '<')
                {
                    corrupted = true;
                }
                else
                    caves.pop_back();
                break;
            }

            if (corrupted)
            {
                break;
            }
        }

        // Keep incomplete lines;
        if(!corrupted && caves.size() != 0)
            lines.push_back(string(caves.begin(), caves.end()));
    }

    // Calculate error score.
    vector<uint64_t> scores;
    for (int i = 0; i < lines.size(); i++)
    {
        string tmp = "";
        uint64_t localScore = 0;
        for (int j = lines[i].size() - 1; j >= 0; j--)
        {
            int val = 0;
            switch (lines[i][j])
            {
            case '(':
                val = 1;
                break;
            case '[':
                val = 2;
                break;
            case '{':
                val = 3;
                break;
            case '<':
                val = 4;
                break;
            default:
                break;
            }

            localScore *= 5;
            localScore += val;
        }

        scores.push_back(localScore);
    }

    int score;
    sort(scores.begin(), scores.end());
    score = scores[scores.size() / 2];

    printf("The total syntax error score is: %i\n", score);

    return 1;
}