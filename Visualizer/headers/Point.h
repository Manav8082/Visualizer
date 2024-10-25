#pragma once 

class Point 
{
private:
    int mX, mY, mZ;
public:
    Point(int x,int y,int z);
    ~Point();
    int X();
    int Y();
    int Z();
};
