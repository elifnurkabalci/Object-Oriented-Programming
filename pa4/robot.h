#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string.h>
using namespace std;

class Robot{
private:
    int type;
    int strength;
    int hit;
public:
    Robot();
    Robot(int newType, int newStrength, int newHit);
    virtual int getDamage();
    string getType();
    void setType(int newType){ type = newType; }
    void setHit(int newhit){ hit = newhit; }
    int getHit(){ return hit;}
    void setStrength(int newStrength){ strength = newStrength; }
    int getStrength(){return strength;}
};

// humanic -> opti, robocop
// 50 damage puan -> %10 
// opti %15 damage x2
class humanic : public Robot{
public:    
    virtual int getDamage();
};
class optimusprime : public humanic{
public:
    int getDamage();
};
class robocop : public humanic{
public:    
    int getDamage();
};
class roomba : public Robot{ //fast attack twice
public:    
    int getDamage();
};
class  bulldozer : public Robot{
public:
    int getDamage();
};


#endif