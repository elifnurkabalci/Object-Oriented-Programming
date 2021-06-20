#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // sort
using namespace std;

template <class T>
class Catalogs{
public:
    vector <T> Title;
    vector <T> Year;
    vector <T> Person; // director, artist, authors
    vector <T> Genre; // genre, tags
    void ReadFromFile(ifstream & file, ofstream & output);
    void CommandFile(ofstream & output);
    void Search(string d, string c, ofstream & output);
    void Sort(string c, ofstream & output);
};
//*****************************************************************
template <class T>
class Movie{
public:
    vector <T> Starring;
    vector <T> Title;
    vector <T> Year;
    vector <T> Person; // director, artist, authors
    vector <T> Genre; // genre, tags
    void ReadFromFile(ifstream & file, ofstream & output);
    void CommandFile(ofstream & output);
    void Search(string d, string c, ofstream & output);
    void Sort(string c, ofstream & output);
};
//****************************************************************
template<class T>
void Catalogs<T> :: Search(string d, string c, ofstream & output){
    //d = monkeys
    //c = title
    try{
    if(c.compare("title")==0){
        for(int i=0; i<Title.size(); i++){
            if(Title[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<endl;
            }
        }
    }
    else if(c.compare("authors")==0 || c.compare("artists")==0){
        for(int i=0; i<Person.size(); i++){
            if(Person[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<endl;
            }
        }
    }
    else if(c.compare("year")==0){
        for(int i=0; i<Year.size(); i++){
            if(Year[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<endl;
            }
        }
    }
    else if(c.compare("tags")==0 || c.compare("genre")==0){
        for(int i=0; i<Genre.size(); i++){
            if(Genre[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<endl;
            }
        }
    }
    else{
        throw(c);
    }
    }
    catch(string& c){
        output<<"Command is wrong"<<endl;
    } 
}
template<class T>
void Movie<T> :: Search(string d, string c, ofstream & output){
    //d = monkeys
    //c = title
    try{
    if(c.compare("title")==0){
        for(int i=0; i<Title.size(); i++){
            if(Title[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<Starring[i]<<endl;
            }
        }
    }
    else if(c.compare("director")==0){
        for(int i=0; i<Person.size(); i++){
            if(Person[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<Starring[i]<<endl;
            }
        }
    }
    else if(c.compare("year")==0){
        for(int i=0; i<Year.size(); i++){
            if(Year[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<Starring[i]<<endl;
            }
        }
    }
    else if(c.compare("genre")==0){
        for(int i=0; i<Genre.size(); i++){
            if(Genre[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<Starring[i]<<endl;
            }
        }
    }
    else if(c.compare("starring")==0){
        for(int i=0; i<Starring.size(); i++){
            if(Starring[i].find(d) != std::string::npos){
                output<<Title[i]<<" "<<Person[i]<<" "<<Year[i]<<" "<<Genre[i]<<" "<<Starring[i]<<endl;
            }
        }
    }
    else{
        throw(c);
    }
    }
    catch(string& c){
        output<<"Exception: Command is wrong"<<endl;
    }
}
template<class T>
void Catalogs<T> :: Sort(string c, ofstream & output){
    // c -> year
    vector<T> arr;
    try{
    if(c.compare("title")==0){
        for(int i=0; i<Title.size(); i++){
            arr.push_back(Title[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Title.size(); i++){
            for(int j=0; j<Title.size(); j++){
                if(arr[i].compare(Title[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<endl;
                }

            }
        }
    }
    else if(c.compare("authors")==0 || c.compare("artists")==0){
        for(int i=0; i<Person.size(); i++){
            arr.push_back(Person[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Person.size(); i++){
            for(int j=0; j<Person.size(); j++){
                if(arr[i].compare(Person[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<endl;
                }

            }
        }
    }
    else if(c.compare("year")==0){
        for(int i=0; i<Year.size(); i++){
            arr.push_back(Year[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Year.size(); i++){
            for(int j=0; j<Year.size(); j++){
                if(arr[i].compare(Year[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<endl;
                }

            }
        }
    }
    else if(c.compare("tags")==0 || c.compare("genre")==0){
        for(int i=0; i<Genre.size(); i++){
            arr.push_back(Genre[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Genre.size(); i++){
            for(int j=0; j<Genre.size(); j++){
                if(arr[i].compare(Genre[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<endl;
                }
            }
        }
    }
    else{
        throw(c);
    }
    }
    catch(string& c){
        output<<"Exception: Command is wrong"<<endl;
    } 
}
template<class T>
void Movie<T> :: Sort(string c,ofstream& output){
    // c -> year
    vector<T> arr;
    try{
    if(c.compare("title")==0){
        for(int i=0; i<Title.size(); i++){
            arr.push_back(Title[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Title.size(); i++){
            for(int j=0; j<Title.size(); j++){
                if(arr[i].compare(Title[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<" "<<Starring[j]<<endl;
                }

            }
        }
    }
    else if(c.compare("director")==0){
        for(int i=0; i<Person.size(); i++){
            arr.push_back(Person[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Person.size(); i++){
            for(int j=0; j<Person.size(); j++){
                if(arr[i].compare(Person[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<" "<<Starring[j]<<endl;
                }

            }
        }
    }
    else if(c.compare("year")==0){
        for(int i=0; i<Year.size(); i++){
            arr.push_back(Year[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Year.size(); i++){
            for(int j=0; j<Year.size(); j++){
                if(arr[i].compare(Year[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<" "<<Starring[j]<<endl;
                }

            }
        }
    }
    else if(c.compare("genre")==0){
        for(int i=0; i<Genre.size(); i++){
            arr.push_back(Genre[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Genre.size(); i++){
            for(int j=0; j<Genre.size(); j++){
                if(arr[i].compare(Genre[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<" "<<Starring[j]<<endl;
                }

            }
        }
    }
    else if(c.compare("starring")==0){
        for(int i=0; i<Starring.size(); i++){
            arr.push_back(Starring[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<Starring.size(); i++){
            for(int j=0; j<Starring.size(); j++){
                if(arr[i].compare(Starring[j])==0){
                    output<<Title[j]<<" "<<Person[j]<<" "<<Year[j]<<" "<<Genre[j]<<" "<<Starring[j]<<endl;
                }

            }
        }
    }
    else{
        throw(c);
    }
    }
    catch(string& c){
        output<<"Exception: Command is wrong"<<endl;
    }
}
template<class T>
void Catalogs<T> :: CommandFile(ofstream & output){
    ifstream file;
    file.open("commands.txt");
    string a,c,d;
    char b;
    while(!file.eof()){
        file>>a; //search
        if(a.compare("search")==0){
            file>>b; //"
            getline(file,d,'"'); //monkeys
            file>>c; //in
            file>>b; // "
            getline(file,c,'"'); //title
            output<<a<<" "<<b<<d<<b<<" in "<<c<<endl;
            Search(d,c,output);
        }
        else if(a.compare("sort")==0){
            file>>b; // "
            getline(file,c,'"');
            output<<a<<" "<<b<<c<<b<<endl;
            Sort(c,output);
        }
        else throw(c); // in the sort func.
    }
    file.close();
}
template<class T>
void Movie<T> :: CommandFile(ofstream & output){
    ifstream file;
    file.open("commands.txt");
    string a,c,d;
    char b;
    while(!file.eof()){
        file>>a; //search
        if(a.compare("search")==0){
            file>>b; //"
            getline(file,d,'"'); //monkeys
            file>>c; //in
            file>>b; // "
            getline(file,c,'"'); //title
            output<<a<<" "<<b<<d<<b<<" in "<<c<<endl;
            Search(d,c,output);
        }
        else if(a.compare("sort")==0){
            file>>b; // "
            getline(file,c,'"');
            output<<a<<" "<<b<<c<<b<<endl;
            Sort(c,output);
        }
    }
    file.close();
}
template<class T>
void Catalogs<T> :: ReadFromFile(ifstream & file, ofstream & output){
    char a;  // " first
    string b,c,d,e;
    file>>a;  // "
    getline(file,b,'"');   //title
    Title.push_back(b);
    file>>a;  // " "  3 char
        
    getline(file,b,'"');  // authors, artists
    Person.push_back(b);
    file>>a; // " " 3 char
    
    getline(file,b,'"'); // year
    Year.push_back(b);
    file>>a; // " " 3 char
        
    getline(file,b,'"');  // genre, tags
    Genre.push_back(b);
    while(!file.eof()){
        try{
            file>>a;  // "
            getline(file,b,'"');   //title
            int test=0;
            for(int i=0; i<Title.size(); i++) if(b.compare(Title[i])==0 ) test=1;
            if(test==0) Title.push_back(b);
            file>>a;  // " "  3 char
            
            getline(file,c,'"');  // authors, artists
            if(test==0) Person.push_back(c);
            file>>a; // " " 3 char

            getline(file,d,'"'); // year
            if(test==0) Year.push_back(d);
            file>>a; // " " 3 char
            
            string arr=e;
            getline(file,e,'"');  // genre, tags
            if(test==0) Genre.push_back(e);
            if(test==1) throw(test);
            if(arr.compare(e)==0) throw(a);
        }
        catch(int& test){
            output<<"Exception: duplicate entry"<<endl;
            output<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<endl;
        }
        catch(char& a){
            output<<"Exception: missing field"<<endl;
            output<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<endl;
        }
        
    }
    Title.pop_back(); // repeat the last item, I delete it
    Person.pop_back();
    Year.pop_back();
    Genre.pop_back();
    output<<Title.size()<<" unique entries"<<endl;
    CommandFile(output);
}
template<class T>
void Movie<T> :: ReadFromFile(ifstream & file, ofstream & output){
    char a;  // " first
    string b,c,d,e,f;

    file>>a;  // "
    getline(file,b,'"');   //title
    Title.push_back(b);
    file>>a;  // " "  3 char

    getline(file,b,'"');  // authors, artists
    Person.push_back(b);
    file>>a; // " " 3 char
    
    getline(file,b,'"'); // year
    Year.push_back(b);
    file>>a; // " " 3 char
        
    getline(file,b,'"');  // genre, tags
    Genre.push_back(b);
    file>>a;

    getline(file,b,'"');
    Starring.push_back(b);
    while(!file.eof()){
        try{
            file>>a;  // "
            getline(file,b,'"');   //title
            int test=0;
            for(int i=0; i<Title.size(); i++) if(b.compare(Title[i])==0 ) test=1;
            if(test==0) Title.push_back(b);
            file>>a;  // " "  3 char
            
            getline(file,c,'"');  // authors, artists
            if(test==0) Person.push_back(c);
            file>>a; // " " 3 char

            getline(file,d,'"'); // year
            if(test==0) Year.push_back(d);
            file>>a; // " " 3 char
            
            getline(file,e,'"'); // year
            if(test==0) Genre.push_back(e);
            file>>a; // " " 3 char

            string arr=f;
            getline(file,f,'"');  // genre, tags
            if(test==0) Starring.push_back(f);
            if(test==1) throw(test);
            if(arr.compare(f)==0) throw(a);
        }
        catch(int& test){
            output<<"Exception: duplicate entry"<<endl;
            output<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
        }
        catch(char& a){
            output<<"Exception: missing field"<<endl;
            output<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
        }
        
    }
    Title.pop_back(); // repeat the last item, I delete it
    Person.pop_back();
    Year.pop_back();
    Genre.pop_back();
    Starring.pop_back();
    output<<Title.size()<<" unique entries"<<endl;
    CommandFile(output);
}
void Control(){
    ifstream file1;
    ofstream file2;
    file2.open("output.txt");
    file1.open("data.txt");
    string a;
    file1>>a;
    file2<<"Catalog Read: "<<a<<endl;
    Catalogs<string> item1;
    Movie<string> item2;
    if(a=="book" ||a=="music"){
        item1.ReadFromFile(file1,file2);
    }
    else if(a=="movie"){
        item2.ReadFromFile(file1,file2);
    }
    file1.close();
    file2.close();
}
int main(){
    Control();
    return 0;
}