#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <cassert>
#include <vector>

using namespace std;
namespace ariel {}

class Team {
    private:
    vector<Character> Soldiers; //max_size 10
    Character* leader;
    
    public:
    Team(Character* leader);
    ~Team();
    void add(Character* character);
    void attack(Team* enemy_team);
    int stillAlive();
    void print();
    // vector<Character> get_team();
    // Character* get_leader();
};
#endif