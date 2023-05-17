#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>
#include "Team.hpp"
using namespace std;

Team::Team(Character* lead): leader(lead){}
Team::~Team(){}
void Team::add(Character* character){}
void Team::attack(Team* enemy_team){}
int Team::stillAlive(){return 0;}
void Team::print(){}
// vector<Character> get_team(){}
// Character* get_leader(){}