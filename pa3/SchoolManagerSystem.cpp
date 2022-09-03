#include<iostream>
#include"SchoolManagerSystem.h"

using namespace std;

namespace P3{

    SchoolManagerSystem :: SchoolManagerSystem(){
        cout<<"Main_menu"<<endl;
        menu1();
    }
    void SchoolManagerSystem :: menu1(){
        int a;
        cout<<"0 exit"<<endl<<"1 student"<<endl<<"2 course"<<endl<<"3 list_all_students"<<endl<<"4 list_all_courses"<<endl;
        cin>>a;
        switch (a){
        case 0:{
            exit(1);
        }break;
        case 1:{
            student_menu2();
            menu1();
        }break;
        case 2:{
            course_menu2();
            menu1();
        }break;
        case 3:{
            list_all_students();
            menu1();
        }break;
        case 4:{
            list_all_courses();
            menu1();
        }break;
        default:{
            menu1();
        }break;
        }
    }
    void SchoolManagerSystem :: add_student(){
        string s;
        int id;
        cout<<"Enter the name of student: ";
        cin>>s;
        cout<<"Enter the ID of student: ";
        cin>>id;
        this->stdref = new Student(s,id); // add new data to student referance
    }
    void SchoolManagerSystem :: add_course(){
        string s;
        int code;
        cout<<"Enter the name of course: ";
        cin>>s;
        cout<<"Enter the code of course: ";
        cin>>code;
        this->crsref = new Course(s,code); // add new data to course reference
        
    }
    void SchoolManagerSystem :: delete_student(string s, int i){
        int test=-1;
        while(stdref!=NULL){ // find the student
            if(stdref[i].getName()==s && stdref[i].getID()==i){
                test=i;
            }
            i++;
        }
        if(test != -1){ // if student does not exist
            for(int k=test; k<sizeof(stdref)-1; k++){
                stdref[k]=stdref[k+1]; // swapping
            }
            stdref[sizeof(stdref)-1].setName(" ");
            stdref[sizeof(stdref)-1].setID(0); // for become null
        }
    }
    void SchoolManagerSystem :: delete_course(string s, int code){
        int test =-1;
        for(int i=0; i<sizeof(crsref); i++){
            if(crsref[i].getName()==s && crsref[i].getCode()==code){
                test=i;
            } // if course is exist
        }
        if(test != -1){
            for(int k=test; k<sizeof(crsref)-1; k++){
                crsref[k]=crsref[k+1]; // swapping
            }
            crsref[sizeof(stdref)-1].setName(" ");
            crsref[sizeof(stdref)-1].setcode(0);
        }
    }
    void SchoolManagerSystem :: add_selected_student(string s, int i){
        int t = -1;
        for(int i=0; i<sizeof(stdref); i++){
            if(stdref[i].getName()==s && stdref[i].getID()==i){
                t=i; // find the student location
            }
        }
        string *tempname;
        int *tempcode; // for arrange printing data's
        if(t!=-1){
            int test;
            cout<<"0 up"<<endl;
            for(int i=0; i<sizeof(crsref); i++){
                test=-1;
                for(int j=0; j<sizeof(stdref[t].courseref); j++){
                    if(crsref[t].getName()==stdref[t].courseref[j].getName() &&
                        crsref[t].getCode()==stdref[t].courseref[j].getCode()) test =0;
                }
                if(test==-1){
                    cout<<i+1<<" "<<crsref[t].getCode()<<" "<<crsref[t].getName()<<endl;
                    tempcode[i]=crsref[t].getCode();
                    tempname[i]=crsref[t].getName();
                } // for printing and find the course that does not exist in student course's 
            }
            int a,tem;
            cin>>a;
            if(a==0) select_course();
            else if(a<=sizeof(crsref)){

                stdref[t].courseref[sizeof(stdref[t].courseref)].setcode(tempcode[a-1]);
                stdref[t].courseref[sizeof(stdref[t].courseref)].setName(tempname[a-1]);
                for(int i=0; i<sizeof(crsref); i++){
                    if(crsref[i].getName()==tempname[a-1] && crsref[i].getCode()==tempcode[a-1]){
                        tem=i; // find the this course
                    }
                }
                crsref[tem].studentref[sizeof(crsref[tem].studentref)+1]=stdref[t];

            }
        }
    }
    void SchoolManagerSystem :: drop_selected_student(string s,int i){
        int t = -1;
        for(int i=0; i<sizeof(stdref); i++){
            if(stdref[i].getName()==s && stdref[i].getID()==i){
                t=i; // find the student location
            }
        }
        if(t!=-1){
            cout<<"0 up"<<endl;
            int i;
            for(i=0; i<sizeof(stdref[t].courseref); i++){
                cout<<i+1<<" "<<stdref[t].courseref[i].getCode()<<" "<<stdref[t].courseref[i].getName()<<endl;
            }
            int a;
            cin>>a;
            if(a==0) select_student();
            else if(a<=sizeof(stdref[t].courseref)){
                for(int i=0; i<sizeof(crsref); i++){
                    if(crsref[i].getCode() == stdref[t].courseref[a-1].getCode() && 
                        crsref[i].getName() == stdref[t].courseref[a-1].getName()){
                            crsref[i].setcode(0);
                            crsref[i].setName(" ");
                        }
                }
                stdref[t].courseref[a-1].setcode(0);
                stdref[t].courseref[a-1].setName(" ");
            }
            
        }
    }   
    void SchoolManagerSystem :: list_student_selected_course(string s, int code){
        int test=-1;
        for(int i=0; i<sizeof(crsref); i++){
            if(s==crsref[i].getName() && code==crsref[i].getCode()){
                test=i;
            }
        }
        if(test!=-1){
            for(int j=0; j<sizeof(crsref[test].studentref); j++){
                cout<<crsref[test].studentref[j].getName()<<endl;
            }
        }
    }
    void SchoolManagerSystem :: select_student(){
        string s;
        int id,a;
        cout<<"Enter the name of student: ";
        cin>>s;
        cout<<"Enter the ID of student: ";
        cin>>id;
        cout<<"0 up"<<endl<<"1 delete_student"<<endl<<"2 add_selected_student_to_a_course"<<endl<<"3 drop_selected_student_from_a_course"<<endl;
        cin>>a;
        switch (a)
        {
        case 0:{
            student_menu2();
        }break;
        case 1:{    
            delete_student(s,id);
            student_menu2();
        }break;
        case 2:{
            add_selected_student(s,id);
            student_menu2();
        }break;
        case 3:{
            drop_selected_student(s,id);
            student_menu2();   
        }break;
        default:{
            select_student();
        }break;
        }
    }
    void SchoolManagerSystem :: select_course(){
        string s;
        int code,a;
        cout<<"Enter the name of course: ";
        cin>>s;
        cout<<"Enter the code of course: ";
        cin>>code;
        cout<<"0 up"<<endl<<"1 delete_course"<<endl<<"list_students_registered_to_the_selected_course"<<endl;
        cin>>a;
        switch (a)
        {
        case 0:{
            course_menu2();
        }break;
        case 1:{
            delete_course(s, code);
            course_menu2();
        }break;
        case 2:{
            list_student_selected_course(s,code);
            course_menu2();
        }break;
        default:{
            select_course();
        }break;
        }
    }
    void SchoolManagerSystem :: list_all_students(){
        for(int i=0; i<sizeof(stdref); i++){
            cout<<stdref[i].getName()<<"\t"<<stdref->getID()<<endl;
        }
    }
    void SchoolManagerSystem :: list_all_courses(){
        for(int i=0; i<sizeof(crsref); i++){
            cout<<crsref[i].getName()<<"\t"<<crsref->getCode()<<endl;
        }
    }
    void SchoolManagerSystem :: student_menu2(){
        int a;
        cout<<endl<<"0 up"<<endl<<"1 add_student"<<endl<<"2 select_student"<<endl;
        cin>>a;
        switch (a){
        case 0:{
            menu1();
        }break;
        case 1:{
            add_student();
            student_menu2();
        }break;
        case 2:{
            select_student();
            student_menu2();
        }break;
        default:{
            student_menu2();
        }break;
        }
    }
    void SchoolManagerSystem :: course_menu2(){
        int a;
        cout<<"0 up"<<endl<<"1 add_course"<<endl<<"2 select_course"<<endl;
        cin>>a;
        switch (a){
        case 0:{
            menu1();
        }break;
        case 1:{
            add_course();
            course_menu2();
        }break;
        case 2:{
            select_course();
            course_menu2();
        }break;
        default:{
            course_menu2();
        }break;
        }
    }
}