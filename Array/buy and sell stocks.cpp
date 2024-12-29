https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615
//same day 
int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int ans=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                ans+=prices[i]-prices[i-1];
            }
        }
        return ans;
    }
