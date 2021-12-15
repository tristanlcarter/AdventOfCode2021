#pragma once
#ifndef DAY8_H
#define DAY8_H
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class day8
{
public:
	int part1();
	int part2();
private:
	bool ConvertAndCompare(string str1, string str2);
	bool IsStringInFirst(string first, string second);
};

#endif