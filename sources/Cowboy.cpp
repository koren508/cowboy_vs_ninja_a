#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include "Cowboy.hpp"
#include <string>

Cowboy::Cowboy(const string name , const Point loc) : Character(name , loc , 110){
    bullets = 6;
}
// Cowboy& Cowboy::operator=(const Cowboy& other){}
void Cowboy::shoot(Character* enemy){}
string Cowboy::print(){
    return "C";
}
int Cowboy::get_bullets(){return bullets;}
