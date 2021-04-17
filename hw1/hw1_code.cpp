#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int GenerateNum1(){ // generate a number 
    return rand() & 9;
}
int GenerateNum2(){
    return rand() % 6;
}
void Game(int SecretNumber){ // All game is in the this function
    int Arr[6],Est[6];
    int UserEnter,k=0;
    int Exact=0,Misplaced=0;
    bool test=false;
    for(int i=0; i<6; i++){;
        Arr[i]=SecretNumber/pow(10,6-i-1); // The target of user 
        SecretNumber = SecretNumber - Arr[i]*pow(10,5-i);
    }
    while(test==false){    // for game is start
        Exact=0,Misplaced=0;
        cin>>UserEnter; // enter the variable
        k++; // #of iterations
        for(int i=0; i<6; i++){
            Est[i]=UserEnter/pow(10,6-i-1);  // for using user entered number
            UserEnter = UserEnter - Est[i]*pow(10,5-i);
        }
        for(int i=0; i<6; i++){   // count the first and second variables
            if(Arr[i]==Est[i]) Exact++;
            else{
                for(int j=0; j<6; j++){
                    if(Arr[j]==Est[i]) Misplaced++;
                }
            }
        }
        if(Exact==6){
            cout<<"FOUND "<<k<<endl;   //User found the number in k iterations, program exits.
            test=true;
        }
        else{  // 
            cout<<Exact<<" "<<Misplaced<<endl;
        }
        if(k==100){   // If user cannot find in 100 iterations
            test=true;
            cout<<"FAILED"<<endl;
        }
    
    }

}
void Control(int Arr[6], int i){  // Control for the same elements in random array
    for(int j=0; j<i; j++){
        while(Arr[i]==Arr[j]){
            Arr[i]=GenerateNum1();
        }
    }
}
void r(string a){ // computer generate random number with -r
    int Arr[6];
    int N=stoi(a);
    if(N<=0){
        cout<<"E0"<<endl;  //Negative value or 0 value following the -r option.
    }
    else if(N<6 || N>6){  // if entered number more or less than 6
        cout<<"E1"<<endl;
    }
    else{ // Everything is ok
        int sum=0;
        srand(static_cast<int>(time(NULL)));
        for(int i=0; i<6; i++){    // The general for loop
            Arr[i]=GenerateNum2();
            while(Arr[0]==0){
                Arr[0]=GenerateNum2(); // every step
            }
            Control(Arr,i);
            sum+=Arr[i]*pow(10,N-i-1); // create the secret number
        }
        for(int m=0; m<6; m++){   // If Array elements are the same 
            for(int n=0; n<6; n++){
                if(Arr[m]==Arr[n]){
                    Control(Arr,6);  // The last control
                }
            }
        }
        Game(sum); // Everything is done
    }
}
void u(string a){  // User choose the secret number with -u
    int Arr[6];
    bool test = true;
    int SecretNum = stoi(a);
    for(int i=0; i<6; i++){  // take to array from integer number
        Arr[i]=SecretNum/pow(10,6-i-1);
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(i!=j){
                if(Arr[i]==Arr[j]){
                    test=false;  // test the function
                    cout<<"E0"<<endl; //Digits of the number followed by -u are not unique.
                }
            }
        }
    }
    if(test==true) Game(SecretNum);
}
int main(int argc, char* argv[]){   // Taking the console variables with arguments 
    if(argv[1][0]=='-' && argv[1][1]=='r'){  // for r
        if((int)argv[2][0]>60)
            cout<<"E2"<<endl;
        else{
            r(argv[2]);
        }
    }
    else if(argv[1][0]=='-' && argv[1][1]=='u') u(argv[2]); // for u
    else{
        cout<<"E0"<<endl; // for incorrect variables
    }
    return 0;
}