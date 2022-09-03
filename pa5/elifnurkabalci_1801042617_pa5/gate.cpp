#include<iostream>
#include<fstream>
#include"gate.h"

using namespace std;

void And::set_input_p1(Gate *rhs){		
	input1=rhs;				 
	output_variable=input1->get_variable();
}
int And::setup(){			 
	int temp1, temp2;
	temp1=input1->setup();	 
	temp2=input2->setup();
	return temp1 && temp2;
}
	
int Or::setup(){	
	int temp1,temp2;
	temp1=input1->setup();	 
	temp2=input2->setup();
	//cout<<"aaa  "<<temp1<<"       "<<temp2<<endl;
	return temp1 || temp2;
}

int Not::setup(){	
	int temp;
	temp=input1->setup();	 
	if(temp==0) temp=1;
	else temp=0;
	output_variable = temp;
	return temp;
}

int FlipFlop::setup(){			
	int temp,f_o;
	f_o=former_out;				
	temp=input1->setup();	
	if(temp==f_o) temp=0;
	else temp=1;
	return temp;
}

int Decoder::setup(){	
	int temp1,temp2;
	temp1=input1->setup(); 
	temp2=input2->setup();
	
	output_variable=0;
	output_variable2=0;
	output_variable3=0;
	output_variable4=0;

	if(temp1==0 && temp2==0) output_variable=1;
	else if(temp1==0 && temp2==1) output_variable2=1;	
	else if(temp1==1 && temp2==0) output_variable3=1;
	else if(temp1==1 && temp2==1) output_variable4=1;

	return 1;
}