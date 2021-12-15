#include "Day2.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int day2::part1()
{
    ifstream infile("../day2.txt");
    int position = 0;
    int depth = 0;
    string line;

    while (getline(infile, line))
    {
        stringstream tmpss(line);
        string cmd;
        int n;
        tmpss >> cmd >> n;

        if (cmd == "forward")
        {
            position += n;
        }
        else if (cmd == "down")
        {
            depth += n;
        }
        else if (cmd == "up")
        {
            depth -= n;
        }
    }

    cout << "The position multiplied by the depth is: " << position * depth << '\n';

    return position * depth;
}

int day2::part2()
{
    ifstream infile("../day2.txt");
    int position = 0;
    int depth = 0;
    int aim = 0;
    string line;

    while (getline(infile, line))
    {
        stringstream tmpss(line);
        string cmd;
        int n;
        tmpss >> cmd >> n;

        if (cmd == "forward")
        {
            position += n;
            depth += (aim * n);
        }
        else if (cmd == "down")
        {
            aim += n;
        }
        else if (cmd == "up")
        {
            aim -= n;
        }
    }

    cout << "The position multiplied by the depth is: " << position * depth << '\n';

    return position * depth;
}