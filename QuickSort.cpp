#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void quickSort(vector<int> &v,int left,int right){
	int i = left,j=right;
	int pivot = v[left + (right-left)/2];
	
	//partition
	while(i <= j){
		while(v[i] < pivot)
			i++;
		while(v[j] > pivot)
			j--;
		if(i <= j){
			swap(v[i],v[j]);
			i++;
			j--;
		}
	}	
	//recursion	
	if(left < j) quickSort(v,left,j);
	if(right > i) quickSort(v,i,right);

}
int main(){
	vector<int>v;
	for(int j=0;j<100;j++)
		v.push_back(rand()%100);
	int len = v.size();
	quickSort(v,0,len-1);	
	for(int i=0;i<len;i++)
		cout<<v[i]<<",";
	return 0;
}
