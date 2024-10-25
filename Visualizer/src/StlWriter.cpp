#include"StlWriter.h"
#include<fstream>
#include<iomanip>
using namespace std;

StlWriter::StlWriter()
{
}
StlWriter::~StlWriter()
{
}

void StlWriter::Write(const string& outputFile,Triangulation& triangulation)
{
    ofstream myfile(outputFile);
    if (myfile.is_open())
    {
        for (Triangle& tri : triangulation.Triangles)
        {
            myfile << fixed << setprecision(6)
                << fomulateText(triangulation, tri.P1())
                << fomulateText(triangulation, tri.P2())
                << fomulateText(triangulation, tri.P3())
                << fomulateText(triangulation, tri.P1())<<"\n" << "\n";
        }
    }
    myfile.close();
}

std::string StlWriter::fomulateText(Triangulation triangulation, Point point)
{
    double x = triangulation.UniqueNumbers[point.X()];
    double y = triangulation.UniqueNumbers[point.Y()];
    double z = triangulation.UniqueNumbers[point.Z()];
    return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z)+"\n";
}