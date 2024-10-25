#pragma once
#include"Point.h"
#include"Triangle.h"
#include<vector>

using namespace std;

class Triangulation {
public:
	Triangulation();
	~Triangulation();
	vector<double> UniqueNumbers;
	vector<Triangle> Triangles;
	vector<Point> uniqueVertex;
	vector<Point> uniqueNormal;
};
