#include<vector>
#include<iostream>
using namespace std;


void decimal_to_hex(int x){
	int data = 1<<31;
	for(int i=0;i<32;i++){
		int tmp = x<<i;
		int res = tmp & data;
		if(res !=  0)
			cout<<"1";
		else 
			cout<<"0";
	}
}
int main(){

	decimal_to_hex(-15);
	return 0;
}
