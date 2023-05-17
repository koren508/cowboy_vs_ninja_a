#include "Character.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

Character::Character(const string nam , const Point loc , int heal): name(nam),location(loc),health(heal){}
Character::~Character(){}
bool Character::isAlive(){return health > 0;} //only 0 returns False
double Character::distance(Character& dst){return location.distance(dst.location);}
void Character::hit(int num){if(num>0) health = health - num;}
string Character::getName(){return name;}
Point Character::getLocation(){return location;}
void Character::setLocation(Point new_location){this->location = new_location;}
int Character::getHealth(){return health;}
void Character::setHealth(int new_hp){health = new_hp;}