#include<iostream>
#include<vector>
using namespace std;

//Simple insertion sort
template <typename Comparable>
void insertionSort(vector<Comparable> &a) {
	int j;
	for(int i=1; i!=a.size(); ++i) {
		Comparable tmp = a[i];
		for(j=i; tmp<a[j-1] && j>0; --j) {
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
}
//Shellsort,using Shell's increments
template <typename Comparable>
void shellSort(vector<Comparable> &a) {
	for(int gap = a.size(); gap > 0; gap /= 2){
		int j;
		for(int i=1; i!=a.size(); ++i) {
			Comparable tmp = a[i];
			for(j=i; tmp<a[j-gap] && j>= gap; j -= gap) {
				a[j] = a[j-gap];
			}
			a[j] = tmp;
		}
	}
}


int main() {
	vector<int> a;
	int num;
	while(cin>>num) {
		a.push_back(num);
	}
	shellSort(a);
	for(int i=0; i!=a.size(); ++i) {
		cout<<a[i]<<" ";
	}
}
