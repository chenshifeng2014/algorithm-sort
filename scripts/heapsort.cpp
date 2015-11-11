#include<iostream>
#include<vector>
using namespace std;

//standard  heapsort
inline int leftChild(int i) {
	return 2*i+1;
}

template <typename Comparable>
void perDown(vector<Comparable> &a,int i,int n) {
	int child;
	Comparable tmp;
	for(tmp = a[i]; leftChild(i)<n; i=child) {
		child = leftChild(i);
		if(child!=n-1 && a[child]<a[child+1])
			child++;
		if(tmp<a[child]) {
			a[i].swap(a[child]);
		} else {
			break;
		}
	}
	a[i] = tmp;
}

template <typename Comparable>
void heapSort(vector<Comparable> &a) {
	for(int i=a.size() / 2; i>=0; --i)
		perDown(a,i,a.size());
	for(int j=a.size()-1; j>0; --j) {
		swap(a[0],a[j]);
		perDown(a,0,j);
	}
}

int main() {
	vector<int> a;
	int num;
	while(cin>>num) {
		a.push_back(num);
	}
	heapSort(a);
	for(int i=0; i!=a.size(); ++i) {
		cout<<a[i]<<" ";
	}
}
