#pragma once
#include <vector>
#include <string>
#include "Triangulation.h"
#include "Point.h"
#include "Reader.h"
#include<map>
#define  Tolerance 0.0000001
using namespace std;
class StlReader : private Reader_base{
public:
	StlReader();
	~StlReader();
	void read(const string& inputFile, Triangulation& triangulation);
	bool operator()(double a, double b) const;
};
