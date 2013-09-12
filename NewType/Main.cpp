#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>
using namespace std;

class NewType{
	string alpha;
	string answer;
	string input;
	time_t start,finish;
	time_t s_start,s_finish;
	double second;
	int length;
	int count;
public:
	NewType();
	~NewType();
	void Proc();
	void display();
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
	srand(time(NULL));
	time_t number = rand();
	for(int i=0;i<length;i++){
		number/=2;
		a+=alpha[number%26];
	}
	return a;
}

void NewType::display(){
}

void NewType::Proc(){
	time(&start);
	while(count<4){
		answer=getRandomString();

		time(&s_start);
		display();
		cout<<"["<<count<<"]";
		cout<<answer<<endl;
		//typing
		cout<<"-->";
		cin>>input;
		time(&s_finish);
		
		//judgement
		if(answer==input){
			cout<<"OK!"<<endl;
			second=difftime(s_finish,s_start);
			cout<<second<<endl;
			count++;
		}else{
			cout<<"Failed"<<endl;
		}
		//reset
		answer.clear();
		input.clear();
	}
	time(&finish);
	second=difftime(finish,start);
	cout<<second<<endl;
}

/* main function */
int main(){
	NewType *nt = new NewType();
	nt->Proc();
	return 0;
}