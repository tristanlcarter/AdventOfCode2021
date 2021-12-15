#include "Day5.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
int day5::part1()
{
    ifstream infile("../day5.txt");
    string line;
    vector<int> start, end;
    vector< vector<int> > field;
    while (getline(infile, line))
    {
        // Get the two coordinates.
        stringstream ss(line);
        size_t mid = line.find('-');
        string first, second;
        first = line.substr(0, mid - 1);
        second = line.substr(mid + 2, line.size());
        mid = first.find(',');
        start.push_back(stoi(first.substr(0, mid)));
        start.push_back(stoi(first.substr(mid+1, first.size())));
        mid = second.find(',');
        end.push_back(stoi(second.substr(0, mid)));
        end.push_back(stoi(second.substr(mid + 1, second.size())));
       
        if (start[0] != end[0] && start[1] != end[1])
        {
            start.clear();
            end.clear();
            continue;
        }

        // Expand the field to hold vents. (Apparently not needed but whatever)
        int greater = (end[0] > end[1]) ? end[0] : end[1];
        if (greater > field.size())
        {
            for (int i = 0; i < field.size(); i++)
            {
                field[i].resize(greater+1, 0);
            }
            vector<int> empty(greater+1, 0);
            field.resize(greater+1, empty);
        }

        // Add line of vents to field.
        while (start[0] != end[0] || start[1] != end[1])
        {
            field[ start[0] ][ start[1] ]++;
            if (start[0] != end[0])
            {
                if (start[0] > end[0])
                    start[0]--;
                else
                    start[0]++;
            }
            if (start[1] != end[1])
            {
                if (start[1] > end[1])
                    start[1]--;
                else
                    start[1]++;
            }
        }
        field[start[0]][start[1]]++;

        start.clear();
        end.clear();
    }
    // Count the dangerous vents.
    int total = 0;
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field.size(); j++)
        {
            if (field[i][j] >= 2)
                total++;
        }
    }
    
    cout << "The total points are: " << total << "\n";

    return 1;
}

int day5::part2()
{
    ifstream infile("../day5.txt");
    string line;
    vector<int> start, end;
    vector< vector<int> > field;
    while (getline(infile, line))
    {
        // Get the two coordinates.
        stringstream ss(line);
        size_t mid = line.find('-');
        string first, second;
        first = line.substr(0, mid - 1);
        second = line.substr(mid + 2, line.size());
        mid = first.find(',');
        start.push_back(stoi(first.substr(0, mid)));
        start.push_back(stoi(first.substr(mid + 1, first.size())));
        mid = second.find(',');
        end.push_back(stoi(second.substr(0, mid)));
        end.push_back(stoi(second.substr(mid + 1, second.size())));

        // Expand the field to hold vents. (Apparently not needed but whatever)
        int greater = (end[0] > end[1]) ? end[0] : end[1];
        if (greater > field.size())
        {
            for (int i = 0; i < field.size(); i++)
            {
                field[i].resize(greater + 1, 0);
            }
            vector<int> empty(greater + 1, 0);
            field.resize(greater + 1, empty);
        }

        // Add line of vents to field.
        while (start[0] != end[0] || start[1] != end[1])
        {
            field[start[0]][start[1]]++;
            if (start[0] != end[0])
            {
                if (start[0] > end[0])
                    start[0]--;
                else
                    start[0]++;
            }
            if (start[1] != end[1])
            {
                if (start[1] > end[1])
                    start[1]--;
                else
                    start[1]++;
            }
        }
        field[start[0]][start[1]]++;

        start.clear();
        end.clear();
    }
    // Count the dangerous vents.
    int total = 0;
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field.size(); j++)
        {
            if (field[i][j] >= 2)
                total++;
        }
    }

    cout << "The total points are: " << total << "\n";

    return 1;
}

