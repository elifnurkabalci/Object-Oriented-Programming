#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

using namespace std;
class DayofYearSet{
public:
    class DayofYear{
    public:
        int day, month;
    };
    DayofYear *outptr=NULL;
    DayofYearSet(int i);
    DayofYearSet(vector<DayofYear> vec); // its constructor 
    void DeMorgan(DayofYearSet& Obj1, DayofYearSet& Obj2);
    void add(DayofYear& element); // add an element
    void remove(DayofYear& element); // remove an element
    int size(); // return #of element
    bool operator==(DayofYearSet& Obj); // return true if its equal
    bool operator!=(const DayofYearSet& Obj); // return true if its not equal
    friend ostream & operator<< (ostream& output ,const DayofYearSet& Obj); // print the Dayofyearset details
    friend DayofYearSet operator + (DayofYearSet& Obj1,DayofYearSet& Obj2); // return union set
    friend DayofYearSet operator - (DayofYearSet& Obj1,DayofYearSet& Obj2); // return difference set
    friend DayofYearSet operator ^ (DayofYearSet& Obj1,DayofYearSet& Obj2); // return intersection set
    void operator [] (int position); // return the element at given position
    DayofYearSet operator !(); //return a unary set
    int TotalDayofYear(); 
    //~DayofYearSet();
};
#endif //DAYOFYEAR_H