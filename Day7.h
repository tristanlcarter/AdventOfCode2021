#pragma once
#ifndef DAY7_H
#define DAY7_H
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class day7
{
public:
	int part1();
	int part2();
private:
	int FuelCost(vector<int> positions, int dest);
	int NewFuelCost(vector<int> positions, int dest);
};

#endif