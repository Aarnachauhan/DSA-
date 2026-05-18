gfg
tc-o(n2)
Sc-o(1)
brute force:
class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    swap(arr[i],arr[j]);
                }
            }
            
        }
    }
};
optimal :

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        bool swapped;
        
        for(int i=0;i<n-1;i++){
            swapped=false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped=true;
                }
            }
            if(!swapped){
                break;
            }
        }
    }
};
