#pragma once
#ifndef DAY12_H
#define DAY12_H
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
class day12
{
public:
	vector<string> paths;
	int part1();
	int part2();
	struct Node
	{
		string Name;
		vector<Node> nodes;
	};
	map<string, Node> allNodes;
	void followPath(Node n, string path);
	void followPath2(Node n, string path, bool twoVisited);
};

#endif