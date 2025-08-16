gfg
naive- o(n2) 
sc-O(1)
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size();
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==0){
                  maxi=max(maxi,j-i+1);  
                }
            }
        }
        return maxi;
    }
};


//tc-o(n logn) where n is for traversal , logn n for hashmap traversal
//sc- O(n)
gfg
int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int,int> mpp;
        int n=arr.size();
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxi= i+1;
            }
            else{
                if(mpp.find(sum)!=mpp.end()){
                    maxi=max(maxi, i-mpp[sum]);
                }
                else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
