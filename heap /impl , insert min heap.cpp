no platform -> refer gfg

in maxheap , we didnt put anything in index0 , but here ,we started from 0 . thats why parent= i-1/2 and not parent=i/2
tc-o(logn )
sc-o(n) 
#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> & heap , int value){
    heap.push_back(value);
    int index=heap.size()-1;
    while(index > 0 && heap[(index-1)/2] > heap[index]){
        swap(heap[index], heap[(index-1)/2]);
        
        index=(index-1)/2;
    }

};

int main() {
	// your code goes here
	vector<int>arr;
    vector<int>values = {10, 3, 2, 4, 5, 1};
    int n = values.size();
    for (int i = 0; i < n; i++) {
        insert(arr, values[i]);
        cout << "Inserted " << values[i]
             << " into the min-heap: ";
        for (int j = 0; j <arr.size(); j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
