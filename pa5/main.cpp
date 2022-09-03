#include<iostream>
#include<fstream>
#include"gate.h"

using namespace std;

int main(){
	string line,name;				
	char space=' ';			 
	int count1=0, count2=0, ind=0, gate_num;			
	Gate **gates;				
	

	//***************************************************************************************
	// circuit part
	ifstream file1("circuit.txt");		 		
	if(!file1.is_open()) exit(1);
	
	while(getline(file1,line)){
		if(count1==0){			
			for(int i=0; i<line.length(); i++){ 
				if(line[i]==space) count2++; // # of input 
			}
		}
		count1++; // line
	}
	
	gate_num = count2+count1-2;	// 4 + 8 -2  - > 2, input and output, in 8 already exist	
	gates = new Gate*[gate_num];	

	file1.clear();				
	file1.seekg(0,ios::beg);	 
	while(getline(file1,line)){
		name=line.substr(0,line.find(" "));	

		if(name=="INPUT"){	
			for(int i=0; i<count2; i++){  // create input object number of input		 
				gates[ind]=new Input();			
				gates[ind]->set_name(name);	
				line=line.substr(line.find(" ")+1,line.length()-line.find(" "));	
				gates[ind]->set_frstname(line.substr(0,line.find(" ")));		
				ind++;
			}
		}
		else if(name=="OUTPUT"){ continue; }
		// this part;
		// save the gate names, so I can find the object if ı want
		else if(name=="AND"){		
			gates[ind]=new And();
			gates[ind]->set_name(line.substr(0,line.find(" ")));

			for(int i=0; i<3; i++){		
				line=line.substr(line.find(" ")+1,line.length()-line.find(" "));	
				if(i==0) gates[ind]->set_output(line.substr(0,line.find(" ")));
				else if(i==1) gates[ind]->set_frstname(line.substr(0,line.find(" ")));
				else gates[ind]->set_scndname(line.substr(0,line.find(" ")));	
			}
			ind++;	
		}
		else if(name=="OR"){		
			gates[ind]=new Or();
			gates[ind]->set_name(line.substr(0,line.find(" ")));
			for(int i=0; i<3; i++){			
				line=line.substr(line.find(" ")+1,line.length()-line.find(" "));
				if(i==0) gates[ind]->set_output(line.substr(0,line.find(" ")));
				else if(i==1) gates[ind]->set_frstname(line.substr(0,line.find(" ")));
				else gates[ind]->set_scndname(line.substr(0,line.find(" ")));	
			}
			ind++;
		}

		else if(name=="NOT"){	
			gates[ind]=new Not();
			gates[ind]->set_name(line.substr(0,line.find(" ")));
			for(int i=0; i<2; i++){	
				line=line.substr(line.find(" ")+1,line.length()-line.find(" "));
				if(i==0) gates[ind]->set_output(line.substr(0,line.find(" ")));
				else if(i==1) gates[ind]->set_frstname(line.substr(0,line.find(" ")));	
			}
			ind++;		
		}
		else if(name=="FLIPFLOP"){	
			gates[ind]=new FlipFlop();
			gates[ind]->set_name(line.substr(0,line.find(" ")));
			for(int i=0; i<2; i++){	
				line=line.substr(line.find(" ")+1,line.length()-line.find(" "));
				if(i==0) gates[ind]->set_output(line.substr(0,line.find(" ")));
				else if(i==1) gates[ind]->set_frstname(line.substr(0,line.find(" ")));	
			}
			ind++;		
		}
		else if(name=="DECODER"){
			gates[ind]=new Decoder();
			gates[ind]->set_name(line.substr(0,line.find(" ")));
			for(int i=0; i<6; i++){	
				line=line.substr(line.find(" ")+1,line.length()-line.find(" "));
				if(i==4) gates[ind]->set_frstname(line.substr(0,line.find(" ")));
				else if(i==5) gates[ind]->set_scndname(line.substr(0,line.find(" ")));
			}
		ind++;
		}
	}
	file1.close();
	 //*********************************************************************************************
	//input part
	ifstream file2("input.txt");	 
	if(!file2.is_open()) exit(1);
	
	int res_temp, flag1=0, flag2=0, res=0, num,index=0, fm_out=0; 
	
	while(!file2.eof()){
		index=0;		
		file2>>num; // 1010
		gates[index]->set_variable(num/1000); // first digit
		index++;
		num -= (num/1000)* 1000; // 1 * 1000 -> 010
		gates[index]->set_variable(num/100); // second digit
		index++;
		num -= (num/100) * 100; // 0
		gates[index]->set_variable(num/10); // third digit
		index++;
		num -= (num/10) * 10; // 1
		gates[index]->set_variable(num/1); // fourth digit
		index++;
		for(int i=count2; i<gate_num; i++){	 
			flag1=0; flag2=0;
			if(gates[i]->get_name()=="FLIPFLOP"){ 
				gates[i]->set_former_out(fm_out);  // former out special for flip flop
			}
			for(int j=0; j<count2; j++){				  // if gates first name in input variables, flags are made for it
				if(gates[i]->get_frstname()==gates[j]->get_frstname()){
					gates[i]->set_input_p1(gates[j]);
					flag1=1;
				}
			}
			if(flag1!=1){						  // if it is not input variable look at others
				for(int j=count2; j<gate_num; j++){
					if(gates[i]->get_frstname()==gates[j]->get_output()){
						gates[i]->set_input_p1(gates[j]);
					}
				}
			}
			if(gates[i]->get_name()!="NOT" && gates[i]->get_name()!="FLIPFLOP"){ // this part for second variables, flipflop and not gates have not 
				for(int j=0; j<count2; j++){		 
					if(gates[i]->get_scndname()==gates[j]->get_frstname()){
						gates[i]->set_input_p2(gates[j]);
						flag2=1;
					}
				}
				if(flag2!=1){					
					for(int j=count2; j<gate_num; j++){
						if(gates[i]->get_scndname()==gates[j]->get_output()){
							gates[i]->set_input_p2(gates[j]);
						}
					}
				}
			}
			if(gates[i]->get_name()=="DECODER"){	  // it is decoder, it is last part
				gates[i]->setup();
				cout<<gates[i]->get_variable()<<" "<<gates[i]->get_variable2()<<" "<<gates[i]->get_variable3()<<" "<<gates[i]->get_variable4()<<endl;
				res++;
				continue;
			}
			res_temp=gates[i]->setup();			// call the last setup and save the result for former out
			if(gates[i]->get_name()=="FLIPFLOP") fm_out=res_temp;
			
		}
		if(res==0) cout<<res_temp<<" ";
	}
	file2.close();
	return 0;
}