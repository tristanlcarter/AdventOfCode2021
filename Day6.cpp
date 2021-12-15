#include "Day6.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
int day6::part1()
{
    ifstream infile("../day6.txt");
    string line;
    vector<int> fish;
    while (getline(infile, line, ','))
    {
        fish.push_back(stoi(line));
    }

    cout << "Initial fish: " << fish.size();

    int day = 1;
    while (day < 81)
    {
        // Decrement internal fish timer.
        int fishToAdd = 0;
        for (int i = 0; i < fish.size(); i++)
        {
            if (fish[i] == 0)
            {
                fishToAdd++;
                fish[i] = 6;
            }
            else
                fish[i]--;
        }

        // Add new fish.
        while (fishToAdd != 0)
        {
            fish.push_back(8);
            fishToAdd--;
        }

        // Print number of fish after the day, and increment.
        cout << "Number of fish after day " << day << ": " << fish.size() << "\n";
        day++;
    }

    return 1;
}

int day6::part2()
{
    ifstream infile("../day6.txt");
    string line;
    //vector<int> fish;
    vector<uint64_t> fish(9, 0);
    int size = 9;
    while (getline(infile, line, ','))
    {
        int num = stoi(line);
        fish[num]++;
    }
    
    uint64_t sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += fish[i];
    }
    cout << "Initial fish: " << sum;
    

    int day = 1;
    while (day < 257)
    {
        // Decrement internal fish timer.
        int fishToAdd = 0;
        uint64_t tmp = fish[0];
        for (int i = 0; i < size-1; i++)
        {
            fish[i] = fish[i + 1];
        }

        // Add new fish.
        fish[6] += tmp;
        fish[8] = tmp;

        // Increment day.
        sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += fish[i];
        }
        cout << "Number of fish after " << day << ": " << sum << "\n";
        day++;
    }

    return 1;
}

