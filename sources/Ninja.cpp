#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include "Ninja.hpp"
#include <string>

void Ninja::move(Character* enemy){
    if(enemy != NULL){
    Point source = this->getLocation();
    Point dest = enemy->getLocation();
    int range = this->getMobility();
    Point new_location = Point::moveTowards(source , dest , range);
    this->setLocation(new_location);
    }
}
void Ninja::slash(Character* enemy){
    if(enemy == NULL) throw runtime_error("enemy pointer is NULL");
    if(this->isAlive()){
        Point a = this->getLocation();
        Point b = enemy->getLocation();
        if(a.distance(b)<=1){
            enemy->setHealth(enemy->getHealth() - 40);
        }else{
            this->move(enemy); //if target is far , move towards to him
        }
    }
}
int Ninja::getMobility(){return mobility;}
string Ninja::print(){return "N";}