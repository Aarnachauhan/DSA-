gfg
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        set<int> st;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                cout<<i<<" ";
                if(i!=n/i) st.insert(n/i);
            }
            
        }
        for(auto it:st) cout<< it <<" ";
    }
};
