#ifndef STUDENT_H
#define STUDENT_H

///#include "Course.h"
#include<iostream>
using namespace std;

namespace P3{
class Course;

class Student{
private:
    string name;
    int ID;
public:
    Course* courseref;
    Student();
    Student(string name, int ID);
    ~Student(); 
    void setName(string n){ name = n; }
    void setID(int i){ ID = i; }
    string getName(){ return name;}
    int getID(){ return ID;}
};

class Course{ // declaration for redeclaration error
private:
    string name;
    int code;
    
public:
    Student *studentref;
    Course();
    ~Course();
    void setName(string n){ name = n; }
    void setcode(int i){ code = i; }
    Course(string name, int code);
    string getName(){ return name;}
    int getCode(){ return code;}
};

}
#endif

