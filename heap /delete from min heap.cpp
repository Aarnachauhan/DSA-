#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap , int i){
    int smallest=i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<heap.size() && heap[left]<heap[smallest]){
        smallest=left;
    }
    if(right<heap.size() && heap[right]<heap[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(heap[i],heap[smallest]);
        heapify(heap,smallest);
    }
}

int extractmin(vector<int>&heap){
    if(heap.empty()) return -1;
    int minielement=heap[0];
    heap[0]=heap.back();
    heap.pop_back();
    
    if(!heap.empty()){
        heapify(heap,0);
    }
    return minielement;
}



int main() {
	// your code goes here
	vector<int> heap={2,5,10,20,15};
	cout<<"deleted" <<extractmin(heap)<<endl;
	
	for(int x:heap){
	    cout<<x<<" ";
	}
}
