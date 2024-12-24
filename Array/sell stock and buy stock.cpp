class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        int minsofar=prices[0];
        for(int i=0;i<n;i++){
          minsofar=min(prices[i],minsofar);
          int profit=prices[i]-minsofar;
          maxprofit=max(profit,maxprofit);
        }
        return maxprofit;
    }
};
