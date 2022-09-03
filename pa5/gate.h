#ifndef gate
#define gate
#include<string>

using namespace std;

class Gate{		
	private:
		string name;		
				
	public:
		Gate(){}
		inline void set_name(string n){ name=n; }
		inline string get_name(){ return name; }

		virtual void set_frstname(string n1){}
		virtual void set_scndname(string n2){}
		virtual string get_frstname(){}	
		virtual string get_scndname(){}	
		virtual void set_output(string out){}
		virtual string get_output(){}	
		virtual void set_variable(int var){}
		virtual int get_variable(){}		
		virtual void set_variable2(int var){} 
		virtual int get_variable2(){}
		virtual void set_variable3(int var){}
		virtual int get_variable3(){}
		virtual void set_variable4(int var){}
		virtual int get_variable4(){}
		virtual void set_former_out(int num){} 
		virtual int get_former_out(){}			
		virtual void set_input_p1(Gate *rhs){}	 
		virtual Gate* get_input_p1(){}				
		virtual void set_input_p2(Gate *rhs){}	 
		virtual Gate* get_input_p2(){}
		virtual int setup(){}					 
};

class Input:public Gate{		
	private:
		string input_name;		
		int output_variable;
		Gate *input1;
		Gate *input2;
	public:
		Input(){}
		inline void set_frstname(string n1){ input_name=n1; }
		inline string get_frstname(){ return input_name; }
		inline void set_variable(int var){ output_variable=var; }
		inline int get_variable(){ return output_variable; }
		inline int setup(){ return output_variable; }


		void set_scndname(string n2){}
		string get_scndname(){}
		void set_output(string out){}
		string get_output(){}		
		void set_variable2(int var){}
		int get_variable2(){}
		void set_variable3(int var){}
		int get_variable3(){}
		void set_variable4(int var){}
		int get_variable4(){}
		void set_former_out(int num){}
		int get_former_out(){}
		void set_input_p1(Gate *rhs){}
		Gate* get_input_p1(){}
		void set_input_p2(Gate *rhs){}
		Gate* get_input_p2(){}
};

class And:public Gate{		
	private:
		string input_name1;	
		string input_name2;	
		string output_name;	
		int output_variable;	
		Gate *input1;
		Gate *input2;
	public:
		And(){}
		inline void set_frstname(string n1){ input_name1=n1; }
		inline string get_frstname(){ return input_name1; }
		inline void set_scndname(string n2){ input_name2=n2; }
		inline string get_scndname(){ return input_name2; }
		inline void set_output(string out){ output_name=out; }
		inline string get_output(){ return output_name; }
		inline void set_variable(int var){ output_variable=var; }
		inline int get_variable(){ return output_variable; }
		inline Gate* get_input_p1(){ return input1; }
		inline void set_input_p2(Gate *rhs){ input2=rhs; }
		inline Gate* get_input_p2(){return input2; }

		int setup();		
		void set_input_p1(Gate *rhs);


		void set_variable2(int var){}
		int get_variable2(){}
		void set_variable3(int var){}
		int get_variable3(){}
		void set_variable4(int var){}
		int get_variable4(){}
		void set_former_out(int num){}
		int get_former_out(){}
};

class Or:public Gate{		
	private:
		string input_name1;
		string input_name2;
		string output_name;
		int output_variable;
		Gate *input1;
		Gate *input2;
	public:
		Or(){}
		inline void set_frstname(string n1){ input_name1=n1; }
		inline string get_frstname(){ return input_name1; }
		inline void set_scndname(string n2){ input_name2=n2; }
		inline string get_scndname(){ return input_name2; }
		inline void set_output(string out){ output_name=out; }
		inline string get_output(){ return output_name; }
		inline void set_variable(int var){ output_variable=var; }
		inline int get_variable(){ return output_variable; }
		inline void set_input_p1(Gate *rhs){ input1=rhs; }
		inline Gate* get_input_p1(){ return input1; }
		inline void set_input_p2(Gate *rhs){ input2=rhs; }
		inline Gate* get_input_p2(){ return input2; }

