#ifndef CONTAINER_H
#define CONTAINER_H
using namespace std;

template <class T>
class Iterable{
public:
    shared_ptr(T* ptr);
    Iterable();
    bool isEmpty();
    int size();
    void erase(T element);
    void clear();
    T* begin();
    T* end();
    T* cbegin() const;
    T* cend() const;
    for_each();
};

template <class T>
class GTUVector : public Iterable<T>{
public:    
    shared_ptr(T&& vec);
    GTUVector();
    move();
    void add(T element);
    T operator[](int position);
};

template <class T>
class GTUSet : public Iterable<T>{
public:    
    shared_ptr(T&& set);
    GTUSet();
    move();
    T search(T element);
    void add(T element);
    void deletee(T element);
    T intersect(T&& set1);
    T unionn(T&& set1);    
};

template <class T, int SIZE>
class GTUArray : public Iterable<T>{
public:
    shared_ptr(T& arr);
    move();
    GTUArray();
};
template<class T>
class GTUIterator : public Iterable<T>{
public:

};
template<class T>
class GTUIteratorConst : public Iterable<T>{

};

#endif //CONTAINER_H
