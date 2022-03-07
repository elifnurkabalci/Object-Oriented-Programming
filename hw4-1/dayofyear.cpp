#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"dayofyear.h"
using namespace std;
DayofYearSet :: DayofYearSet(int i){
    outptr = new DayofYear[i];
}
DayofYearSet :: DayofYearSet(vector<DayofYear> vec){  
    int m=0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i].day>31 && vec[i].month>12 && vec[i].day<0 && vec[i].month<0){
            vec[i].day=0;
            vec[i].month=0;
        }
        else{
            vec[m]=vec[i];
            m++;
        }
    }
    vec.resize(m);
    outptr = new DayofYear[vec.size()];
    for(int i=0; i<vec.size(); i++){
        outptr[i]=vec[i];
    }
    
}
void DayofYearSet :: add(DayofYear& element){
    int temp=0,i=0;
    while(outptr[i].day!=0 && outptr[i].month!=0){
        if(element.day==outptr[i].day && element.month==outptr[i].month){ 
            cout<<"This element is already exist"<<endl;
            temp=1;
        }
        i++;
    }
    if(temp==0){
        outptr[size()]=element;
    }
}
void DayofYearSet :: remove(DayofYear& element){
    int temp=0,i=0;
    while(outptr[i].day>0 && outptr[i].month>0){
        if(element.day==outptr[i].day && element.month==outptr[i].month){
            temp=i;
        } // we find the location
        i++;
    }
    for(int j=temp; j<size()-1; j++){
        outptr[j]=outptr[j+1];
    }
    outptr[size()].day=0;
    outptr[size()].month=0;
    

}
int DayofYearSet :: size(){
    int i=0;
    while(outptr[i].day>0 && outptr[i].month>0){
        i++;
    }
    return i;
}
bool DayofYearSet :: operator==(DayofYearSet& Obj){
    bool temp=false;
    int a=0;
    if(Obj.size()==size()){
        for(int i=0; i<size(); i++){
            if(Obj.outptr[i].day==outptr[i].day && Obj.outptr[i].month==outptr[i].month) a++;
        }
        if(a==size()) temp=true;
    }
    return temp;
}
bool DayofYearSet :: operator!=(const DayofYearSet& Obj){
    return !(outptr==Obj.outptr);
}
DayofYearSet operator + (DayofYearSet& Obj1,DayofYearSet& Obj2){
    DayofYearSet newptr(Obj1.size()+Obj2.size());
    auto i=0;
    for(i=0; i<Obj1.size(); i++){
        newptr.outptr[i]=Obj1.outptr[i];
    }
    decltype(i) temp;
    for(int k=0; k<Obj2.size(); k++){
        temp=0;
        for(int j=0; j<Obj1.size(); j++){
            if(Obj1.outptr[j].day==Obj2.outptr[k].day && Obj1.outptr[j].month==Obj2.outptr[k].month){
                temp=1;
            }
        }
        if(temp==0){ 
            newptr.outptr[i].day=Obj2.outptr[k].day;  // it may be i instead of i+1
            newptr.outptr[i].month=Obj2.outptr[k].month;  // it may be i instead of i+1
            i++;
        }
    }

    return newptr;
}
DayofYearSet operator - (DayofYearSet& Obj1,DayofYearSet& Obj2){
    DayofYearSet newptr(Obj1.size());
    int temp,m=0;
    for(int i=0; i<Obj1.size(); i++){
        temp=0;
        for(int j=0; j<Obj2.size(); j++){
            if(Obj1.outptr[i].day==Obj2.outptr[j].day && Obj1.outptr[i].month==Obj2.outptr[j].month) temp=1;
        }
        if(temp=0){
            newptr.outptr[m].day=Obj1.outptr[i].day;
            newptr.outptr[m].month=Obj1.outptr[i].month;
            m++;
        }
    }

    return newptr;
}
DayofYearSet operator ^ (DayofYearSet& Obj1,DayofYearSet& Obj2){
    DayofYearSet newptr(Obj1.size()+Obj2.size());
    int temp,m=0,k=0;
    for(int i=0; i<Obj1.size(); i++){
        temp=0;
        for(int j=0; j<Obj2.size(); j++){
            if(Obj1.outptr[i].day==Obj2.outptr[j].day && Obj1.outptr[i].month==Obj2.outptr[j].month){ 
                newptr.outptr[m].day=Obj1.outptr[k].day;
                newptr.outptr[m].month=Obj1.outptr[k].month;
                m++;
            }
        }
    }
    return newptr;
}
void DayofYearSet :: operator [] (int position){
    string str;
    switch (outptr[position].month)
    {
    case 1:{str="January"; }break;
    case 2:{str="February"; }break;
    case 3:{str="March"; }break;
    case 4:{str="April"; }break;
    case 5:{str="May"; }break;
    case 6:{str="June"; }break;
    case 7:{str="July"; }break;
    case 8:{str="August"; }break;
    case 9:{str="September"; }break;
    case 10:{str="October"; }break;
    case 11:{str="November"; }break;
    case 12:{str="December"; }break;
    default:{ cerr<<"Does not exist this month"<<endl; }break;
    }
    cout<<"month: "<<outptr[position].month<<endl;
    cout<<"day: "<<outptr[position].day<<endl;
}
DayofYearSet DayofYearSet :: operator! (){
    vector<DayofYear> vec(365);
    int k,m=0;
    for(int i=0; i<12; i++){
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) k=31;
        else if(i==2) k=28;
        else if(i==4 || i==6 || i==9 || i==11) k=30;
        for(int j=0; j<k; j++){
            vec[m].day=j;
            vec[m].month=i;
            m++;
        }
    }// I defined all year days
    // fill the vector
    for(int i=0; i<size(); i++){
        for(int j=0; j<365; j++){
            if(outptr[i].day==vec[j].day && outptr[i].month==vec[j].month){
                vec[j].day=0;
                vec[j].month=0;
            }
        }
    }
    return (DayofYearSet)0;
}   
ostream& operator<< (ostream& output, const DayofYearSet& Obj){
    int i=0;
    while(Obj.outptr[i].day>0 && Obj.outptr[i].month>0 ){
        output<<i<<": "<<Obj.outptr[i].day<<" "<<Obj.outptr[i].month<<endl;
        i++;
    }
    return output;
}
void DayofYearSet :: DeMorgan(DayofYearSet& Obj1, DayofYearSet& Obj2){
    /*if(!(Obj1 + Obj2) == (!Obj1 ^ !Obj2)){
        cout<<"De Morgan Test is Successful. "<<endl;
    }
    else{
        cout<<"De Morgan Test is Unsuccessful."<<endl;
    }*/
}
int DayofYearSet :: TotalDayofYear(){
    static int tot=0;
    tot++;
    return tot;
}