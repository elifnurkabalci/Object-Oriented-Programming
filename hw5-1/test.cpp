#include <iostream>
#include <vector>
#include <string>
#include "boardgame.h"

using namespace std;
//There are test functions
void PlayPeg(PegSolitaire& peg){
    peg.type=1;
    int m;
    peg.initialize();
    cout<<"1)English"<<endl<<"2)European"<<endl;
    cin>>m;
    peg.init(m);
    peg.print();
}
void Play8Puzzle(EightPuzzle& puz){
    puz.type=2;
    puz.initialize();
    puz.init();
    puz.print();
}
void Playklotski(Klotski& klot){
    klot.type=3;
    klot.initialize();
    klot.init();
    klot.print();
}

int main(){
    PegSolitaire peg1, peg2;
    EightPuzzle puz1, puz2;
    Klotski klot1, klot2;

    //PlayPeg(peg1);
    //peg1.playUser();

    //PlayPeg(peg2);
    //peg2.playAutoAll();

    //Play8Puzzle(puz1);
    //puz1.playUser();

    //Play8Puzzle(puz2);
    //puz2.playAutoAll();

    Playklotski(klot1);
    klot1.playUser();

    //Playklotski(klot2);
    //klot2.playAutoAll;

    return 0;
}