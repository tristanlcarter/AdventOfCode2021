#pragma once
#ifndef DAY9_H
#define DAY9_H
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class day9
{
public:
	int part1();
	int part2();
	int SizeOfBasin(vector< vector<int> >& b, pair<int, int> center);
};

#endif