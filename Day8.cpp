#include "Day8.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int day8::part1()
{
    ifstream infile("../day8.txt");
    string line;
    int digits = 0;
    while (getline(infile, line))
    {
        stringstream ss(line);
        getline(ss, line,  '|'); // throw away for now
        getline(ss, line, '|');
        
        string digit;
        stringstream output(line);
        while (output >> digit)
        {
            int s = digit.size();
            if (s == 2 || s == 4 || s == 3 || s == 7)
                digits++;
        }
    }

    cout << "1, 4, 7, and 8 show up " << digits << " times.\n";

    return 1;
}

int day8::part2()
{
    ifstream infile("../day8.txt");
    string line;
    int outputVals = 0;
    while (getline(infile, line))
    {
        vector<string> display(10, "");
        vector<string> sixDig;
        vector<string> fiveDig;
        vector<string> outputStrings;
        stringstream ss(line);
        string input;
        bool output = false;
        // Read in the entire line as inputs and outputs.
        while (ss >> input)
        {
            if (!output)
            {
                if (input == "|")
                {
                    output = true;
                    continue;
                }
                if (input.size() == 7)
                    display[8] = input;
                else if (input.size() == 2)
                    display[1] = input;
                else if (input.size() == 4)
                    display[4] = input;
                else if (input.size() == 3)
                    display[7] = input;
                else if (input.size() == 6)
                    sixDig.push_back(input);
                else if (input.size() == 5)
                    fiveDig.push_back(input);
            }
            else
            {
                outputStrings.push_back(input);
            }
        }
        // Decipher six digit displays.
        for (int i = 0; i < sixDig.size(); i++)
        {
            if (!IsStringInFirst(sixDig[i], display[1]))
                display[6] = sixDig[i];
            else if (!IsStringInFirst(sixDig[i], display[4]))
                display[0] = sixDig[i];
            else
                display[9] = sixDig[i];
        }
        // Decipher five digit displays.
        for (int i = 0; i < fiveDig.size(); i++)
        {
            if (IsStringInFirst(fiveDig[i], display[1]))
                display[3] = fiveDig[i];
            else if (IsStringInFirst(display[9], fiveDig[i]))
                display[5] = fiveDig[i];
            else
                display[2] = fiveDig[i];
        }
        // Decipher output value.
        string out = "";
        for (int i = 0; i < outputStrings.size(); i++)
        {
            for (int j = 0; j < display.size(); j++)
            {
                if (ConvertAndCompare(outputStrings[i], display[j]))
                {
                    out.append(to_string(j));
                    break;
                }
            }
        }

        outputVals += stoi(out);
    }

    cout << "The output values add up to " << outputVals << "\n";

    return 1;
}

bool day8::ConvertAndCompare(string str1, string str2)
{
    auto A = std::vector<char>(str1.begin(), str1.end());
    auto B = std::vector<char>(str2.begin(), str2.end());
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    string a(A.begin(), A.end());
    string b(B.begin(), B.end());
    return a == b;
}

bool day8::IsStringInFirst(string first, string second)
{
    for (int i = 0; i < second.size(); i++)
    {
        if (first.find(second[i]) == string::npos)
            return false;
    }

    return true;
}