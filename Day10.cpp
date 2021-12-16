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
    while (getline(infile, line))
    {
        vector<int> caves(4, 0);
        for (int i = 0; i < line.size(); i++)
        {
            switch (line[i])
            {
            case '(':
                caves[0]++;
                break;
            case '[':
                caves[1]++;
                break;
            case '{':
                caves[2]++;
                break;
            case '<':
                caves[3]++;
                break;
            case ')':
                caves[0]--;
                break;
            case ']':
                caves[1]--;
                break;
            case '}':
                caves[2]--;
                break;
            case '>':
                caves[3]--;
                break;
            }

            for (int j = 0; j < caves.size(); j++)
            {
                if (caves[j] < 0)
                {
                    printf("Corrupted line caused by: %c", line[i]);
                    break;
                }
            }
        }
    }

    printf("The corrupted line score is: %i\n", 0);

    return 1;
}

int day10::part2()
{
    return 1;
}