#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void heapify(vector<int> &v,int i,int size){
	int lnode = 2*i + 1;
	int rnode = 2*i + 2;
	int min = i;
	if(lnode <= size && v[lnode] < v[min])
		min = lnode;
	if(rnode <= size && v[rnode] < v[min])
		min = rnode;
	if(min != i){
		swap(v[i],v[min]);
		heapify(v,min,size);
	}
}
void HeapSort(vector<int> &v){
	int len = v.size();
	for(int i=len/2;i>=0;i--){
		heapify(v,i,len-1);	
	}
	for(int j=len-1;j>=0;j--){
		swap(v[j],v[0]);
		heapify(v,0,j-1);
	}
}
int main(){
	vector<int>v;	
	for(int i=0;i<100;i++){
		v.push_back(rand()%100);
	}
	HeapSort(v);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<",";
	}
	
	return 0;
}
