#include<cstdlib>
#include<time.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string alpha("abcdefghijklmnopqrstuvwxyz");
	string a,b;
	unsigned int c;
	while(1){
		//generate random string
		srand(time(NULL));
		c=rand();
		for(int i=0;i<10;i++){
			c/=2;
			a+=alpha[c%26];
		}
		cout<<a<<endl;
		//typing
		cin>>b;
		//judgement
		if(a==b){
			cout<<"OK!"<<endl;
		}else{
			cout<<"Failed"<<endl;
			break;
		}
		//reset
		a.clear();
		b.clear();
	}
	return 0;
}