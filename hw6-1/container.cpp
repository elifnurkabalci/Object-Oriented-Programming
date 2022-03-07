#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<algorithm>
#include<set>
#include"container.h"
using namespace std;

template <class T>
bool Iterable<T> :: isEmpty(){
    bool result=false;
    if(size()==0) result=true;
    return result;
}
template <class T>
int Iterable<T> :: size(){
    int size=0;
    typename vector<Iterable<T>*>::iterator iter;
    for(iter=this->ptr.begin(); iter != this->ptr.end(); iter++){
        size++;
    }
    return size;
}
template <class T>
void Iterable<T> :: erase(T element){
    typename vector<Iterable<T>*>::iterator iter;
    for(iter=this->ptr.begin(); iter != this->ptr.end(); iter++){
        if(iter == element){
            iter=0;
        }
    }
}
template <class T>
void Iterable<T> :: clear(){
    typename vector<Iterable<T>*>::iterator iter;
    for(iter=this->ptr.begin(); iter != this->ptr.end(); iter++){
        iter=0;
    }
}
template <class T>
T* Iterable<T> :: begin(){
    return this->ptr.begin();
}
template <class T>
T* Iterable<T> ::  end(){
    return this->ptr.end();
}
template <class T>
T* Iterable<T> :: cbegin() const{
    return this->ptr.begin();
}
template <class T>
T* Iterable<T> :: cend() const{
    return this->ptr.end();
}
/********************************************/
template <class T>
GTUVector<T> :: GTUVector(){
    this->ptr=std::move(this->vec);
} 
template <class T>
void GTUVector<T> :: add(T element){
    this->ptr.push_back(element);
}
template <class T>
T GTUVector<T> :: operator[](int position){
    typename vector<Iterable<T>*>::iterator iter;
    for(iter=this->ptr.begin(); iter != this->ptr[position]; iter++){
    }
    return iter;
}
/***********************************/
template<class T>
GTUSet<T> :: GTUSet(){
    this->ptr=std::move(this->set);
}
template <class T>
T GTUSet<T> :: search(T element){
    return this->ptr.find(element);
}
template <class T>
void GTUSet<T> :: add(T element){
    this->ptr.insert(element);
}
template <class T>
void GTUSet<T> :: deletee(T element){
    this->erase(element);
}
template <class T>
T GTUSet<T> :: intersect(T&& set1){
    std::sort(this->ptr.begin(), this->ptr.end());
    std::sort(set1.begin(), set1.end());
    T&& intset;
    std::set_intersection(this->ptr.begin(),this->ptr.end(), set1.begin(), set1.end(), std::back_inserter(intset));
    return intset;
}
template <class T>
T GTUSet<T> :: unionn(T&& set1){
    T&& unionset;
    std::set_union(this->ptr.begin(), this->ptr.end(), set1.begin(), set1.end(), std::back_inserter(unionset));
    return unionset;
}
/********************************/
template <class T,int SIZE>
GTUArray<T,SIZE> :: GTUArray(){
    for(int i=0; i<SIZE; i++){
        this->arr.push_back(0);
    }
    this->ptr=std::move(this->arr);
}
