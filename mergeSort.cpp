#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void merge(vector<int> &v,int left,int pivot,int right){
	vector<int>tmp;
	int i = left,j = pivot +1;
	while(i <= pivot && j <= right){
		if(v[i] < v[j]){
			tmp.push_back(v[i]);
			i++;	
		}else{
			tmp.push_back(v[j]);
			j++;
		}
	}
	while(i <= pivot){
		tmp.push_back(v[i++]);	
	}
	while(j <= right){
		tmp.push_back(v[j++]);
	}
	for(int i=0;i<tmp.size();i++){
		v[left+i] = tmp[i];
	}
}
void mergeSort(vector<int> &v,int left,int right){
	int pivot = left +(right-left)/2;
	if(left == right) return;
	mergeSort(v,left,pivot);	
	mergeSort(v,pivot+1,right);	
	merge(v,left,pivot,right);
}
int main(){
	vector<int>v;
	for(int i=0;i<1000;i++){
		v.push_back(rand()%100);
	}
	mergeSort(v,0,v.size()-1);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<",";
	}
	return 0;
}
