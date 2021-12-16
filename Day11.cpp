#include "Day11.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int day11::part1()
{
    ifstream infile("../day11.txt");
    string line;
    // Read in all energies.
    vector< vector<int> > octi;
    while (getline(infile, line))
    {
        vector<int> row;
        for (int i = 0; i < line.size(); i++)
        {
            row.push_back((int)line[i] - '0');
        }

        octi.push_back(row);
    }

    // Start flash steps.
    int step = 0;
    while (step < 100)
    {
        step++;
        // Find the initial flashes.
        vector< pair<int, int> > flashed;
        for (int i = 0; i < octi.size(); i++)
        {
            for (int j = 0; j < octi[i].size(); j++)
            {
                if (++octi[i][j] > 9)
                    flashed.push_back(make_pair(i, j));
            }
        }

        // Recursively flash.
        while (flashed.size() != 0)
        {
            pair<int, int> c = flashed.back();
            flashed.pop_back();
            octi = makeFlash(octi, c);
        }

        // Reset to 0 after flashes.
        //printf("After step %i:\n", step);
        for (int i = 0; i < octi.size(); i++)
        {
            for (int j = 0; j < octi[i].size(); j++)
            {
                if (octi[i][j] > 9)
                    octi[i][j] = 0;
                //printf("%i", octi[i][j]);
            }
            //printf("\n");
        }
    }

    printf("The total flashes are: %i\n", flashes);

    return 1;
}

int day11::part2()
{
    ifstream infile("../day11.txt");
    string line;
    // Read in all energies.
    vector< vector<int> > octi;
    while (getline(infile, line))
    {
        vector<int> row;
        for (int i = 0; i < line.size(); i++)
        {
            row.push_back((int)line[i] - '0');
        }

        octi.push_back(row);
    }

    // Start flash steps.
    int step = 0;
    while (true)
    {
        step++;
        // Find the initial flashes.
        vector< pair<int, int> > flashed;
        for (int i = 0; i < octi.size(); i++)
        {
            for (int j = 0; j < octi[i].size(); j++)
            {
                if (++octi[i][j] > 9)
                    flashed.push_back(make_pair(i, j));
            }
        }

        // Recursively flash.
        while (flashed.size() != 0)
        {
            pair<int, int> c = flashed.back();
            flashed.pop_back();
            octi = makeFlash(octi, c);
        }

        // Reset to 0 after flashes.
        //printf("After step %i:\n", step);
        for (int i = 0; i < octi.size(); i++)
        {
            for (int j = 0; j < octi[i].size(); j++)
            {
                if (octi[i][j] > 9)
                    octi[i][j] = 0;
                //printf("%i", octi[i][j]);
            }
            //printf("\n");
        }

        if (adjacent_find(octi.begin(), octi.end(), not_equal_to<>()) == octi.end() && octi[0][0] == 0)
        {
            printf("The octi all flash together after step %i\n", step);
            break;
        }
    }

    return 1;
}

vector< vector<int> > day11::makeFlash(vector< vector<int> > octi, pair<int, int> coord)
{
    if (octi[coord.first][coord.second] == 10)
    {
        flashes++;

        if (coord.first != 0 && octi[coord.first - 1][coord.second] != 10)
        {
            if(++octi[coord.first - 1][coord.second] == 10)
                octi = makeFlash(octi, make_pair(coord.first - 1, coord.second));
        }

        if (coord.first != 0 && coord.second != 0 && octi[coord.first - 1][coord.second - 1] != 10)
        {
            if (++octi[coord.first - 1][coord.second - 1] == 10)
                octi = makeFlash(octi, make_pair(coord.first - 1, coord.second - 1));
        }

        if (coord.first != octi.size() - 1 && coord.second != 0 && octi[coord.first + 1][coord.second - 1] != 10)
        {
            if (++octi[coord.first + 1][coord.second - 1] == 10)
                octi = makeFlash(octi, make_pair(coord.first + 1, coord.second - 1));
        }

        if (coord.first != octi.size() - 1 && octi[coord.first + 1][coord.second] != 10)
        {
            if (++octi[coord.first + 1][coord.second] == 10)
                octi = makeFlash(octi, make_pair(coord.first + 1, coord.second));
        }

        if (coord.first != octi.size() - 1 && coord.second != octi[coord.first].size() - 1 && octi[coord.first + 1][coord.second + 1] != 10)
        {
            if (++octi[coord.first + 1][coord.second + 1] == 10)
                octi = makeFlash(octi, make_pair(coord.first + 1, coord.second + 1));
        }

        if (coord.second != 0 && octi[coord.first][coord.second - 1] != 10)
        {
            if (++octi[coord.first][coord.second - 1] == 10)
                octi = makeFlash(octi, make_pair(coord.first, coord.second - 1));
        }

        if (coord.second != octi[coord.first].size() - 1 && octi[coord.first][coord.second + 1] != 10)
        {
            if (++octi[coord.first][coord.second + 1] == 10)
                octi = makeFlash(octi, make_pair(coord.first, coord.second + 1));
        }

        if (coord.first != 0 && coord.second != octi[coord.first].size() - 1 && octi[coord.first - 1][coord.second + 1] != 10)
        {
            if (++octi[coord.first - 1][coord.second + 1] == 10)
                octi = makeFlash(octi, make_pair(coord.first - 1, coord.second + 1));
        }
    }
    return octi;
}