#pragma once
#include<string>
#include"Triangulation.h"
class Writer
{
public:
	virtual void Write(const string& outputFile, Triangulation& traingulation) = 0;
};
