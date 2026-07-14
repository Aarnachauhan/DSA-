no platform -> refer gfg

tc-o(logn )
sc-o(n) 

#include <bits/stdc++.h>
using namespace std;
class MinHeap{
    public:
    vector<int> heap;
    
    void insert(int val){
        heap.push_back(val);
        int ind=heap.size()-1;
        
        while(ind>0){
            int parent=(ind-1)/2;
            
            if(heap[parent]>heap[ind]){
                swap(heap[parent],heap[ind]);
                ind=parent;
            }
            else break;
        }
    }
    
    void print(){
        for(int x:heap){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};



int main() {
	MinHeap h;
	h.insert(10);
	h.insert(20);
	h.insert(5);
	h.insert(15);
	h.insert(2);
	
	h.print();
	
	return 0;

}
