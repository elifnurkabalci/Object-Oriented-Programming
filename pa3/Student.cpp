#include<iostream>
#include"Student.h"

using namespace std;

namespace P3{
    Student ::Student(){
        courseref = NULL; // for inital condition
    }
    Student :: Student(string name, int ID){
        this->name = name; // this means in student class member function name
        this->ID=ID;
    }
    Student :: ~Student(){
        if(courseref!=NULL) // empty the memory allocation
            delete[] courseref;
    }

}