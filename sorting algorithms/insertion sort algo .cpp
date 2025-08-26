gfg
tc-best case o(n) 
worst case o(n2)
sc-o(1)
class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=1;i<n;i++){
            int key=arr[i];
            int j=i-1; //prev
            
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }
};
