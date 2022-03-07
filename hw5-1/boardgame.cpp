#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 
#include "boardgame.h"
using namespace std;
void BoardGame2D :: Playpeg(int row, int col, string c){
    if(vec[row][col]=='P'){
        if(c=="UP"){
            if(vec[row-1][col]=='P' && vec[row-2][col]=='.'){
                vec[row][col]='.'; vec[row-1][col]='.'; vec[row-2][col]='P';
            }
        }
        else if(c=="DOWN"){
            if(vec[row+1][col]=='P' && vec[row+2][col]=='.'){
                vec[row][col]='.'; vec[row+1][col]='.'; vec[row+2][col]='P';
            }
        }
        else if(c=="LEFT"){
            if(vec[row][col-1]=='P' && vec[row][col-2]=='.'){
                vec[row][col]='.'; vec[row][col-1]='.'; vec[row][col-2]='P';
            }
        }
        else if(c=="RIGHT"){
            if(vec[row][col+1]=='P' && vec[row][col+2]=='.'){
                vec[row][col]='.'; vec[row][col+1]='.'; vec[row][col+2]='P';
            }
        }
    }
}
void BoardGame2D :: Playpuz(int row, int col, string c){
    if(vec[row][col]!=0){ // its not a space
        if(c=="UP" && vec[row-1][col]==0 && row>=1){ 
            vec[row-1][col]=vec[row][col]; vec[row][col]=0; 
        }
        else if(c=="DOWN" && vec[row+1][col]==0 && row<=1){
            vec[row+1][col]=vec[row][col]; vec[row][col]=0; 
        }
        else if(c=="LEFT" && vec[row][col-1]==0 && col>=1){
            vec[row][col-1]=vec[row][col]; vec[row][col]=0; 
        }
        else if(c=="RIGHT" && vec[row][col+1]==0 && col<=1){
            vec[row][col+1]=vec[row][col]; vec[row][col]=0; 
        }
    }
}
void BoardGame2D :: Playklot(int row, int col, string c){
    if(vec[row][col]!=0){
        if(c=="UP" && row>=1){
            if((vec[row][col]=='1' || vec[row][col]=='2' || vec[row][col]=='3' || vec[row][col]=='4')&& vec[row-1][col]==0){
                vec[row-1][col]=vec[row][col]; vec[row][col]=0; 
            }
            else if(vec[row][col]=='C' || vec[row][col]=='F' || vec[row][col]=='B' || vec[row][col]=='E'){
                if(vec[row-1][col]==0){
                    vec[row-1][col]=vec[row][col]; vec[row+1][col]=0; 
                }
                else if(vec[row-1][col]==vec[row][col] && vec[row-2][col]==0){
                    vec[row-2][col]=vec[row][col];
                    vec[row][col]=0;
                }
            } 
            else if(vec[row][col]=='A'){
                if(vec[row][col]==vec[row][col-1] && vec[row-1][col]==0 && vec[row-1][col-1]==0){
                    vec[row-1][col]=vec[row][col]; vec[row-1][col-1]=vec[row][col];
                    vec[row+1][col]=0; vec[row+1][col-1]=0;
                }
                else if(vec[row][col]==vec[row][col-1] && vec[row][col]==vec[row-1][col-1] && vec[row][col]==vec[row-1][col]  && vec[row-2][col]==0 && vec[row-2][col-1]==0){
                    vec[row-2][col]=vec[row][col]; vec[row-2][col-1]=vec[row][col];
                    vec[row][col]=0; vec[row][col-1]=0;
                }
                else if(vec[row][col] == vec[row][col+1] && vec[row-1][col]==0 && vec[row-1][col+1]==0){
                    vec[row-1][col]=vec[row][col]; vec[row-1][col+1]=vec[row][col];
                    vec[row+1][col]=0; vec[row+1][col+1]=0;
                }
                else if(vec[row][col]==vec[row][col+1] && vec[row][col]==vec[row-1][col+1] && vec[row][col]==vec[row-1][col]  && vec[row-2][col]==0 && vec[row-2][col+1]==0){
                    vec[row-2][col]=vec[row][col]; vec[row-2][col+1]=vec[row][col];
                    vec[row][col]=0; vec[row][col+1]=0;
                }
            }
            else if(vec[row][col]=='D'){
                if(vec[row][col]==vec[row][col-1] && vec[row-1][col]==0 && vec[row-1][col-1]==0){
                    vec[row-1][col]=vec[row][col]; vec[row-1][col-1]=vec[row][col];
                    vec[row][col]=0; vec[row][col-1]=0;
                }
                else if(vec[row][col] == vec[row][col+1] && vec[row-1][col]==0 && vec[row-1][col+1]==0){
                    vec[row-1][col]=vec[row][col]; vec[row-1][col+1]=vec[row][col];
                    vec[row][col]=0; vec[row][col+1]=0;
                }
            }
        }
        else if(c=="DOWN" && row<=1){
            if((vec[row][col]==1 || vec[row][col]==2 || vec[row][col]==3 || vec[row][col]==4)&& vec[row+1][col]==0){
                vec[row+1][col]=vec[row][col]; vec[row][col]=0; 
            }
            else if(vec[row][col]=='C' || vec[row][col]=='F' || vec[row][col]=='B' || vec[row][col]=='E'){
                if(vec[row+1][col]==0){
                    vec[row+1][col]=vec[row][col]; vec[row-1][col]=0; 
                }
                else if(vec[row+1][col]==vec[row][col] && vec[row+2][col]==0){
                    vec[row+2][col]=vec[row][col];
                    vec[row][col]=0;
                }
            }
            else if(vec[row][col]=='A'){
                if(vec[row][col]==vec[row][col-1] && vec[row+1][col]==0 && vec[row+1][col-1]==0){
                    vec[row+1][col]=vec[row][col]; vec[row+1][col-1]=vec[row][col];
                    vec[row-1][col]=0; vec[row-1][col-1]=0;
                }
                else if(vec[row][col]==vec[row][col-1] && vec[row][col]==vec[row+1][col-1] && vec[row][col]==vec[row+1][col]  && vec[row+2][col]==0 && vec[row+2][col-1]==0){
                    vec[row+2][col]=vec[row][col]; vec[row+2][col-1]=vec[row][col];
                    vec[row][col]=0; vec[row][col-1]=0;
                }
                else if(vec[row][col] == vec[row][col+1] && vec[row+1][col]==0 && vec[row+1][col+1]==0){
                    vec[row+1][col]=vec[row][col]; vec[row+1][col+1]=vec[row][col];
                    vec[row-1][col]=0; vec[row-1][col+1]=0;
                }
                else if(vec[row][col]==vec[row][col+1] && vec[row][col]==vec[row+1][col+1] && vec[row][col]==vec[row+1][col]  && vec[row+2][col]==0 && vec[row+2][col+1]==0){
                    vec[row+2][col]=vec[row][col]; vec[row+2][col+1]=vec[row][col];
                    vec[row][col]=0; vec[row][col+1]=0;
                }
            }
            else if(vec[row][col]=='D'){
                if(vec[row][col]==vec[row][col-1] && vec[row+1][col]==0 && vec[row+1][col-1]==0){
                    vec[row+1][col]=vec[row][col]; vec[row+1][col-1]=vec[row][col];
                    vec[row][col]=0; vec[row][col-1]=0;
                }
                else if(vec[row][col] == vec[row][col+1] && vec[row+1][col]==0 && vec[row+1][col+1]==0){
                    vec[row+1][col]=vec[row][col]; vec[row+1][col+1]=vec[row][col];
                    vec[row][col]=0; vec[row][col+1]=0;
                }
            }
        }
        else if(c=="LEFT" && col>=1){
            if((vec[row][col]==1 || vec[row][col]==2 || vec[row][col]==3 || vec[row][col]==4)&& vec[row][col-1]==0){
                vec[row][col-1]=vec[row][col]; vec[row][col]=0; 
            }
            else if(vec[row][col]=='C' || vec[row][col]=='F' || vec[row][col]=='B' || vec[row][col]=='E'){
                if(vec[row][col]==vec[row-1][col] && vec[row][col-1]==0 && vec[row-1][col-1]==0){
                    vec[row][col-1]=vec[row][col]; vec[row-1][col-1]=vec[row][col];
                    vec[row][col]=0; vec[row-1][col]=0;
                }
                else if(vec[row][col] == vec[row+1][col] && vec[row][col-1]==0 && vec[row+1][col-1]==0){
                    vec[row][col-1]=vec[row][col]; vec[row+1][col-1]=vec[row][col];
                    vec[row][col]=0; vec[row+1][col]=0;
                }
            }
            else if(vec[row][col]=='A'){
                if(vec[row][col]==vec[row-1][col] && vec[row][col-1]==0 && vec[row-1][col-1]==0){
                    vec[row][col-1]=vec[row][col]; vec[row-1][col-1]=vec[row][col];
                    vec[row][col+1]=0; vec[row-1][col+1]=0;
                }
                else if(vec[row][col]==vec[row-1][col] && vec[row][col]==vec[row-1][col-1] && vec[row][col]==vec[row][col-1]  && vec[row][col-2]==0 && vec[row-1][col-2]==0){
                    vec[row][col-2]=vec[row][col]; vec[row-1][col-2]=vec[row][col];
                    vec[row][col]=0; vec[row-1][col]=0;
                }
                else if(vec[row][col] == vec[row+1][col] && vec[row][col-1]==0 && vec[row+1][col-1]==0){
                    vec[row][col-1]=vec[row][col]; vec[row+1][col-1]=vec[row][col];
                    vec[row][col+1]=0; vec[row+1][col+1]=0;
                }
                else if(vec[row][col]==vec[row+1][col] && vec[row][col]==vec[row+1][col-1] && vec[row][col]==vec[row][col-1]  && vec[row][col-2]==0 && vec[row+1][col-2]==0){
                    vec[row][col-2]=vec[row][col]; vec[row+1][col-2]=vec[row][col];
                    vec[row][col]=0; vec[row+1][col]=0;
                }
            }
            else if(vec[row][col]=='D'){
                if(vec[row][col-1]==0){
                    vec[row][col-1]=vec[row][col]; vec[row][col+1]=0; 
                }
                else if(vec[row][col-1]==vec[row][col] && vec[row][col-2]==0){
                    vec[row+2][col]=vec[row][col];
                    vec[row][col]=0;
                }
            }
        }
        else if(c=="RIGHT" && col<=2){
            if((vec[row][col]=='1' || vec[row][col]=='2' || vec[row][col]=='3' || vec[row][col]=='4')&& vec[row][col+1]==0){
                vec[row][col+1]=vec[row][col]; vec[row][col]=0; 
            }
            else if(vec[row][col]=='C' || vec[row][col]=='F' || vec[row][col]=='B' || vec[row][col]=='E'){
                if(vec[row][col]==vec[row-1][col] && vec[row][col+1]==0 && vec[row-1][col+1]==0){
                    vec[row][col+1]=vec[row][col]; vec[row-1][col+1]=vec[row][col];
                    vec[row][col]=0; vec[row-1][col]=0;
                }
                else if(vec[row][col] == vec[row+1][col] && vec[row][col+1]==0 && vec[row+1][col+1]==0){
                    vec[row][col+1]=vec[row][col]; vec[row+1][col+1]=vec[row][col];
                    vec[row][col]=0; vec[row+1][col]=0;
                }
            }
            else if(vec[row][col]=='A'){
                if(vec[row][col]==vec[row-1][col] && vec[row][col+1]==0 && vec[row-1][col+1]==0){
                    vec[row][col+1]=vec[row][col]; vec[row-1][col+1]=vec[row][col];
                    vec[row][col-1]=0; vec[row-1][col-1]=0;
                }
                else if(vec[row][col]==vec[row-1][col] && vec[row][col]==vec[row-1][col+1] && vec[row][col]==vec[row][col+1]  && vec[row][col+2]==0 && vec[row+2][col-1]==0){
                    vec[row][col+2]=vec[row][col]; vec[row-1][col+2]=vec[row][col];
                    vec[row][col]=0; vec[row-1][col]=0;
                }
                else if(vec[row][col] == vec[row+1][col] && vec[row][col+1]==0 && vec[row+1][col+1]==0){
                    vec[row][col+1]=vec[row][col]; vec[row+1][col+1]=vec[row][col];
                    vec[row][col-1]=0; vec[row+1][col-1]=0;
                }
                else if(vec[row][col]==vec[row+1][col] && vec[row][col]==vec[row+1][col+1] && vec[row][col]==vec[row][col+1]  && vec[row][col+2]==0 && vec[row+1][col+2]==0){
                    vec[row][col+2]=vec[row][col]; vec[row+1][col+2]=vec[row][col];
                    vec[row][col]=0; vec[row+1][col]=0;
                }
            }
            else if(vec[row][col]=='D'){
                if(vec[row][col+1]==0){
                    vec[row][col+1]=vec[row][col]; vec[row][col-1]=0; 
                }
                else if(vec[row][col+1]==vec[row][col] && vec[row][col+2]==0){
                    vec[row-2][col]=vec[row][col];
                    vec[row][col]=0;
                }
            }
        }
    }
}
void BoardGame2D :: playUser(string *a){
    //a[0]=2B a[1]=UP
    string b=a[0];
    string c=a[1]; 
    int row=(int)b[0]-49;
    int col=(int)b[1]-65;
    if(type==1){
        Playpeg(row,col,c);
    }
    else if(type==2){
        Playpuz(row,col,c);
    }
    else if(type==3){
        Playklot(row,col,c);
    }
}
void BoardGame2D :: playUser(){
    string a[2],b,c;
    while(endgame()!=true){
        cout<<"Enter the move: ";
        cin>>b>>c;
        a[0]=b;
        a[1]=c;
        playUser(a);
        print();
    }
    cout<<"Score: "<<boardScore()<<endl;
}
void BoardGame2D :: playAuto(){
    int row,col,cint;
    char colc;
    string c;
    row=rand()%vec.size();
    col=rand()%vec[0].size();
    cint = rand()%4+1; // 0-3 +1 -> 1-4
    if(cint==1) c="UP";
    else if(cint==2) c="DOWN";
    else if(cint==3) c="LEFT";
    else if(cint==4) c="RIGHT";
    cout<<row+1<<(char)(col+65)<<" "<<c<<endl;
    if(type==1){
        Playpeg(row,col,c);
    }
    else if(type==2){
        Playpuz(row,col,c);
    }
    else if(type==3){
        Playklot(row,col,c);
    }
}
void BoardGame2D :: playAutoAll(){
    while(endgame()!=true){
        playAuto();
    }
    cout<<"Score: "<<boardScore()<<endl;
}
void BoardGame2D :: print(){
    char ptr[7]={'a','b','c','d','e','f','g'}; // col numbers
    cout<<"   ";
    for(int i=0; i<vec[0].size(); i++){
        cout<<ptr[i];
    }
    cout<<endl;
    for(int i=0; i<vec.size(); i++){ // Print table to screen
        cout<<i+1<<"  ";
        for(int j=0; j<vec[0].size(); j++){
            if(vec[i][j]==0) cout<<" ";
            else cout<<vec[i][j];
        }
        cout<<endl;
    }
}
ostream & operator<<(ostream& output, const BoardGame2D& obj){
    return output;
}
int BoardGame2D :: ControlPegGame(){
    int test=1;
    for(int i=0; i<vec[0].size()-2; i++){
        for(int j=0; j<vec[0].size()-2; j++){
            if(vec[i][j]=='P' && vec[i][j+1]=='P' && vec[i][j+2]=='.'){ // right
                    test=0;
            }
            if(vec[i][j]=='P' && vec[i+1][j]=='P' && vec[i+2][j]=='.'){ // down
                test=0;
            }
            if(i>2){
                if(vec[i][j]=='P' && vec[i-1][j]=='P' && vec[i-2][j]=='.') test=0;
            }
            if(j>2){
                if(vec[i][j]=='P' && vec[i][j-1]=='P' && vec[i][j-2]=='.') test=0;
            }
        }        
    }
    return test;
}
bool BoardGame2D :: endgame(){
    bool result=false;
    if(type==1){
        if(ControlPegGame()==1) result=true;
    }
    else if(type==2){
        if(vec[0][0]==1 && vec[0][1]==2 && vec[0][2]==3 &&
           vec[1][0]==4 && vec[1][1]==5 && vec[1][2]==6 &&
           vec[2][0]==7 && vec[2][1]==8 && vec[2][2]==0) result=true;
    }
    else if(type=3){
        if(vec[3][1]=='A' && vec[3][2]=='A' && vec[4][1]=='A' && vec[4][2]=='A') result=true;
    }
    return result;
}
int BoardGame2D :: boardScore(){
    int result;
    if(type==1){
        result=-1;
        for(int i=0; i<vec[0].size(); i++){
            for(int j=0; j<vec[0].size(); j++){
                if(vec[i][j]=='P') result++;
            }
        }
    }
    else if(type==2 ||type==3){
        if(endgame()==true) result = 0; // its the best case    
        else result=1;
    }
    return result;
}
void BoardGame2D :: initialize(){
    int row,col;
    if(type==1){ // peg
        row=7; col=7;
    }
    else if(type==2){ // eightgame
        row=3; col=3;
    }
    else if(type==3){ // kloksi
        row=5; col=4;
    }
    vec.resize(row);
    for(int j=0; j<row; j++)
        vec[j].resize(col);
    for(int j=0; j<vec.size(); j++){ //row
        for(int k=0; k<vec[0].size(); k++){ //col
            vec[j][k]=0;
        }
    }//arrrangent for seg fault
}
void PegSolitaire :: init(int m){
    if(m==1){
            for(int j=0; j<7; j++){
                for(int k=0; k<7; k++){
                    if((j==0 || j==1 || j==5 || j==6)&&(k==2 || k==3 || k==4)) vec[j][k]='P';
                    else if(j==2 || j==3 || j==4) vec[j][k]='P';
                }
            }
            vec[3][3]='.';
        }
        else if(m==2){
            for(int j=0; j<7; j++){
                for(int k=0; k<7; k++){
                    if((j==0 || j==6)&&(k==2 || k==3 || k==4)) vec[j][k]='P';
                    else if(j==2 || j==3 || j==4) vec[j][k]='P';
                    else if((j==1 || j==5)&&(k==1 || k==2 || k==3 || k==4 || k==5)) vec[j][k]='P'; 
                }
            }
            vec[3][3]='.';
        }
        else cerr<<"This type is does not exist"<<endl;
}
void EightPuzzle :: init(){
    srand(time(NULL));
    vector<int> v = {1,2,3,4,5,6,7,8};
    int size = v.size();
    for(int i=0; i<size-1; i++){
        int j=i+rand()%(size-i);

        int temp; //swapping
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }
    int k=0;
    for(int m=0; m<8; m++){
        cout<<v[m];
    }
    cout<<endl;
    vec[0][0]=((char)v[0]+48); vec[0][1]=((char)v[1]+48); vec[0][2]=((char)v[2]+48);
    vec[1][0]=((char)v[3]+48); vec[1][1]=((char)v[4]+48); vec[1][2]=((char)v[5]+48);
    vec[2][0]=((char)v[6]+48); vec[2][1]=((char)v[7]+48); vec[2][2]=0;
}
void Klotski :: init(){
    vec[0][0]='C'; vec[1][0]='C';
    vec[0][1]='A'; vec[0][2]='A'; vec[1][1]='A'; vec[1][2]='A';
    vec[2][3]='E'; vec[3][3]='E';
    vec[0][3]='B'; vec[1][3]='B';
    vec[2][0]='F'; vec[3][0]='F';
    vec[2][1]='D'; vec[2][2]='D';
    vec[4][0]='1'; vec[3][1]='2'; vec[3][2]='3'; vec[4][3]='4';
}
