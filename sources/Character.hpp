#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
using namespace std;
namespace ariel {}

class Character{
    private:
    string name;
    Point location;
    int health;
    
    public:
    Character(const string name , const Point p , int health_amount);
    virtual ~Character();
    bool isAlive(); //only 0 returns False
    double distance(Character& dst);
    void hit(int num);
    string getName();
    Point getLocation();
    void setLocation(Point new_location);
    int getHealth();
    void setHealth(int new_hp);
    virtual string print() = 0; // makes the class an abstract
};
#endif