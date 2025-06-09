gfg
T.C. - O(N*denominations*coin_selected) ~ O(log(n))
S.C  - O(1)

vector<int> minPartition(int N) {
        // code here
        vector<int> res;
        vector<int> denom={1,2,5,10,20,50,100,200,500,2000};
        int j=denom.size()-1;
        while(N){
            if(denom[j]<=N){
                res.push_back(denom[j]);
                N-=denom[j];
                
            }
            else{
                j--;
            }
        }
        return res;
    }
