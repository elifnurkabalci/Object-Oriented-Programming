#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Logic{  // base class
public:
    int former_out=0;
    int *Dec;   // its for the decoder, store the output  
    int AND(int a, int b);
    int OR(int a, int b);
    int NOT(int a);
    int FLIPFLOP(int a);
    void DECODER(int a, int b);
};

class Circuit : public Logic{ // derived class
public:
    void SetInput(string **Arr); 
    void SetCircuit(string **Arr,string **OutputArr);
    
};
void Circuit :: SetInput(string **Arr){ // read from input file, store in the array
    ifstream file2;
    file2.open("input.txt");
    char a;
    int i=0,j=0;  // i is row, j is column
    while(i!=3){
        Arr[i]= new string[4]; // create 4 col for every row
        while(j!=4){ // input
            file2>>a;
            Arr[i][j]=a; 
            j++;
        }
        i++; 
        j=0;
    }
    /*
    Arr
    1 1 0 1 
    1 0 1 0
    1 1 1 0
    */
    file2.close();
}
/*
OutputArr:
a    _     in this program, filling the between the values, and we use correcty 
b    _
c
d
d1
d2
d3
d4
and1
or1
n1
f1
a2
*/
void Circuit :: SetCircuit(string **Arr,string **OutputArr){
    ifstream file1;
    string a,b,c;
    int i=0,k=0,m,n;
    while(k!=3){ // k is the number of row in the Arr
        file1.open("circuit.txt");
        while(!file1.eof()){
            file1>>a; // INPUT, OUTPUT...
            if(a=="INPUT"){
                file1>>a;  //a
                while(i!=3){
                    OutputArr[i] = new string[2];
                    OutputArr[i][0]=a;
                    OutputArr[i][1]=Arr[k][i]; // a=1....  this took value of a,b,c,d...
                    file1>>a; //b,c,d
                    i++;
                    
                }
            }
            else if(a=="OUTPUT"){
                int c = i;  
                while((i-c)!=4){
                    OutputArr[i] = new string[2];
                    file1>>a;
                    OutputArr[i][0]=a;
                    OutputArr[i][1]=to_string(0);  // fill with empty for the arrangement
                    i++;
                }
            }
            else if(a=="AND"){
                OutputArr[i] = new string[2];
                file1>>a; // result , and1
                OutputArr[i][0]=a;
                file1>>a;  //a
                file1>>b;  //b
                for(int x=0; x<sizeof(*OutputArr); x++){
                    if(OutputArr[x][0]==a){
                        m=stoi(OutputArr[x][1]); // find the value of a in the OutputArr
                    }
                    if(OutputArr[x][0]==b){
                        n=stoi(OutputArr[x][1]);
                    }
                }
                OutputArr[i][1]=to_string(AND(m,n)); // calculate
                i++;
            }
            else if(a=="OR"){
                OutputArr[i] = new string[2];
                file1>>a;  //result, or1
                OutputArr[i][0]=a;
                file1>>a;   //and1
                file1>>b;    //c
                for(int x=0; x<sizeof(*OutputArr); x++){
                    if(OutputArr[x][0]==a){
                        m=stoi(OutputArr[x][1]);
                    }
                    if(OutputArr[x][0]==b){
                        n=stoi(OutputArr[x][1]);
                    }
                }
                OutputArr[i][1]=to_string(OR(m,n)); //calculate
                i++;
            }
            else if(a=="NOT"){
                OutputArr[i] = new string[2];
                file1>>a; // result, n1
                OutputArr[i][0]=a;
                file1>>a;  
                for(int x=0; x<sizeof(*OutputArr); x++){
                    if(OutputArr[x][0]==a){
                        m=stoi(OutputArr[x][1]);
                    }
                }
                OutputArr[i][1]=to_string(NOT(m)); //calculate
                i++;
            }
            else if(a=="FLIPFLOP"){
                OutputArr[i] = new string[2];
                file1>>a; // result, f1
                OutputArr[i][0]=a;
                file1>>a;  
                for(int x=0; x<sizeof(*OutputArr); x++){
                    if(OutputArr[x][0]==a){
                        m=stoi(OutputArr[x][1]);
                    }
                }
                OutputArr[i][1]=to_string(FLIPFLOP(m)); // calculate
                i++;
            }
            else if(a=="DECODER"){
                OutputArr[i] = new string[2];
                for(int b=0; b<5; b++){  // d1,d2,d3,d4
                    file1>>a; //results  
                }
                //last a is a2
                file1>>b; //f1
                for(int x=0; x<13; x++){
                    if(OutputArr[x][0]==a){
                        m=stoi(OutputArr[x][1]);
                    }
                    if(OutputArr[x][0]==b){
                        n=stoi(OutputArr[x][1]);
                    }
                }
                DECODER(m,n);
            }
        }
        k++;
        file1.close();
        i=0;
        for(int x=0; x<4; x++){ // print the screen
            cout<<Dec[x];
            cout<<" ";
        }
        cout<<endl;
    }
}
int Logic :: AND(int a, int b){ //truth table of AND
    int result=0;
    if(a==0 && b==0){
        result = 0;
    }
    else if(a==0 && b==1){
        result = 0;
    }
    else if(a==1 && b==0){
        result = 0;
    }
    else if(a==1 && b==1){
        result = 1;
    }
    return result;
} 
int Logic :: OR(int a, int b){ // truth table of OR
    int result=0;
    if(a==0 && b==0){
        result = 0;
    }
    else if(a==0 && b==1){
        result = 1;
    }
    else if(a==1 && b==0){
        result = 1;
    }
    else if(a==1 && b==1){
        result = 1;
    }
    return result;
} 
int Logic :: NOT(int a){ // truth table of NOT
    int result=0;
    if(a==0){
        result=1;
    }
    else if(a==1){
        result=0;
    }
    return result;
}
int Logic :: FLIPFLOP(int a){ //truth table of FLIPFLOP
    int result=0;
    if(former_out==0) former_out=1;
    else if(former_out==1) former_out=0;
    if(a==0 && former_out==0){
        result = 0;
    }
    else if(a==0 && former_out==1){
        result = 1;
    }
    else if(a==1 && former_out==0){
        result = 1;
    }
    else if(a==1 && former_out==1){
        result = 0;
    }
    this->former_out=result;
    return result;
}
void Logic :: DECODER(int a, int b){ // truth table of DECODER
    Dec = new int [4];
    for(int i=0; i<4; i++){
        Dec[i]=0;
    }
    if(a==0 && b==0){
        Dec[0] = 1;
    }
    else if(a==0 && b==1){
        Dec[1] = 1;
    }
    else if(a==1 && b==0){
        Dec[2] = 1;
    }
    else if(a==1 && b==1){
        Dec[3] = 1;
    }

}
int main(){
    Circuit item;    
    string **Arr= new string*[5];
    string **OutputArr= new string*[15];

    item.SetInput(Arr);
    item.SetCircuit(Arr,OutputArr);
    return 0;
}