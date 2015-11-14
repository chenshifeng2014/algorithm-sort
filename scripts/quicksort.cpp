#include<iostream>
#include<vector>
using namespace std;

//median3 function
template <typename Comparable>
const Comparable &median3(vector<Comparable> &a,int left,int right) {
	int center = (left + right) / 2;
	if(a[center] < a[left])
		swap(a[center],a[left]);
	if(a[right]<a[left])
		swap(a[right],a[left]);
	if(a[right]<a[center])
		swap(a[right],a[center]);
	swap(a[center],a[right-1]);
	return a[right-1];
}
//quicksort
template <typename Comparable>
void quickSort(vector<Comparable> &a,int left,int right) {
	if(left>=right)
		return;
	Comparable pivot = median3(a,left,right);
	int i = left;
	int j = right - 1;
	for(;;) {
		while(a[++i]<pivot) {}
		while(a[--j]>pivot) {}
		if(i<j) 
			swap(a[i],a[j]);
		else
			break;
	}
	if(left + 1 != right)
		swap(a[i],a[right-1]);
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
	
}

template <typename Comparable>
void quickSort(vector<Comparable> &a) {
	quickSort(a,0,a.size() - 1);
}

int main() {
	vector<int> a;
	int num;
	while(cin>>num) {
		a.push_back(num);
	}
	quickSort(a);
	for(int i=0; i!=a.size(); ++i) {
		cout<<a[i]<<" ";
	}
}
