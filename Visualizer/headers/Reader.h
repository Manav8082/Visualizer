#pragma once
#include <string>
#include"Triangulation.h"
class Reader_base 
{
public:
	virtual void read(const std::string& inputFile, Triangulation& triangulation)=0;
};