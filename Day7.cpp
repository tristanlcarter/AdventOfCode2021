#include "Day7.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
int day7::part1()
{
    ifstream infile("../day7.txt");
    string line;
    vector<int> positions;
    while (getline(infile, line, ','))
    {
        positions.push_back(stoi(line));
    }
    
    int dest = 0;
    int cost = FuelCost(positions, positions[0]);
    for (int i = 1; i < positions.size(); i++)
    {
        int nextCost = FuelCost(positions, positions[i]);
        if (nextCost < cost)
        {
            cost = nextCost;
            dest = positions[i];
        }
    }

    cout << "The cheapest cost is: " << cost << " fuel\n";

    return 1;
}

int day7::part2()
{
    ifstream infile("../day7.txt");
    string line;
    vector<int> positions;
    while (getline(infile, line, ','))
    {
        positions.push_back(stoi(line));
    }

    int dest = positions[0];
    int cost = NewFuelCost(positions, positions[0]);
    for (int i = 1; i < positions.size(); i++)
    {
        int nextCost = NewFuelCost(positions, positions[i]);
        if (nextCost < cost)
        {
            cost = nextCost;
            dest = positions[i];
        }
    }

    cout << "The cheapest cost is: " << cost << " fuel\n";

    return 1;
}

int day7::FuelCost(vector<int> positions, int dest)
{
    int totalCost = 0;
    for (int i = 0; i < positions.size(); i++)
    {
        int num = abs(positions[i] - dest);
        totalCost += num;
    }

    return totalCost;
}

int day7::NewFuelCost(vector<int> positions, int dest)
{
    int totalCost = 0;
    for (int i = 0; i < positions.size(); i++)
    {
        int num = abs(positions[i] - dest);
        int step = 0;
        int newCost = 0;
        for (int j = 0; j < num; j++)
        {
            newCost += ++step;
        }

        totalCost += newCost;
    }

    return totalCost;
}