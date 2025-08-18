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
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        
        long long sn=(n*(n+1))/2; //x-y
        long long s2n=(n*(n+1)*(2*n+1))/6; //x2-y2
        
        long long s=0, s2=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
            s2+=(long long)arr[i]*(long long)arr[i];
        }
        long long val1=s-sn;
        long long val2=s2-s2n;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        
        return {(int)x,(int)y};
        
        }
};

optimal 2- array marking
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int rep=-1;
        for(int i=0;i<n;i++){
            int val=abs(arr[i]);
            
            if(arr[val-1]>0){
                arr[val-1]*=-1;
            }else{
                //found the duplicate one.
                rep=val;
            }
            
        }
        int miss=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                miss=i+1;
                break;
            }
        }
        return {rep,miss};
    }
};
