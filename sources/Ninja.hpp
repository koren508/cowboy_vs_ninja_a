#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
using namespace std;
namespace ariel {}

class Ninja : public Character {
    private:
    int mobility;
    
    protected: //constructor in protected form so we won't be able to create an object of Ninja
    Ninja(const string name , const Point loc , int heal , int mob): Character(name,loc,heal) , mobility(mob){}  

    public:
    void move(Character* enemy);
    void slash(Character* enemy);
    int getMobility();
    string print() override;
};

class OldNinja : public Ninja {
    public:
    OldNinja(const string name , const Point loc):Ninja(name,loc,150,8){}
};

class YoungNinja : public Ninja {
    public:
    YoungNinja(const string name , const Point loc):Ninja(name,loc,100,14){}
};

class TrainedNinja : public Ninja {
    public:
    TrainedNinja(const string name , const Point loc):Ninja(name,loc,120,12){}
};
#endif