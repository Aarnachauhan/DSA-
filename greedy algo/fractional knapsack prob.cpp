gfg
tc-O(nlogn)
sc-o(n)
static bool compare(vector<int>& a, vector<int>& b) {
    double a1 = (1.0 * a[0]) / a[1];  // value/weight of item a
    double b1 = (1.0 * b[0]) / b[1];  // value/weight of item b
    return a1 > b1;                   // higher ratio comes first
}
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>> items(n, vector<int>(2));
        
        for(int i=0;i<n;i++){
            items[i][0]=val[i];
            items[i][1]= wt[i];
        }
        sort(items.begin(),items.end(),compare);
        
        double res=0.0;
        int currcap=capacity;
        
        for(int i=0;i<n;i++){
            if(items[i][1]<=currcap){
                res+=items[i][0];
                currcap-=items[i][1];
            }
            else{
                res+=(1.0 * items[i][0]/items[i][1])* currcap;
                break;
            }
          
        }
        return res;
    }
};
