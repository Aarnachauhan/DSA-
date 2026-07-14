no platform-- codechef
output : 55 54 53 50 52 
tc-o(logn )

my code:
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Maxheap{
    public:
    vector<int> heap;
    
    void insert(int val){
        heap.push_back(val);
        int ind=heap.size()-1;
        while(ind>0){
            int parent=(ind-1)/2;
            if(heap[parent]<heap[ind]){
                swap(heap[parent],heap[ind]);
                parent=ind;
            }else break;
        }
        
    }
    
    void print(){
        for(int x:heap){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};



int main(){
    Maxheap h;
    h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();

}

older code:
#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        
        while(index>1){
            int parent=index/2;
            if(arr[parent]< arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main() {
	// your code goes here
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();

}
