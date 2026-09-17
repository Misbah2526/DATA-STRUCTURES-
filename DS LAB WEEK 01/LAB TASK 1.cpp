#include<iostream>
using namespace std;
int main(){
	int start, stop,x,sum=0;
	cout<<"Enter X:";
	cin>>x;
	cout<<"Enter start :";
	cin>>start;
	cout<<"Enter stop:";
	cin>>stop;
	for(int i=start;i<=stop;i++){
		sum+=x*x;
		
	}
	cout<<"Sum of x*x:"<<sum;
	return 0;
}