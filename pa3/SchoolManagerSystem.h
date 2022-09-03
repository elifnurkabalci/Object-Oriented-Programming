#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include<iostream>
#include"Student.h"
//#include"Course.h"
using namespace std;

namespace P3{
class SchoolManagerSystem{
private:
    Student *stdref;
    Course *crsref;

public:
    void add_student();
    void add_course();
    void delete_student(string s, int i);
    void delete_course(string s, int code);
    void select_student();
    void select_course();
    void list_student_selected_course(string s, int code);
    SchoolManagerSystem();
    //members related with menu functionality
    void menu1();
    void student_menu2();
    void course_menu2();
    void list_all_students();
    void list_all_courses();
    void add_selected_student(string s, int i);
    void drop_selected_student(string s,int i);
};


}

#endif
