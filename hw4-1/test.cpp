#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"dayofyear.h"

using namespace std;

int main(){
    vector<DayofYearSet :: DayofYear> vec1,vec2;
    DayofYearSet:: DayofYear element,element1,element2, element3, element4, element5;
    element.day=15; element.month=1;
    element1.day=31; element1.month=8;
    element2.day=11; element2.month=5;
    element3.day=12; element3.month=5;
    element4.day=18; element4.month=4;
    element5.day=26; element5.month=3;
    vec1.push_back(element);
    vec1.push_back(element2);
    vec1.push_back(element4);
    vec2.push_back(element1);
    vec2.push_back(element3);
    vec2.push_back(element5);
    DayofYearSet Obj1(vec1), Obj2(vec2);
    Obj1.add(element); // it must say already exist
    Obj1.add(element1); // it must add
    Obj1.remove(element); // this is exist so it must delete
    cout<<"Sizeof Obj1: "<<Obj1.size()<<endl;

    //Obj2.add(element);
    //Obj2.add(element3); // already exist
    cout<<"Sizeof Obj2: "<<Obj2.size()<<endl; 

    cout<<"Obj1: "<<endl<<Obj1<<endl;
    cout<<"Obj2: "<<endl<<Obj2<<endl;
    cout<<"Obj1+Obj2: "<<endl<<(Obj1+Obj2)<<endl;
    cout<<"Obj1-Obj2: "<<endl<<(Obj1-Obj2)<<endl;
    cout<<"Obj1^Obj2: "<<endl<<(Obj1^Obj2)<<endl;
    
    cout<<"Obj1[2]: "<<endl;
    Obj1[2];
    cout<<endl;
    cout<<"Obj1==Obj2: "<<(Obj1==Obj2)<<endl;
    cout<<"Obj1!=Obj2: "<<(Obj1!=Obj2)<<endl;

    Obj1.DeMorgan(Obj1, Obj2);

    Obj1.TotalDayofYear();
    Obj2.TotalDayofYear();
    return 0;
}