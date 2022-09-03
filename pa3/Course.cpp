#include<iostream>
#include"Course.h"

using namespace std;

namespace P3{
    Course :: Course(){
        studentref = NULL;
    }
    Course :: ~Course(){
        if(studentref != NULL)
            delete[] studentref; // for empty allocation
    }
    Course :: Course(string name, int code){
        this->name = name; // declaration with user
        this->code = code;
    }
}