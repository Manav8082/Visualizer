#include"StlReader.h"
#include<fstream>
#include<sstream>
#include "Triangle.h"
#include "Triangulation.h"
#include<iostream>

using namespace std;

StlReader::StlReader()
{
}

StlReader::~StlReader()
{
}


bool StlReader::operator()(double a, double b) const
{
	return (fabs(a - b) > Tolerance) ? a < b : false;
}

void StlReader::read(const string& inputFile, Triangulation& triangulation)
{
	map<double, int,StlReader> uniqueMap;
	std::vector<int> pointIndices;
	double xyz[3];
	ifstream myfile(inputFile);
	
	int index = 0;
	if(myfile.is_open())
	{
		string line;
		while (getline(myfile, line))
		{
			std::stringstream ss(line);
			string word;
			if (ss >> word)
			{
				if (word == "vertex")
				{
					ss >> xyz[0] >> xyz[1] >> xyz[2];
					for(int i=0;i<3;i++)
					{
						auto pair = uniqueMap.find(xyz[i]);
						if (pair == uniqueMap.end())
						{
							triangulation.UniqueNumbers.push_back(xyz[i]);
							uniqueMap[xyz[i]] = triangulation.UniqueNumbers.size() - 1;
							pointIndices.push_back(triangulation.UniqueNumbers.size()-1);
						}
						else
						{
							pointIndices.push_back(pair->second);
						}
					}
				}
			}
			if (pointIndices.size() == 9)
			{
				Point p1 = Point(pointIndices[0], pointIndices[1], pointIndices[2]);
				Point p2 = Point(pointIndices[3], pointIndices[4], pointIndices[5]);
				Point p3 = Point(pointIndices[6], pointIndices[7], pointIndices[8]);
				Triangle t(p1, p2, p3);
				triangulation.Triangles.push_back(t);
				pointIndices.clear();
			}
		}
	}
	else 
	{
		throw("file doesn't exist");
	}
}