		int setup();	
		
		
		void set_variable2(int var){}
		int get_variable2(){}
		void set_variable3(int var){}
		int get_variable3(){}
		void set_variable4(int var){}
		int get_variable4(){}
		void set_former_out(int num){}
		int get_former_out(){}
};
class Not:public Gate{		
	private:
		string input_name1;
		string output_name;
		int output_variable;
		Gate *input1;
		
	public:
		Not(){}
		inline void set_frstname(string n1){ input_name1=n1; }
		inline string get_frstname(){ return input_name1; }
		inline void set_output(string out){ output_name=out; }
		inline string get_output(){ return output_name; }
		inline void set_variable(int var){ output_variable=var; }
		inline int get_variable(){ return output_variable; }
		inline void set_input_p1(Gate *rhs){ input1=rhs; }
		inline Gate* get_input_p1(){ return input1; }

		int setup();


		void set_scndname(string n2){}
		string get_scndname(){}
		void set_variable2(int var){}
		int get_variable2(){}
		void set_variable3(int var){}
		int get_variable3(){}
		void set_variable4(int var){}
		int get_variable4(){}
		void set_former_out(int num){}
		int get_former_out(){}
		void set_input_p2(Gate *rhs){}
		Gate* get_input_p2(){}
};

class FlipFlop:public Gate{	
	private:
		string input_name1;
		string output_name;
		int former_out=0;
		int output_variable;
		Gate *input1;
	public:
		FlipFlop(){}
		inline void set_frstname(string n1){ input_name1=n1; }
		inline string get_frstname(){ return input_name1; }
		inline void set_output(string out){ output_name=out; }
		inline string get_output(){ return output_name; }
		inline void set_variable(int var){ output_variable=var; }
		inline int get_variable(){ return output_variable; }
		inline void set_former_out(int num){ former_out=num; }
		inline int get_former_out(){ return former_out; }
		inline void set_input_p1(Gate *rhs){ input1=rhs;}
		inline Gate* get_input_p1(){ return input1; }

		int setup();

		void set_scndname(string n2){}
		string get_scndname(){}
		void set_variable2(int var){}
		int get_variable2(){}
		void set_variable3(int var){}
		int get_variable3(){}
		void set_variable4(int var){}
		int get_variable4(){}
		void set_input_p2(Gate *rhs){}
		Gate* get_input_p2(){}
		
};

class Decoder:public Gate{
	private:
		string output_name;
		int output_variable;
		int output_variable2;
		int output_variable3;
		int output_variable4;
		string input_name1;
		string input_name2;
		Gate *input1;
		Gate *input2;
	public:
		Decoder(){}
		inline void set_frstname(string n1){ input_name1=n1; }
		inline string get_frstname(){ return input_name1; }
		inline void set_scndname(string n2){ input_name2=n2; }
		inline string get_scndname(){ return input_name2; }
		inline void set_output(string out){ output_name=out; }
		inline string get_output(){ return output_name; }
		inline void set_variable(int var){ output_variable=var; }
		inline int get_variable(){ return output_variable; }
		inline void set_variable2(int var){ output_variable2=var; }
		inline int get_variable2(){ return output_variable2; }
		inline void set_variable3(int var){ output_variable3=var; }
		inline int get_variable3(){ return output_variable3; }
		inline void set_variable4(int var){ output_variable4=var; }
		inline int get_variable4(){ return output_variable4; }
		inline void set_input_p1(Gate *rhs){ input1=rhs; }
		inline Gate* get_input_p1(){ return input1; }
		inline void set_input_p2(Gate *rhs){ input2=rhs; }
		inline Gate* get_input_p2(){ return input2; }

		int setup();

		void set_former_out(int num){}
		int get_former_out(){}
};
#endif // gate




