#include "Day9.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int day9::part1()
{
    ifstream infile("../day9.txt");
    string line;
    vector< vector<int> > basin;
    while (getline(infile, line))
    {
        vector<int> input;
        for (int i = 0; i < line.size(); i++)
        {
            // Convert to ints.
            input.push_back(line[i] - '0');
        }

        basin.push_back(input);
    }

    int sum = 0;
    for (int i = 0; i < basin.size(); i++)
    {
        for (int j = 0; j < basin[i].size(); j++)
        {
            if (i != 0 && (basin[i][j] >= basin[i-1][j]))
                continue;
            if (i != basin.size() - 1 && (basin[i][j] >= basin[i + 1][j]))
                continue;
            if (j != 0 && (basin[i][j] >= basin[i][j - 1]))
                continue;
            if (j != basin[i].size() - 1 && (basin[i][j] >= basin[i][j + 1]))
                continue;

            sum += basin[i][j] + 1;
        }
    }

    printf("The sum of the risk levels are: %i\n", sum);

    return 1;
}

int day9::part2()
{
    ifstream infile("../day9.txt");
    string line;
    vector< vector<int> > basin;
    while (getline(infile, line))
    {
        vector<int> input;
        for (int i = 0; i < line.size(); i++)
        {
            // Convert to ints.
            input.push_back(line[i] - '0');
        }

        basin.push_back(input);
    }

    vector< pair<int, int> > deepBasins;
    for (int i = 0; i < basin.size(); i++)
    {
        for (int j = 0; j < basin[i].size(); j++)
        {
            if (i != 0 && (basin[i][j] >= basin[i - 1][j]))
                continue;
            if (i != basin.size() - 1 && (basin[i][j] >= basin[i + 1][j]))
                continue;
            if (j != 0 && (basin[i][j] >= basin[i][j - 1]))
                continue;
            if (j != basin[i].size() - 1 && (basin[i][j] >= basin[i][j + 1]))
                continue;

            deepBasins.push_back(make_pair(i, j));
        }
    }

    int size = 0;
    vector<int> largestBasins(3, 0);
    for (int k = 0; k < deepBasins.size(); k++)
    {
        size = SizeOfBasin(basin, deepBasins[k]);
        //printf("Size of basin is %i\n", size);
        if (size > largestBasins[0]) // replace smaller basins
        {
            largestBasins[2] = largestBasins[1];
            largestBasins[1] = largestBasins[0];
            largestBasins[0] = size;
        }
        else if (size > largestBasins[1])
        {
            largestBasins[2] = largestBasins[1];
            largestBasins[1] = size;
        }
        else if (size > largestBasins[2])
        {
            largestBasins[2] = size;
        }
    }

    
    printf("The 3 largest basins multiply to: %i\n", largestBasins[0] * largestBasins[1] * largestBasins[2]);

    return 1;
}

int day9::SizeOfBasin(vector< vector<int> > &b, pair<int, int> center)
{
    if (b[center.first][center.second] == 9)
        return 0;

    int size = 1;
    b[center.first][center.second] = 9;
    if (center.first != 0 && b[center.first - 1][center.second] != 9)
        size += SizeOfBasin(b, make_pair(center.first - 1, center.second));
    if(center.first != b.size() - 1 && b[center.first + 1][center.second] != 9)
        size += SizeOfBasin(b, make_pair(center.first + 1, center.second));
    if (center.second != 0 && b[center.first][center.second - 1] != 9)
        size += SizeOfBasin(b, make_pair(center.first, center.second - 1));
    if (center.second != b[center.first].size() - 1 && b[center.first][center.second + 1] != 9)
        size += SizeOfBasin(b, make_pair(center.first, center.second + 1));
    
    return size;
}