#include "Day1.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int day1::part1()
{
    cout << "*the code has disappeared*\n";
    return 1;
}

int day1::part2()
{
    ifstream infile("../day1-2.txt");
    vector<int> totalNum;
    string line;

    // Read in the first 3 values to establish the first set of 3 numbers.
    for (int j = 0; j < 3; j++)
    {
        getline(infile, line);
        stringstream tmpss(line);
        int n;
        tmpss >> n;
        totalNum.push_back(n);
        for (int k = 0; k < totalNum.size() - 1; k++)
        {
            totalNum[k] += n;
        }
    }

    int rangeInc = 0; // Variable to track the set of 3's that increased from previous.
    while (getline(infile, line))
    {
        int completeSet = totalNum[0];

        for (int i = 0; i < 2; i++)
        {
            totalNum[i] = totalNum[i + 1];
        }
        totalNum[2] = 0;

        stringstream iss(line);
        int num;
        iss >> num;
        for (int j = 0; j < 3; j++)
        {
            totalNum[j] += num;
        }

        if (completeSet < totalNum[0])
        {
            rangeInc++;
        }
    }

    cout << "Total increases are: " << rangeInc << '\n';

    return rangeInc;
}