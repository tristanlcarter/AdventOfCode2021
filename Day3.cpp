#include "Day3.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int day3::part1()
{
    ifstream infile("../day3.txt");
    vector<int> common;
    int totalInput = 0;
    string line;
    
    getline(infile, line);
    for (int i = 0; i < line.size(); i++)
    {
        common.push_back((int)line[i] - 48);
    }
    totalInput++;

    while (getline(infile, line))
    {
        totalInput++;
        for (int i = 0; i < line.size(); i++)
        {
            common[i] += (int)line[i] - 48;
        }
    }

    string gamma = "";
    string epsilon = "";
    for (int i = 0; i < common.size(); i++)
    {
        if (common[i] > (totalInput / 2))
        {
            gamma.append("1");
            epsilon.append("0");
        }
        else {
            gamma.append("0");
            epsilon.append("1");
        }
    }

    int gRate = stoi(gamma, 0, 2);
    int eRate = stoi(epsilon, 0, 2);
    cout << "The power consumption (gamma * epsilon) is: " << gRate * eRate << "\n";

    return gRate * eRate;
}

int day3::part2()
{
    ifstream infile("../day3.txt");
    vector<string> generator;
    vector<string> scrubber;
    vector<string> tmp;
    double totalInput = 0;
    double totalOnes = 0;
    string line;

    while (getline(infile, line))
    {
        totalInput++;

        if (line[0] == '1')
        {
            generator.push_back(line); // Store all 1s in generator (temporary)
            totalOnes++;
        }
        else
        {
            scrubber.push_back(line); // Store all 0s in scrubber (temporary)
        }
    }

    if (totalOnes < (totalInput / 2))
    {
        tmp = generator;
        generator = scrubber;
        scrubber = tmp;
        tmp.clear();
    }

    // Check generator for oxygen rating.
    int i = 1;
    totalInput = 0;
    totalOnes = 0;
    vector<string> ones;
    vector<string> zeroes;
    while (generator.size() != 1)
    {
        // Iterate through all strings in the generator vector. Separate and count ones/zeroes.
        for (int j = 0; j < generator.size(); j++)
        {
            totalInput++;
            if (generator[j][i] == '1')
            {
                totalOnes++;
                ones.push_back(generator[j]);
            }
            else
                zeroes.push_back(generator[j]);
        }
        if (totalOnes >= (totalInput / 2))
        {
            generator = ones;
        }
        else
            generator = zeroes;

        i++;
        totalInput = 0;
        totalOnes = 0;
        ones.clear();
        zeroes.clear();
    }
    int oxygenRating = stoi(generator[0], 0, 2);

    // Check scrubber for C02 rating.
    i = 1;
    while (scrubber.size() != 1)
    {
        // Iterate through all strings in the scrubber vector. Separate and count ones/zeroes.
        for (int j = 0; j < scrubber.size(); j++)
        {
            totalInput++;
            if (scrubber[j][i] == '1')
            {
                totalOnes++;
                ones.push_back(scrubber[j]);
            }
            else
                zeroes.push_back(scrubber[j]);
        }
        if (totalOnes < (totalInput / 2))
        {
            scrubber = ones;
        }
        else
            scrubber = zeroes;

        i++;
        totalInput = 0;
        totalOnes = 0;
        ones.clear();
        zeroes.clear();
    }
    int co2Rating = stoi(scrubber[0], 0, 2);

    cout << "The life support rating (generator * scrubber) is: " << oxygenRating * co2Rating << "\n";

    return oxygenRating * co2Rating;
}