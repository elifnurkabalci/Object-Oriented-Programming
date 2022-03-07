import java.util.ArrayList;
import java.util.Arrays;
class DayofYearSet {
    public DayofYear outlist[];
    DayofYearSet(ArrayList<DayofYear> listt){
        totalobj(); // for increase the # of objects
        outlist=listt.toArray(new DayofYear[0]);
    }
    DayofYearSet(){   
    }
    void ToString(){
        System.out.print("[");
        for(int i=0; i<size(); i++){
            System.out.print(outlist[i].day + "-" + outlist[i].month + ", ");
        }
        System.out.print("]\n");
    }
    boolean equals(DayofYearSet obj){
        boolean result=false;
        int a=0;
        if(obj.size()==size()){
            for(int i=0; i<size(); i++){
                if(obj.outlist[i].day==outlist[i].day && obj.outlist[i].month==outlist[i].month) a++;
            }
            if(a==size()) result=true;
        }
        return result; 
    }
    void resize(int a){
        DayofYear[] newArr = Arrays.copyOf(outlist, outlist.length + a);
        outlist = newArr;  
        // if a ==1 it means that grow array, if a== -1 removed an element      
    }
    void add(DayofYear element){
        int temp=0,i;
        //System.out.println(outlist.length); its not a wrong in union and others but complement vs give error there
        for(i=0; i<outlist.length; i++){
            if(outlist[i].day == element.day && outlist[i].month == element.month){
                temp=1;
            }
        }
        if(temp==0){    
            resize(1);
            outlist[size()-1]=element;
        }
        else System.out.println("This element already exist");
    }
    void remove(DayofYear element){
        int temp=size(),i;
        for(i=0; i<size(); i++){
            if(outlist[i].day == element.day && outlist[i].month == element.month){
                temp=i;
            }
        }
        if(temp== size()) System.out.println("This element does not exist"); //end of array
        else{  // found it
            for(int j=temp; j<size()-1; j++){
                outlist[j].day = outlist[j+1].day;
                outlist[j].month = outlist[j+1].month;
            }
            outlist[size()-1].day=0;
            outlist[size()-1].month=0;
            resize(-1);
        }
    }
    int size(){
        return outlist.length; // return size of array
    }
    static int totalobj(){ // total object
        final int result = 0;
        return result+1;
    }
    DayofYearSet union(DayofYearSet obj1, DayofYearSet obj2){ // +
        var newobj = new DayofYearSet(); // obj1+ obj2
        int i=0;
        for(i=0; i<obj1.size(); i++){
            newobj.outlist=obj1.outlist;
        }
        for(int k=0; k<obj2.size(); k++){
            boolean temp=false;
            for(int j=0; j<obj1.size(); j++){
                if(obj1.outlist[j] == obj2.outlist[k]) temp=true;
            }
            if(temp==false){
                resize(1);
                newobj.add(obj2.outlist[k]);
            }
        }
        return newobj;
    }
    DayofYearSet difference(DayofYearSet obj1, DayofYearSet obj2){ // -
        var newobj = new DayofYearSet(); // obj1-oj2
        int i=0;
        for(i=0; i<obj1.size(); i++){
            boolean temp=false;
            for(int j=0; j<obj2.size(); j++){
                if(obj1.outlist[i] == obj2.outlist[j]) temp=true;
            }
            if(temp==false){
                resize(1);
                newobj.add(obj1.outlist[i]);
            }
        }
        return newobj;
    }
    DayofYearSet intersection(DayofYearSet obj1, DayofYearSet obj2){ // ^
        var newobj = new DayofYearSet();
        for(int i=0; i<obj1.size(); i++){
            for(int j=0; j<obj2.size(); j++){
                if(obj1.outlist[i].day == obj2.outlist[j].day && obj1.outlist[i].month == obj2.outlist[j].month){
                    resize(1);
                    newobj.add(obj1.outlist[i]); 
                }
            }
        }
        return newobj;
    }
    DayofYearSet complement(DayofYearSet obj){ // !
        var newobj = new DayofYearSet();
        int k=0;
        for(int i=1; i<=12; i++){
            if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) k=31;
            else if(i==2) k=28;
            else if(i==4 || i==6 || i==9 || i==11) k=30;
            for(int j=1; j<=k; j++){
                DayofYear element = new DayofYear();
                element.day=j; element.month=i;
                newobj.add(element);
            } // declaration all days
        }
        for(int i=0; i<size(); i++){
            for(int j=0; j<365; j++){
                if(obj.outlist[i] == newobj.outlist[j]){
                    newobj.remove(outlist[j]); // remove already existing
                }
            }
        }
        return newobj;
    }
    boolean DeMorgan(DayofYearSet obj1, DayofYearSet obj2){
        return complement(union(obj1,obj2)) == intersection(complement(obj1),complement(obj2));
    }
}
class DayofYear extends DayofYearSet{
    public int day,month;
    public DayofYear(){ // declare for local delcarations (template)
    }
    public static void main(String[] args){
        ArrayList<DayofYear> listt = new ArrayList<>(); //arraylist for d1 obj
        DayofYear element = new DayofYear();
        DayofYear element1 = new DayofYear();
        DayofYear element2 = new DayofYear();
        DayofYear element3 = new DayofYear(); // elements declarations
        element.day=15; element.month=1;
        element1.day=31; element1.month=8;
        element2.day=11; element2.month=5;
        element3.day=12; element3.month=5; // filling
        listt.add(element); // fill in listt
        listt.add(element1);
        DayofYearSet d1 = new DayofYearSet(listt); // declaration first obj
        d1.add(element);  // test add method , already exist
        d1.ToString(); // test ToString method

        d1.remove(element); // test remove method
        d1.ToString();
 
        d1.add(element3); // test add method, adding something
        d1.ToString();

        ArrayList<DayofYear> listt2 = new ArrayList<>(); // declaration second arraylist
        listt2.add(element2);
        listt2.add(element3);
        DayofYearSet d2 = new DayofYearSet(listt2); // delaration second obj

        System.out.println(d1.equals(d2)); // equality result

        d1.union(d1, d2).ToString();  // union
        //d1.difference(d1,d2); // I write all them, but they give error in same function
        //d1.DeMorgan(d1, d2);  // complemenet, union, intersection
    }
}
