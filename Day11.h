#pragma once
#ifndef DAY11_H
#define DAY11_H
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class day11
{
public:
	int flashes = 0;
	int part1();
	int part2();
	vector< vector<int> > makeFlash(vector< vector<int> > octi, pair<int, int> coord);
};

#endif