#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
#include <string>
#include <cmath>
using namespace std;

Point::Point(double x2 , double y2): x(x2) , y(y2){}
double Point::get_x(){return x;}
double Point::get_y(){return y;}
double Point::distance (Point& b) { 
    double distance = sqrt(pow(b.x - this->x, 2) + pow(b.y - this->y, 2)); // Pitagoras
    return distance;
}
Point Point::moveTowards( Point& src ,Point& dst , double range){
    if(range < 0) throw invalid_argument("given distance can not be negetive");
    double dist_src_to_dst = src.distance(dst); // distance between src and dst
    if(dist_src_to_dst <= range){
        return dst;
    }
    // Find the unit vector in the direction from src to dst
    double dx = dst.x - src.x;
    double dy = dst.y - src.y;
    double unitX = dx / dist_src_to_dst; // x-component of the unit vector
    double unitY = dy / dist_src_to_dst; // y-component of the unit vector
    // Multiply the unit vector by the distance n
    double CX = src.x + unitX * range; // x of point C
    double CY = src.y + unitY * range; // y of point C
    Point C = {CX, CY};
    return C;
}
void Point::print(){
    cout << "(" << x << "," << y << ")" << endl;
}