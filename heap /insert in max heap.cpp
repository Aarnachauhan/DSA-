
#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &heap, int val){
    heap.push_back(val); //insert at the end
    int i=heap.size()-1;
    while(i>0){
        int parent=(i-1)/2;
    if(heap[parent]<heap[i]){
        swap(heap[parent],heap[i]);
        i=parent;
    }
    else break;
    }
}




int main() {
	// your code goes here
	vector<int> heap={2,5,10,20,15};
	
	insert(heap,25);
	cout<<"after insertion"<<endl;
	for(int x:heap){
	    cout<<x<<" ";
	}
}
output: 
after insertion
25 5 2 20 15 10 
