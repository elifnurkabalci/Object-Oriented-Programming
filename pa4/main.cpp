#include "robot.h"
#include <iostream>

using namespace std;

void play(Robot ch1, Robot ch2){
    cout<<ch1.getType()<<" vs "<<ch2.getType()<<endl;
    int hit1,hit2;
    while(true){
        hit1=ch1.getDamage();
        ch1.setHit(ch1.getHit()-hit1);
        if(ch1.getHit()<=0){ 
            cout<<ch1.getType()<<" is win"<<endl;         
            break;
        }
        hit2=ch2.getDamage();
        ch2.setHit(ch2.getHit()-hit2);
        if(ch2.getHit()<=0){ 
            cout<<ch2.getType()<<" is win"<<endl;            
            break;
        }
    }
    cout<<endl<<endl<<endl;
}
int main(){
    Robot chr1(0, 10, 75); // optimusprime
    Robot chr2(1, 10, 50); // robocop
    Robot chr3(2, 10, 60); // roomba
    Robot chr4; //bulldozer
    play(chr1,chr2);
    play(chr4,chr3);

    return 0;
}