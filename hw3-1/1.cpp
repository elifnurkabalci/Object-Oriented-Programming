#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib> // for generate random variable
#include<ctime>  // for time(0)
using namespace std;

class PegSolitaire{
private:
    int row,type,mode;
    vector<vector<char>> Arr;
public:
    class Cell{};
    enum Celll{peg='P', empty='.'};
    char ptr[9]={'a','b','c','d','e','f','g','h','i'};
    char ptt[13];
    string loadfilenames[5]={"load1.txt","load2.txt","load3.txt","load4.txt","load5.txt"};
    string savefilenames[5]={"save1.txt","save2.txt","save3.txt","save4.txt","save5.txt"};
    inline void setrow(int r){ row = r; }
    inline int getrow(){return row; }
    inline void settype(int t){ type = t; }
    inline int gettype(){return type; }
    inline void setmode(int m){ mode = m; }
    inline int getmode(){return mode; }
    PegSolitaire(); // constructor
    void ShowTable(); // print the screen
    void play(); //computer , play single step
    void play(int a, int b); // user , play single step
    int ControlofGame(); // return if the game ended
    int playGame(); // ask board type , boards should be printed
    int TotalPeg(); //return total number of pegs in all game boards
    int NumOfPeg();
    int NumOfEmpt();
    int NumofOutPeg();
    bool Compare(PegSolitaire &obj);
    void WriteFile(ofstream& savefile);
    void ReadFile();
    void FillArr();
    void UserInput(int *a, int *b,ofstream& savefile);
    void Moving(int a,int b);
    void ResultofGame();
    void ComMov(int *a, int *b);
};
PegSolitaire :: PegSolitaire(){
    settype(playGame());
    static int numof=-1;
    if(type==1 || type==4) setrow(7);
    else if(type==2 || type==5 || type==6) setrow(9);
    else if(type==3) setrow(8);
    Arr.resize(row);
    for(int i=0; i<row; i++) Arr[i].resize(row);
    FillArr();
    ShowTable();
    ofstream savefile;
    numof++;
    savefile.open(savefilenames[numof]); // begin to save 
    savefile<<type<<mode<<endl;
    srand(time(0));
    if(mode==1){
        int a,b;
        while(ControlofGame()!=1){ //Until end of the game
            UserInput(&a,&b,savefile);
            play(a,b);
            if(a==0 && b==0) break;
        }
        ResultofGame();
    } 
    else if(mode==2) play();
    else cerr<<"Error"<<endl;
    savefile.close();
}
void PegSolitaire :: ResultofGame(){
    int result= NumOfPeg();
    cout<<"Result of Game= "<<result<<endl;  // print the result 
    if(result==1) cout<<"It's best score "<<endl;
}
void PegSolitaire :: FillArr(){
    switch (type)
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
    case 7:{
        ReadFile();
    }break;
    default: cerr<<"Wrong choose bye"<<endl;
        break;
    }
}
void PegSolitaire :: UserInput(int *a, int *b, ofstream& savefile){
    const int c=0;
    cout<<"Enter the commants: "<<endl;
    cin>>ptt;
    if(ptt[0]=='S' && ptt[1]=='A' && ptt[2]=='V' && ptt[3]=='E'){ //SAVE FILE.TXT
        WriteFile(savefile);
        *a=0;
        *b=0;
    }
    else{
        *b=ptt[0]-65; // casting
        *a=ptt[1]-49;
    }
}
void PegSolitaire :: Moving(int a,int b){
    if(a==0 && b==0){
        cerr<<"BYE"<<endl; 
    }
    else{
        if(type==6) a=a+4;
        if(Arr[a][b]==peg){
            if(ptt[3]=='L'){
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
            else if(ptt[3]=='R'){
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
            else if(ptt[3]=='U'){
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
            else if(ptt[3]=='D'){
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
        ShowTable();
    } 
}
int PegSolitaire :: playGame(){
    cout<<"Choose the type of board"<<endl<<"For Arbitrary enter '7': "<<endl; // Its console
    cin>>type;
        
    cout<<"1) Human Game"<<endl<<"2) Computer Game"<<endl;
    cin>>mode;
    return type;
}
void PegSolitaire :: ShowTable(){
    cout<<"   ";
    for(int i=0; i<row; i++) cout<< ptr[i];
    cout<<endl;
    if(type==6){
        for(int i=0; i<5; i++){ // In type 6, I desing 9*9 vector, but I fill the last 5 rows
            cout<<i+1<<"  ";
            for(int j=0; j<row; j++){
                if(Arr[i+4][j]==0) cout<<" "; 
                else cout<<Arr[i+4][j];
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0; i<row; i++){ // Print table to screen
            cout<<i+1<<"  ";
            for(int j=0; j<row; j++){
                if(Arr[i][j]==0) cout<<" ";
                else cout<<Arr[i][j];
            }
            cout<<endl;
        }
    }
}
int PegSolitaire :: ControlofGame(){
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
                if(i>2){
                    if(Arr[i][j]==peg && Arr[i-1][j]==peg && Arr[i-2][j]==empty) test=0;
                }
                if(j>2){
                    if(Arr[i][j]==peg && Arr[i][j-1]==peg && Arr[i][j-2]==empty) test=0;
                }
            }  
        }
    }
    return test;
}
bool PegSolitaire :: Compare(PegSolitaire &obj){
    bool result;
    if(NumOfPeg()> obj.NumOfPeg()) result=true;
    else result=false;
    return result;
}
void PegSolitaire :: WriteFile(ofstream& savefile){
    savefile<<"   ";
    for(int i=0; i<Arr[0].size(); i++){
        savefile<<ptr[i];
    }
    savefile<<endl;
    if(type==6){
        for(int i=0; i<5; i++){ // In type 6, I desing 9*9 vector, but I fill the last 5 rows
            savefile<<i+1<<"  ";
            for(int j=0; j<Arr[0].size(); j++){
                if(Arr[i+4][j]==0) savefile<<"0"; 
                else savefile<<Arr[i+4][j];
            }
            savefile<<endl;
        }
    }
    else{
        for(int i=0; i<Arr[0].size(); i++){ // Print table to file
            savefile<<i+1<<"  ";
            for(int j=0; j<Arr[0].size(); j++){
                if(Arr[i][j]==0) savefile<<"0";
                else savefile<<Arr[i][j];
            }
            savefile<<endl;
        }
    }
}
void PegSolitaire :: ReadFile(){
    ifstream loadfile;
        char tem;
        string str;
        int x=0,y=0;
        const int c=0;
        int count;
        cout<<"Enter the wanted board number: ";
        cin>>count;
        loadfile.open(loadfilenames[count]);
        loadfile>>tem; // a
        loadfile>>tem; // b
        loadfile>>str; //abcdefghi
        while(x!=row){
            loadfile>>tem; // number of row
            loadfile>>tem;            
            if(tem=='0') Arr[x][y]=0;
            else Arr[x][y]=tem;
            y++;
            while(y!=Arr[0].size()){
                loadfile>>tem;
                if(tem=='0') Arr[x][y]=0;
                else Arr[x][y]=tem;
                y++;
            }
            x++;
            y=0;
        }
        loadfile.close();
}
void PegSolitaire :: ComMov(int *a, int *b){
    if(type==6){
        *a=(rand()%5)+4;  //If a is odd, b must be odd
        *b=(rand()%9);
        if(*a%2==1)
            while(*b%2!=1) *b=(rand()%8);
        else
            while(*b%2!=0) *b=(rand()%8);
    }
    else{
        *a=rand()%(row); // 0-Arr.size()
        *b=rand()%(row);
    }
    int c=(rand()%4);
    if(c==0) ptt[3]='L';
    else if(c==1) ptt[3]='R';
    else if(c==2) ptt[3]='D';
    else if(c==3) ptt[3]='U';
    cout<<char(*b+65)<<(*a)+1<<ptr[3]<<endl;
}
void PegSolitaire :: play(){
    int a,b;
    while(ControlofGame()!=1){ //Until end of the game
        ComMov(&a,&b);
        Moving(a,b);
    }
    ResultofGame();
}
void PegSolitaire :: play(int a, int b){ // a is row , b is col
    Moving(a,b);
}
int PegSolitaire :: NumOfEmpt(){
    int result=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            if(Arr[i][j]==empty) result++;
        }
    }
    return result;
}
int PegSolitaire :: NumOfPeg(){
    int result=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            if(Arr[i][j]==peg) result++;
        }
    }
    return result;
}
int PegSolitaire :: NumofOutPeg(){
    return NumOfEmpt()-1; // number of peg to empty board area
}
int PegSolitaire :: TotalPeg(){
        static int total=0;  // ıt increase one by one
        total= total+NumOfPeg();
        return total;
}
int main(){
    cout<<"Welcome to Game"<<endl;
    PegSolitaire A1,A2,A3,A4,A5;
    cout<<"A1 compare to A2: "<<A1.Compare(A2)<<endl;
    cout<<"A2 compare to A3: "<<A2.Compare(A3)<<endl;
    cout<<"A3 compare to A4: "<<A3.Compare(A4)<<endl;
    cout<<"A4 compare to A5: "<<A4.Compare(A5)<<endl;
    cout<<"A5 compare to A1: "<<A5.Compare(A1)<<endl;
    cout<<"A1 #of Peg: "<<A1.NumOfPeg()<<endl<<"of Empty:"<<A1.NumOfEmpt()<<endl<<"of Out of Peg: "<<A1.NumofOutPeg()<<endl;
    cout<<"A2 #of Peg: "<<A2.NumOfPeg()<<endl<<"#of Empty:"<<A2.NumOfEmpt()<<endl<<"#of Out of Peg: "<<A2.NumofOutPeg()<<endl;
    cout<<"A3 #of Peg: "<<A3.NumOfPeg()<<endl<<"#of Empty:"<<A3.NumOfEmpt()<<endl<<"#of Out of Peg: "<<A3.NumofOutPeg()<<endl;
    cout<<"A4 #of Peg: "<<A4.NumOfPeg()<<endl<<"#of Empty:"<<A4.NumOfEmpt()<<endl<<"#of Out of Peg: "<<A4.NumofOutPeg()<<endl;
    cout<<"A5 #of Peg: "<<A5.NumOfPeg()<<endl<<"#of Empty:"<<A5.NumOfEmpt()<<endl<<"#of Out of Peg: "<<A5.NumofOutPeg()<<endl;
    cout<<"Total Peg: "<<A5.TotalPeg()<<endl;

    // Remove and rename used for arrangement, because of we save everything in savefile. 
    // But call the loadfile in start of program
    // If we dont delete loadfile rename doesnt work
    remove("load1.txt");
    rename("save1.txt","load1.txt");
    remove("load2.txt");
    rename("save2.txt","load2.txt");
    remove("load3.txt");
    rename("save3.txt","load3.txt");
    remove("load4.txt");
    rename("save4.txt","load4.txt");
    remove("load5.txt");
    rename("save5.txt","load5.txt");
    return 0;
}
