#pragma once
#include<string>
#include"Writer.h"
#include"Triangulation.h"
class StlWriter:private Writer
{
public:
	StlWriter();
	~StlWriter();
	void Write(const string& outputFile,Triangulation& triangulation);
private:
	std::string fomulateText(Triangulation triangulation, Point point);
};
