#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class ppmImage
{
private:
    string name;
public:
    vector<int> Object;
    void set_name(string Name){  //getter setter for name 
        name = Name;
    }
    string get_name(){
        return name;
    }
    ppmImage(string &s);
    ppmImage(/* dimention*/);
    friend ostream & operator << (ostream &out,ifstream& file);
    friend ppmImage& operator + (const ppmImage &obj1, const ppmImage &obj2);
    friend ppmImage& operator - (const ppmImage &obj1, const ppmImage &obj2);
    int& operator ()(int row, int col, int colo_channel);
    int read_ppm(const string source_ppm_file_name, ppmImage& destination_object);
    int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object);
    int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice);
    ppmImage single_color(const ppmImage& source, int color_choice);
    int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);
    int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);
    int test_print(const string filename_image1);
    ~ppmImage();
};
ppmImage::ppmImage(string &s) // create form file with hw page
{
    Object.push_back(0);  // first row
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(100);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(255);
    Object.push_back(0);
    Object.push_back(255);

    Object.push_back(0);  //second row
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(255);
    Object.push_back(175);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);

    Object.push_back(0);  //third row
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(15);
    Object.push_back(175);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);

    Object.push_back(255);  // fourth row
    Object.push_back(0);
    Object.push_back(255);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(0);
    Object.push_back(255);
    Object.push_back(255);
    Object.push_back(255);

}
ostream & operator <<(ostream &out,ifstream& file){
    string data;
    while(!file.eof()){
        file>>data;
        out<<data;
    }
    return out;
}
ppmImage& operator + ( ppmImage &obj1, const ppmImage &obj2){
    //ppmImage obj3;
    for(int i=0; i<48; i++){ 
        obj1.Object[i]=(obj1.Object[i]+obj2.Object[i]);
    }
    return obj1;
}
ppmImage& operator - (ppmImage &obj1, const ppmImage &obj2){
    //ppmImage obj3;
    for(int i=0; i<48; i++){ 
        obj1.Object[i]=(obj1.Object[i]-obj2.Object[i]);
    }
    return obj1;
}
int& ppmImage::operator()(int row, int col, int color_channel){
    // (row)*4+(col*2)+color_channel
    //  0 0 0   5 5 5   6 6 6   2 2 2
    //  1 1 1   2 2 2   3 3 3   5 5 5
    return Object[(row)*12+(col*2)+color_channel];
}
int ppmImage::test_addition(const string filename_image1, const string filename_image2, const string filename_image3){
    ifstream file1,file2;
    file1.open(filename_image1);
    file2.open(filename_image2);
    ofstream file3;
    file3.open(filename_image3);
    string data1,data2;
    for(int i=0; i<3; i++){
        getline(file1,data1);
        getline(file2,data1);
        file3<<data1<<endl;
    }
    int dt1, dt2,k=0;
    while(!file2.eof()){
        file1>>data1;
        file2>>data2;
        dt1 = std::stoi(data1);
        dt2 = std::stoi(data2);
        if(dt1+dt2>=255){
            file3<<255;
        }
        else if(dt1+dt2<=0){
            file3<<0;
        }
        else{
            file3<<dt1+dt2;
        }
        file3<<"   ";
        if(k%6==1 && k!=0) file3<<"\t";
        if(k%12==1 && k!=0) file3<<endl;
        k++;
    }
    file1.close();
    file2.close();
    file3.close();
    return dt1;
}
int ppmImage::test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3){
    ifstream file1,file2;
    file1.open(filename_image1);
    file2.open(filename_image2);
    ofstream file3;
    file3.open(filename_image3);
    string data1,data2;
    for(int i=0; i<3; i++){
        getline(file1,data1);
        getline(file2,data1);
        file3<<data1<<endl;
    }
    int dt1, dt2, k=0;
    while(!file2.eof()){
        file1>>data1;
        file2>>data2;
        dt1 = std::stoi(data1);
        dt2 = std::stoi(data2);
        if(dt1-dt2>=255){
            file3<<255;
        }
        else if(dt1-dt2<=0){
            file3<<0;
        }
        else{
            file3<<dt1-dt2;
        }
        file3<<"   ";
        if(k%6==1 && k!=0) file3<<"\t";
        if(k%12==1 && k!=0) file3<<endl;
        k++;
    }
    file1.close();
    file2.close();
    file3.close();
    return dt2;
}
int ppmImage::test_print(const string filename_image1){
    ifstream file;
    file.open(filename_image1);
    cout<<file;
    file.close();
    return 1;
}
ppmImage::ppmImage()  // fill vector with white numbers
{
	for(int j=0; j<48; j++){   // fill with white for beginnig
        Object.push_back(255);
    }
}

ppmImage::~ppmImage() // default constructor
{
    for(int i=0; i<48; i++){   // fill with white for cleaning 
        Object.push_back(255);
    }
}

