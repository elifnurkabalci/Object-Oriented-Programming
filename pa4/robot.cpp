#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include "robot.h"
using namespace std;

Robot :: Robot(){
    srand(time(NULL));
    setType(3);
    setStrength(10);
    setHit(10); // for bulldozer
}
Robot :: Robot(int newType, int newStrength, int newHit){
    srand(time(NULL));
    this->type = newType;
    this->hit = newHit;
    this->strength = newStrength; // for types except bulldozer
}
int Robot :: getDamage(){
    int damage,total=0;
    int j=1;
    if(getType()=="roomba") j=2;
    for(int i=0; i<j; i++){
        damage = (rand() % strength) + 1; //general random damage generator
        cout<<getType() << " attacks for "<<damage<<" points!"<<endl;
        total += damage;
    }
    return total;
}
string Robot :: getType(){
    switch (this->type){
        case 0: return "optimusprime";
        case 1: return "robocop";
        case 2: return "roomba";
        case 3: return "bulldozer"; // for printing
    }
    return "unknown";
}
int optimusprime :: getDamage(){
    int a,i,result;
    i=rand()%100; // %15, x2 others normal
    a=humanic::getDamage(); // optimus , humanic and optimusprime
    if(i<15){
        cout<<"double point is active"<<endl; // x2 point
        result = 2;
    }
    else result = 1;
    return a * result; // multipy by 2 or normal
}
int robocop :: getDamage(){
    return humanic::getDamage();
}
int humanic :: getDamage(){
    int i,result;
    i=rand()%100;
    if(i<10){
        cout<<"50 point is active"<<endl;
        result=50;
    }
    else result=Robot::getDamage();
    return result;
}
int roomba :: getDamage(){ //roomba can attack twice
    return Robot::getDamage();
}
int bulldozer :: getDamage(){
    return Robot::getDamage();
}
