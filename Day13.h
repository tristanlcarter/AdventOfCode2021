#pragma once
#ifndef DAY13_H
#define DAY13_H
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
class day13
{
public:
	vector< vector<char> > paper;
	int part1();
	int part2();
	vector< vector<char> > FoldPaper(int num, char axis);
};

#endif