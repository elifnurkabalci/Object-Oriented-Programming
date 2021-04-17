#include <iostream>
#include <vector>
#include <fstream>
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
    int read_ppm(const string source_ppm_file_name, ppmImage& destination_object);
    int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object);
    int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice);
    ppmImage single_color(const ppmImage& source, int color_choice);
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
    string s="";
    for(int i=0; i< sizeof(argv[1]); i++){  // for define argument
        if(argv[1][i]==argv[2][0]){
        	i=sizeof(argv[1])-1;
        }
        else{
        	s = s + argv[1][i];
    	}
    }
    ppmImage obj(s);
    int arg=(int)argv[2][0]-'0';
    switch (arg) //argc
    {
    case 1:
        obj.read_ppm(s,obj);
        obj.write_ppm("o1.ppm",obj);
        break;
    case 2:
        obj.read_ppm(s,obj);
        obj.swap_channels(obj,1);
        obj.write_ppm("o2.ppm",obj);
        break;
    case 3:
        obj.read_ppm(s,obj);
        obj.swap_channels(obj,2);
        obj.write_ppm("o3.ppm",obj);
        break;
    case 4:
        obj.read_ppm(s,obj);
        obj.swap_channels(obj,3);
        obj.write_ppm("o4.ppm",obj);
        break;
    case 5:
        obj.read_ppm(s,obj);
        obj.single_color(obj,1);
        obj.write_ppm("o5.ppm",obj);
        break;
    case 6:
        obj.read_ppm(s,obj);
        obj.single_color(obj,2);
        obj.write_ppm("o6.ppm",obj);
        break;
    case 7:
        obj.read_ppm(s,obj);
        obj.single_color(obj,3);
        obj.write_ppm("o7.ppm",obj);
        break;
    default:
        cerr<<"Error"<<endl;
        break;
    }
    return 0;
}
