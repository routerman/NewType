#include<cstdlib>
#include<time.h>
#include<iostream>
#include<string>
using namespace std;

class NewType{
	string alpha;
	string answer;
	string input;
	int length;
	int count;
public:
	NewType();
	~NewType();
	void Proc();
	string getRandomString();
};

NewType::NewType(){
	alpha.append("abcdefghijklmnopqrstuvwxyz");
	length=10;
	count=0;
}

NewType::~NewType(){}

/* generate random string */
string NewType::getRandomString(){
	string a;
	unsigned int number;
	srand(time(NULL));
	number=rand();
	for(int i=0;i<length;i++){
		number/=2;
		a+=alpha[number%26];
	}
	return a;
}

void NewType::Proc(){
	while(1){
		answer=getRandomString();
		cout<<"["<<count<<"]";
		cout<<answer<<endl;
		//typing
		cout<<"-->";
		cin>>input;
		//judgement
		if(answer==input){
			cout<<"OK!"<<endl;
			count++;
		}else{
			cout<<"Failed"<<endl;
		}
		//reset
		answer.clear();
		input.clear();
	}
}

/* main function */
int main(){
	NewType *nt = new NewType();
	nt->Proc();
	return 0;
}