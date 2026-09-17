#include<iostream>
using namespace std;
int main(){
	int data[10]={1,7,2,3,9,4};
	int size =6;
	int key;
	cout<<"Enter value to search :";
	cin>> key;
	int i=0;
	while(i<size && data[i]!= key){
		i++;
		
	}
	if(i<size){
		cout<<"Found at index "<<i<<endl;
		
	}
	else{
		cout<<"Not found"<<endl;
	}
	return 0;
}