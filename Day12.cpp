#include "Day12.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;
int day12::part1()
{
    ifstream infile("../day12.txt");
    string line;
    // Read in all nodes.
    while (getline(infile, line))
    {
        stringstream ss(line);
        string nd, nd2;
        getline(ss, nd, '-');
        ss >> nd2;

        allNodes[nd].Name = nd;
        allNodes[nd2].Name = nd2;
        allNodes[nd].nodes.push_back(allNodes[nd2]);
        allNodes[nd2].nodes.push_back(allNodes[nd]);
    }

    string path = "";
    Node n = allNodes["start"];
    followPath(n, path);

    printf("The total paths are: %i\n", paths.size());

    return 1;
}

int day12::part2()
{
    ifstream infile("../day12.txt");
    string line;
    // Read in all nodes.
    while (getline(infile, line))
    {
        stringstream ss(line);
        string nd, nd2;
        getline(ss, nd, '-');
        ss >> nd2;

        allNodes[nd].Name = nd;
        allNodes[nd2].Name = nd2;
        allNodes[nd].nodes.push_back(allNodes[nd2]);
        allNodes[nd2].nodes.push_back(allNodes[nd]);
    }

    string path = "";
    Node n = allNodes["start"];
    followPath2(n, path, false);

    printf("The total paths are: %i\n", paths.size());

    return 1;
}

void day12::followPath(Node n, string path)
{
    if (n.Name == "end")
    {
        path.append(n.Name);
        paths.push_back(path);
        return;
    }
    else if (path.find(n.Name) != string::npos && n.Name[0] >= 'a' && n.Name[0] <= 'z')
    {
        return;
    }
    else
        path.append(n.Name + ",");

    for (int i = 0; i < n.nodes.size(); i++)
    {
        followPath(allNodes[n.nodes[i].Name], path);
    }
}

void day12::followPath2(Node n, string path, bool twoVisited)
{
    if (n.Name == "end")
    {
        path.append(n.Name);
        paths.push_back(path);
        return;
    }
    else if (n.Name == "start" && path.find(n.Name) != string::npos)
    {
        return;
    }
    else if (path.find(n.Name) != string::npos 
            && n.Name[0] >= 'a' && n.Name[0] <= 'z')
    {
        if (path.find(n.Name) != path.rfind(n.Name) || twoVisited)
            return;
        else
        {
            twoVisited = true;
            path.append(n.Name + ",");
        }
    }
    else
        path.append(n.Name + ",");

    for (int i = 0; i < n.nodes.size(); i++)
    {
        followPath2(allNodes[n.nodes[i].Name], path, twoVisited);
    }
}