#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

class Point {
    private:
    double x;
    double y;

    public:
    Point(double x2 , double y2);
    double get_x();
    double get_y();
    double distance (Point& b);
    static Point moveTowards(Point& src ,Point& dst , double distance);
    void print();
};
#endif