#include<cstdlib>
#include<time.h>
#include<iostream>
#include<string>

using namespace std;

string getRandomString(int length){
	static string alpha("abcdefghijklmnopqrstuvwxyz");
	string a;
	unsigned int number;
	//generate random string
	srand(time(NULL));
	number=rand();
	for(int i=0;i<length;i++){
		number/=2;
		a+=alpha[number%26];
	}
	return a;
}




int main(){
	string answer,b;
	while(1){
		answer=getRandomString(10);
		cout<<"$";
		cout<<answer<<endl;
		//typing
		cout<<">";
		cin>>b;
		//judgement
		if(answer==b){
			cout<<"OK!"<<endl;
		}else{
			cout<<"Failed"<<endl;
			break;
		}
		//reset
		answer.clear();
		b.clear();
	}
	return 0;
}