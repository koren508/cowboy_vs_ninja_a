#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
using namespace std;
namespace ariel {}

class Cowboy : public Character{
    private:
    int bullets;

    public:
    Cowboy(const string name , const Point loc);
    // ~Cowboy();
    // Cowboy& operator=(const Cowboy& other);
    void shoot(Character* enemy);
    bool hasboolets(){return bullets > 0;}
    void reload(){bullets = 6;}
    string print() override;
    int get_bullets();
};
#endif