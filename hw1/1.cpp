#include<iostream>
#include<vector>
#include<string>
#include<cstdlib> // for generate random variable
#include<ctime>  // for time(0)
using namespace std;

enum Cell{peg='P', empty='.'};
void ShowTable(vector<vector<char>> Arr, int type){
    char ptr[9]={'a','b','c','d','e','f','g','h','i'}; // col numbers
    cout<<"   ";
    for(int i=0; i<Arr[0].size(); i++){
        cout<<ptr[i];
    }
    cout<<endl;
    if(type==6){
        for(int i=0; i<5; i++){ // In type 6, I desing 9*9 vector, but I fill the last 5 rows
            cout<<i+1<<"  ";
            for(int j=0; j<Arr[0].size(); j++){
                if(Arr[i+4][j]==0) cout<<" "; 
                else cout<<Arr[i+4][j];
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0; i<Arr[0].size(); i++){ // Print table to screen
            cout<<i+1<<"  ";
            for(int j=0; j<Arr[0].size(); j++){
                if(Arr[i][j]==0) cout<<" ";
                else cout<<Arr[i][j];
            }
            cout<<endl;
        }
    }
    
}
int ControlofEnd(vector<vector<char>> Arr, int type){
    int test=1;
    for(int i=0; i<Arr[0].size()-2; i++){
        for(int j=0; j<Arr[0].size()-2; j++){
            if(type==6){
                if(Arr[i][j]==peg && Arr[i+1][j+1]==peg && Arr[i+2][j+2]==empty){ // right down
                    test=0;
                }
                if(Arr[i][j]==peg && Arr[i+1][j-1]==peg && Arr[i+2][j-2]==empty){ // left down
                    test=0;
                }
                if(Arr[i][j]==peg && Arr[i][j+2]==peg && Arr[i][j+4]==empty){ // right
                    test=0;
                }
                if(Arr[i][j]==peg && Arr[i][j-2]==peg && Arr[i][j-4]==empty){ // left
                    test=0;
                }
                if(Arr[i][j]==peg && Arr[i-1][j+1]==peg && Arr[i-2][j+2]==empty){ // right up
                    test=0;
                }
                if(Arr[i][j]==peg && Arr[i-1][j-1]==peg && Arr[i-2][j-2]==empty){ // left up
                    test=0;
                }

            }
            else{
                if(Arr[i][j]==peg && Arr[i][j+1]==peg && Arr[i][j+2]==empty){ // right
                    test=0;
                }
                if(Arr[i][j]==peg && Arr[i+1][j]==peg && Arr[i+2][j]==empty){ // down
                    test=0;
                }
            }  
        }
    }
    return test;
}
void ResultofGame(vector<vector<char>> Arr){
    int result=0;
    for(int i=0; i<Arr[0].size(); i++){
        for(int j=0; j<Arr[0].size(); j++){
            if(Arr[i][j]==peg) result++;
        }
    }
    cout<<"Result of Game= "<<result<<endl;  // print the result 
    if(result==1) cout<<"It's best score "<<endl;
}
void HumanGame(vector<vector<char>> Arr,int type){ // for user
    char ptr[4];
    int a,b; //a-row b-col
    while(ControlofEnd(Arr,type)!=1){ //Until end of the game
        cout<<"Enter the commants: "<<endl;
        cin>>ptr; // ptr[0] col, ptr[1] row, ptr[2] -, ptr[3] dimention 
        b=ptr[0]-65; // casting
        a=ptr[1]-49;
        if(type==6){
            a=a+4;
        }
        if(Arr[a][b]==peg){
            if(ptr[3]=='L'){
                if(type==6){
                    if(Arr[a][b-2]==peg && Arr[a][b-4]==empty){
                        Arr[a][b]=empty; Arr[a][b-2]=empty; Arr[a][b-4]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }
                else{
                    if(Arr[a][b-1]==peg && Arr[a][b-2]==empty){
                        Arr[a][b]=empty; Arr[a][b-1]=empty; Arr[a][b-2]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }
            }
            else if(ptr[3]=='R'){
                if(type==6){
                    if(Arr[a][b+2]==peg && Arr[a][b+4]==empty){
                        Arr[a][b]=empty; Arr[a][b+2]=empty; Arr[a][b+4]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }
                else{
                    if(Arr[a][b+1]==peg && Arr[a][b+2]==empty){
                        Arr[a][b]=empty; Arr[a][b+1]=empty; Arr[a][b+2]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }
            }
            else if(ptr[3]=='U'){
                if(type==6){
                    if(Arr[a-1][b-1]==peg && Arr[a-2][b-2]==empty){ //left up
                        Arr[a][b]=empty; Arr[a-1][b-1]=empty; Arr[a-2][b-2]=peg;
                    }
                    else if(Arr[a-1][b+1]==peg && Arr[a-2][b+2]==empty){ //right up
                        Arr[a][b]=empty; Arr[a-1][b+1]=empty; Arr[a-2][b+2]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }
                else{
                    if(Arr[a-1][b]==peg && Arr[a-2][b]==empty){
                        Arr[a][b]=empty; Arr[a-1][b]=empty; Arr[a-2][b]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }
            }
            else if(ptr[3]=='D'){
                if(type==6){
                    if(Arr[a+1][b-1]==peg && Arr[a+2][b-2]==empty){ //left down
                        Arr[a][b]=empty; Arr[a+1][b-1]=empty; Arr[a+2][b-2]=peg;
                    }
                    else if(Arr[a+1][b+1]==peg && Arr[a+2][b+2]==empty){ //right down
                        Arr[a][b]=empty; Arr[a+1][b+1]=empty; Arr[a+2][b+2]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }
                else{
                    if(Arr[a+1][b]==peg && Arr[a+2][b]==empty){
                        Arr[a][b]=empty; Arr[a+1][b]=empty; Arr[a+2][b]=peg;
                    }
                    else cerr<<"Wrong command"<<endl;
                }    
            }
            else cerr<<"Wrong comment"<<endl;
        }
        else cerr<<"Wrong command 1"<<endl;
        a=a-4;
        ShowTable(Arr,type);
    }
    ResultofGame(Arr);
}
void ComGame(vector<vector<char>> Arr,int type){
    srand(time(0));
    int a=0,b=0,c; // a-row b-col c-direction
    char d; //d-direction
    if(type==6){
        while(ControlofEnd(Arr,type)!=1){ //Until end of the game
            a=(rand()%5)+4;  //If a is odd, b must be odd
            b=(rand()%9);
            if(a%2==1){
                while(b%2!=1) b=(rand()%8);
            }
            else{
                while(b%2!=0) b=(rand()%8);
            }
            if(Arr[a][b]==peg){
                if(Arr[a][b-2]==peg && Arr[a][b-4]==empty){ //left
                    Arr[a][b]=empty; Arr[a][b-4]=peg; Arr[a][b-2]=empty;
                    a=a-4;
                    cout<<char(b+65)<<a+1<<"-L"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a][b+2]==peg && Arr[a][b+4]==empty){ //right
                    Arr[a][b]=empty; Arr[a][b+4]=peg; Arr[a][b+2]=empty;
                    a=a-4;
                    cout<<char(b+65)<<a+1<<"-R"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a-1][b-1]==peg && Arr[a-2][b-2]==empty){ //left up
                    Arr[a][b]=empty; Arr[a-1][b-1]=empty; Arr[a-2][b-2]=peg;
                    a=a-4;
                    cout<<char(b+65)<<a+1<<"-U"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a-1][b+1]==peg && Arr[a-2][b+2]==empty){ //right up
                    Arr[a][b]=empty; Arr[a-1][b+1]=empty; Arr[a-2][b+2]=peg;
                    a=a-4;
                    cout<<char(b+65)<<a+1<<"-U"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a+1][b-1]==peg && Arr[a+2][b-2]==empty){ //left down
                    Arr[a][b]=empty; Arr[a+1][b-1]=empty; Arr[a+2][b-2]=peg;
                    a=a-4;
                    cout<<char(b+65)<<a+1<<"-D"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a+1][b+1]==peg && Arr[a+2][b+2]==empty){ //right down
                    Arr[a][b]=empty; Arr[a+1][b+1]=empty; Arr[a+2][b+2]=peg;
                    a=a-4;
                    cout<<char(b+65)<<a+1<<"-D"<<endl;
                    ShowTable(Arr,type);
                }
            }
        }
    }
    else{
        while(ControlofEnd(Arr,type)!=1){  //Until end of the game
            a=rand()%(Arr[0].size()); // 0-Arr.size()
            b=rand()%(Arr[0].size());
            //cout<<a<<b<<endl;
            if(Arr[a][b]==peg){
                if(Arr[a][b-1]==peg && Arr[a][b-2]==empty){ //left
                    Arr[a][b]=empty; Arr[a][b-1]=empty; Arr[a][b-2]=peg;
                    cout<<char(b+65)<<a+1<<"-L"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a][b+1]==peg && Arr[a][b+2]==empty){ //right
                    Arr[a][b]=empty; Arr[a][b+1]=empty; Arr[a][b+2]=peg;
                    cout<<char(b+65)<<a+1<<"-R"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a-1][b]==peg && Arr[a-2][b]==empty){ //up
                    Arr[a][b]=empty; Arr[a-1][b]=empty; Arr[a-2][b]=peg;
                    cout<<char(b+65)<<a+1<<"-U"<<endl;
                    ShowTable(Arr,type);
                }
                else if(Arr[a+1][b]==peg && Arr[a+2][b]==empty){ //down
                    Arr[a][b]=empty; Arr[a+1][b]=empty; Arr[a+2][b]=peg;
                    cout<<char(b+65)<<a+1<<"-D"<<endl;
                    ShowTable(Arr,type);
                }
                else;
            }  
        }
    }
    ResultofGame(Arr);
}
void Greeting(){
    int a,b;
    cout<<"Welcome to Game"<<endl;
    cout<<"Choose the type of board"<<endl;
    cin>>a;
    cout<<"1) Human Game"<<endl<<"2) Computer Game"<<endl;
    cin>>b;
    int row;
    if(a==1 || a==4){ // There are row and col sizes, I wrote only row because of there are same
        row=7;
    }
    else if(a==2 || a==5 || a==6){
        row=9;
    }
    else if(a==3){
        row=8;
    }
    vector<vector<char>> Arr(row, vector<char> (row,0));  // Make Vector and fill with 0 (space)
    switch (a)
    {  // In this switch, we fill the vector 
    case 1:{
        for(int i=0; i<7; i++){
            if(i==0 || i==6){
                Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg;
            }
            else if(i==1 || i==5){
                Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg;
            }
            else if(i==2){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg;
                Arr[i][3]=empty;
                Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg;
            }
            else if(i==3 || i==4){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg;
            }
        }
    }break;
    case 2:{
        for(int i=0; i<9; i++){
            if(i==0 || i==1 || i==2 || i==6 || i==7 || i==8){
                Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg;
            }
            else if(i==3 || i==5){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg; Arr[i][7]=peg; Arr[i][8]=peg;
            }
            else if(i==4){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg;
                Arr[i][4]=empty;
                Arr[i][5]=peg; Arr[i][6]=peg; Arr[i][7]=peg; Arr[i][8]=peg;
            }
        }
    }break;
    case 3:{
        for(int i=0; i<8; i++){
            if(i==0 || i==1 || i==2 || i==6 || i==7){
                Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg;
            }
            else if(i==3 || i==5){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg; Arr[i][7]=peg;
            }
            else if(i==4){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg;
                Arr[i][3]=empty;
                Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg; Arr[i][7]=peg;
            }
        }
    }break;
    case 4:{
        for(int i=0; i<7; i++){
            if(i==0 || i==1 || i==5 || i==6){
                Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg;
            }
            else if(i==2 || i==4){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg;
            }
            else if(i==3){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg;
                Arr[i][3]=empty;
                Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg;
            }
        }
    }break;
    case 5:{
        for(int i=0; i<9; i++){
            if(i==0 || i==8){
                Arr[i][4]=peg;
            }
            else if(i==1 || i==7){
                Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg;
            }
            else if(i==2 || i==6){
                Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg;
            }
            else if(i==3 || i==5){
                Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg; Arr[i][4]=peg; Arr[i][5]=peg; Arr[i][6]=peg; Arr[i][7]=peg;
            }
            else if(i==4){
                Arr[i][0]=peg; Arr[i][1]=peg; Arr[i][2]=peg; Arr[i][3]=peg;
                Arr[i][4]=empty;
                Arr[i][5]=peg; Arr[i][6]=peg; Arr[i][7]=peg; Arr[i][8]=peg;
            }
        }
    }break;
    case 6:{   
        Arr[4][4]=empty;
        Arr[5][3]=peg; Arr[5][5]=peg;
        Arr[6][2]=peg; Arr[6][4]=peg; Arr[6][6]=peg;
        Arr[7][1]=peg; Arr[7][3]=peg; Arr[7][5]=peg; Arr[7][7]=peg;
        Arr[8][0]=peg; Arr[8][2]=peg; Arr[8][4]=peg; Arr[8][6]=peg; Arr[8][8]=peg;
    }break;
    default: cerr<<"Wrong choose bye"<<endl;
        break;
    }
    ShowTable(Arr,a);
    if(b==1) HumanGame(Arr,a);
    else if(b==2) ComGame(Arr,a);
    else cerr<<"Error"<<endl;
}
int main(){
    Greeting();
    return 0;
}
