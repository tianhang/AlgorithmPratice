#include<iostream>
using namespace std;

int xor_find(int *arr,int n){
	int res = 0;
	for(int i=0;i<n;i++){
		res ^= arr[i];
	}	
	return res;
}
int main(){
	int arr[] = {1,2,3,3,4};	
//	cout<<xor_find(arr,5)<<endl;
	cout<<(1^1)<<endl;
	return 0;
}
