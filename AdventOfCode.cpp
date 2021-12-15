// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"

using namespace std;

int main()
{
    int day, part;
    while(true)
    {
        cout << "Enter the day: \n";
        cin >> day;
        if (day < 1 || day > 25)
            cout << "That isn't a valid day, idiot.\n\n";
        else 
            break;
    }
    while (true)
    {
        cout << "Enter 1 or 2 for the part: \n";
        cin >> part;
        if (part != 1 && part != 2)
            cout << "That's not a 1 or 2, dummy.\n\n";
        else
            break;
    }

    switch (day)
    {
    case 1:
        day1 d1;
        if (part == 1)
        {
            return d1.part1();
        }
        else if (part == 2)
        {
            return d1.part2();
        }
        break;
    case 2:
        day2 d2;
        if (part == 1)
        {
            return d2.part1();
        }
        else if (part == 2)
        {
            return d2.part2();
        }
        break;
    case 3:
        day3 d3;
        if (part == 1)
        {
            return d3.part1();
        }
        else if (part == 2)
        {
            return d3.part2();
        }
        break;
    case 4:
        day4 d4;
        if (part == 1)
        {
            return d4.part1();
        }
        else if (part == 2)
        {
            return d4.part2();
        }
        break;
    case 5:
        day5 d5;
        if (part == 1)
        {
            return d5.part1();
        }
        else if (part == 2)
        {
            return d5.part2();
        }
        break;
    case 6:
        day6 d6;
        if (part == 1)
        {
            return d6.part1();
        }
        else if (part == 2)
        {
            return d6.part2();
        }
        break;
    case 7:
        day7 d7;
        if (part == 1)
        {
            return d7.part1();
        }
        else if (part == 2)
        {
            return d7.part2();
        }
        break;
    case 8:
        day8 d8;
        if (part == 1)
        {
            return d8.part1();
        }
        else if (part == 2)
        {
            return d8.part2();
        }
        break;
    case 9:
        day9 d9;
        if (part == 1)
        {
            return d9.part1();
        }
        else if (part == 2)
        {
            return d9.part2();
        }
        break;
    default:
        cout << "That day is not complete.\n\n";
        break;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
