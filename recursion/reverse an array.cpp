 public:
    void reverseArray(vector<int> &arr) {
        // code here
        int i;
        int n=arr.size();
      f(arr,0,n);
    }
    void f(vector<int> &arr,int i,int n){
        if(i>=n/2) return;
        swap(arr[i],arr[n-i-1]);
        f(arr,i+1,n);
    }