int ppmImage::read_ppm(const string source_ppm_file_name, ppmImage& destination_object){
    destination_object.name=source_ppm_file_name; // define the name of object
    int m=1;
    return 1;
}
int ppmImage::write_ppm(const string destination_ppm_file_name, const ppmImage& source_object){
    ofstream file;
    file.open(destination_ppm_file_name);
    file<<"P3"<<endl<<"4 4"<<endl<<"255"<<endl;
    for(int i=0; i<Object.size(); i++){   // write in file
        file<<Object[i]<<"  ";
        if(i%6==1 && i!=0) file<<"\t";
        if(i%12==1 && i!=0) file<<endl;
    }
    file.close();
    if(file) return 1; // returns 1 if the operation is successful. otherwise, returns 0.
    else return 0;
    
}
int ppmImage::swap_channels(ppmImage& image_object_to_be_modified, int swap_choice){
    int arr[3],m=1; 
    int ptr[3]; 
    if(swap_choice==1){ //red to green
        arr[0]=100;  //red
        arr[1]=0;
        arr[2]=0;
        ptr[0]=0;   //green
        ptr[1]=255;
        ptr[2]=175;
    }
    else if(swap_choice==2){ // red to blue
        arr[0]=100; //red
        arr[1]=0;
        arr[2]=0;
        ptr[0]=0;  //blue
        ptr[1]=15;
        ptr[2]=175;
    }
    else if(swap_choice==3){ // green to blue
        arr[0]=0;  // green
        arr[1]=255;
        arr[2]=175;
        ptr[0]=0;  //blue
        ptr[1]=15;
        ptr[2]=175;
    }
    for(int i=0; i<48; i++){
        if(i%3==0){
            if(Object[i]==arr[0] && Object[i+1]==arr[1] && Object[i+2]==arr[2]){  //for swapping
                Object[i]=ptr[0];
                Object[i+1]=ptr[1];
                Object[i+2]=ptr[2];
            }
            else if(Object[i]==ptr[0] && Object[i+1]==ptr[1] && Object[i+2]==ptr[2]){
                Object[i]=arr[0];
                Object[i+1]=arr[1];
                Object[i+2]=arr[2];
            }
        }
    }

    return m;
}
ppmImage ppmImage::single_color(const ppmImage& source, int color_choice){
    if(color_choice==1){ //red
        for(int i=0; i<48; i++){
            if(i%3==0){
            	Object[i]=100;
           		Object[i+1]=0;
            	Object[i+2]=0;
           	}
        }
    }
    else if(color_choice==2){  // green
        for(int i=0; i<48; i++){
            if(i%3==0){
            	Object[i]=0;
            	Object[i+1]=255;
            	Object[i+2]=175;
            }
        }
    }
    else if(color_choice==3){  // blue
        for(int i=0; i<48; i++){
        	if(i%3==0){
            	Object[i]=0;
            	Object[i+1]=15;
            	Object[i+2]=175;
            }
        }
    }
    return source;
}
int main(int argc, char** argv){
    string ppm_file_name1="";
    for(int i=0; i< sizeof(argv[2]); i++){  // for define argument ppm1
        if(argv[2][i]==argv[3][0]){
        	i=sizeof(argv[2])-1;
        }
        else{
        	ppm_file_name1 = ppm_file_name1 + argv[2][i];
    	}
    }
    // argv[1] -> number of choose arg
    // argv[2] -> ppm_file_name1  
    // argv[3] -> ppm_file_name2  
    // argv[4] -> ppm_file_name3  
    string ppm_file_name2="";
    for(int i=0; i< sizeof(argv[3]); i++){  // for define argument ppm2
        if(argv[3][i]==argv[4][0]){
        	i=sizeof(argv[3])-1;
        }
        else{
        	ppm_file_name2 = ppm_file_name2 + argv[3][i];
    	}
    }
    string ppm_file_name3="";
    for(int i=0; i< sizeof(argv[4]); i++){   // for define argument ppm3
        ppm_file_name3 = ppm_file_name3 + argv[4][i];
    }

    ppmImage obj(ppm_file_name1);

    int arg=(int)argv[1][0]-'0';
    switch (arg) //argc
    {
    case 1:
        //obj.read_ppm(ppm_file_name1,obj);
        //obj.write_ppm("o1.ppm",obj);
        if(ppm_file_name2.empty() || ppm_file_name3.empty()){}
        else{
            obj.test_addition(ppm_file_name1, ppm_file_name2, ppm_file_name3);
        }
        break;
    case 2:
        //obj.read_ppm(ppm_file_name1,obj);
        //obj.swap_channels(obj,1);
        //obj.write_ppm("o2.ppm",obj);
        if(ppm_file_name2.empty() || ppm_file_name3.empty()){}
        else{
            obj.test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3);
        }
        break;
    case 3:
        obj.read_ppm(ppm_file_name1,obj);
        obj.swap_channels(obj,2);
        obj.write_ppm(ppm_file_name2,obj);
        break;
    case 4:
        obj.read_ppm(ppm_file_name1,obj);
        obj.swap_channels(obj,3);
        obj.write_ppm(ppm_file_name2,obj);
        break;
    case 5:
        obj.read_ppm(ppm_file_name1,obj);
        obj.single_color(obj,1);
        obj.write_ppm(ppm_file_name2,obj);
        break;
    case 6:
        obj.read_ppm(ppm_file_name1,obj);
        obj.single_color(obj,2);
        obj.write_ppm(ppm_file_name2,obj);
        break;
    case 7:
        obj.read_ppm(ppm_file_name1,obj);
        obj.single_color(obj,3);
        obj.write_ppm(ppm_file_name2,obj);
        break;
    default:
        cerr<<"Error"<<endl;
        break;
    }
    return 0;
}
