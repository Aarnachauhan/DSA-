gfg
visited array
tc-o(n)
sc-o(n)

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> freq(n+1,0);
        int missing=-1;
        int dup=-1;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i]==0) missing=i;
            else if(freq[i]==2) dup=i;
        }
        return {dup,missing};
    }
};

optimal 
tc-o(n)
sc-o(1)
