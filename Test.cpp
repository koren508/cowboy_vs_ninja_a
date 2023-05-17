#include "doctest.h"
#include "sources/Team.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

TEST_SUITE("test Point class"){
    TEST_CASE("Constructor"){
        CHECK_NOTHROW(Point(0,0));
        CHECK_NOTHROW(Point(-1,1));
        CHECK_NOTHROW(Point(1,-1));
    }
    TEST_CASE("getters"){
    Point a(5.1,20.8);
    CHECK_EQ(a.get_x() , 5.1);
    CHECK_EQ(a.get_y() , 20.8);
    }
    TEST_CASE("distance function"){
        Point a(0,0);
        Point b(5,5);
        double tolerance = 0.00001;
        Point b_minus(-5,-5);
        CHECK(abs(a.distance(b) - 7.07107) < tolerance);
        CHECK(abs(a.distance(b_minus) - 7.07107) < tolerance);
        Point c(2.3 , -1.5);
        CHECK(abs(c.distance(b) - 7.03847) < tolerance);
        CHECK(abs(c.distance(b_minus) - 8.09568) < tolerance);
        CHECK(abs(c.distance(c) - 0) < tolerance);
    }
    TEST_CASE("moveTowards function"){
        Point a(1,0) , b(5,0); //a is src , b is dst
        CHECK_THROWS_AS(Point::moveTowards(a,b,-1) , std::invalid_argument);
        Point b2 = Point::moveTowards(a,b,4);
        Point b3 = Point::moveTowards(a,b,5);
        Point c = Point::moveTowards(a,b,2);   // c should be (3,0)
        CHECK_EQ(b2.get_x() , b.get_x());
        CHECK_EQ(b2.get_y() , b.get_y());
        CHECK_EQ(b3.get_x() , b.get_x());
        CHECK_EQ(b3.get_y() , b.get_y());
        CHECK_EQ(c.get_x() , 3);
        CHECK_EQ(c.get_y() , 0);
        //Negetive Points check
        Point d(-1,0) , e(-5,0);
        Point f = Point::moveTowards(d,e,2);
        CHECK_EQ(f.get_x() , -3);
        CHECK_EQ(f.get_y() , 0);
    }

}
TEST_SUITE("test Character class"){ //no need to check constructor cuz its an abstract class

    TEST_CASE("isAlive function and hit function"){
        Cowboy *rafi = new Cowboy("Rafi" , Point(5,5));
        Cowboy *tom = new Cowboy("Tom", Point(2,10));
        CHECK(tom->isAlive());
        tom->hit(110);
        CHECK_FALSE(tom->isAlive());
        rafi->hit(10);
        CHECK_EQ(rafi->getHealth() , 100);
        rafi->hit(-5);
        CHECK_EQ(rafi->getHealth() , 100);
    }
}
TEST_SUITE("test Cowboy class"){
    TEST_CASE("Constructor"){
        Cowboy *koren = new Cowboy("Koren" , Point(0,0));
        CHECK_EQ(koren->get_bullets() , 6);
        CHECK_EQ(koren->getHealth() , 110);
        CHECK_EQ(koren->getLocation().get_x() , 0);
        CHECK_EQ(koren->getLocation().get_y() , 0);
    }
}
TEST_SUITE("test Ninja class"){
    TEST_CASE("Constructor"){
        OldNinja *koren = new OldNinja("Koren", Point(0,1));             //health 150 , mobility 8
        YoungNinja *rafi = new YoungNinja("Rafi" , Point(1,3));        //health 100 , mobility 14
        TrainedNinja *itzik = new TrainedNinja("Itzik" , Point(5,2));    //health 120 , mobility 12
        CHECK_EQ(koren->getHealth() , 150); //check koren
        CHECK_EQ(koren->getLocation().get_x() , 0);
        CHECK_EQ(koren->getLocation().get_y() , 1);
        CHECK_EQ(koren->getName() , "Koren");
        CHECK_EQ(koren->getMobility() , 8);
        CHECK_EQ(rafi->getHealth() , 100); //check rafi
        CHECK_EQ(rafi->getLocation().get_x() , 1);
        CHECK_EQ(rafi->getLocation().get_y() , 3);
        CHECK_EQ(rafi->getName() , "Rafi");
        CHECK_EQ(rafi->getMobility() , 14);
        CHECK_EQ(itzik->getHealth() , 120); //check itzik
        CHECK_EQ(itzik->getLocation().get_x() , 5);
        CHECK_EQ(itzik->getLocation().get_y() , 2);
        CHECK_EQ(itzik->getName() , "Itzik");
        CHECK_EQ(itzik->getMobility() , 12);
    }
    TEST_CASE("move function"){
        OldNinja *koren = new OldNinja("Koren", Point(-1,-3));           //health 150 , mobility 8
        OldNinja *koren2 = new OldNinja("Koren2" , Point(-1,-3));        //health 150 , mobility 8
        YoungNinja *rafi = new YoungNinja("Rafi" , Point(15,18));        //health 100 , mobility 14
        CHECK_EQ(koren->getLocation().get_x() , koren2->getLocation().get_x());
        CHECK_EQ(koren->getLocation().get_y() , koren2->getLocation().get_y());
        koren->move(rafi);
        Point a = koren->getLocation();
        Point b = koren2->getLocation();
        CHECK_EQ(a.distance(b) , 8);
    }
    TEST_CASE("slash function"){
        OldNinja *koren = new OldNinja("Koren", Point(0,1));            //health 150 , mobility 8
        YoungNinja *rafi = new YoungNinja("Rafi" , Point(1,1));         //health 100 , mobility 14
        koren->slash(rafi);                                             //should hit rafi
        CHECK_EQ(rafi->getHealth() , 60);                               //100 - 40 = 60
        rafi->setLocation(Point(5,6));                                  //now rafi is too far so koren cant touch him.
        koren->slash(rafi);                                             //koren is too far so he get closer
        CHECK_EQ(rafi->getHealth() , 60);
        Point a = rafi->getLocation();
        Point b(1,1);
        CHECK(a.distance(b) != 0);
        rafi = NULL;
        CHECK_THROWS_AS(koren->slash(rafi) , runtime_error);
    }
}