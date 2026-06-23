gfg
this solution give tle for 10-15 test cases
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        
        sort(jobs.begin(),jobs.end(),greater<pair<int,int>>());
        
        int maxideadline=*max_element(deadline.begin(),deadline.end());
        
        vector<int> slots(maxideadline+1,-1);
        int cnt=0 , maxprofit=0;
        
        for(int i=0;i<n;i++){
            int currprofit=jobs[i].first;
            int currdeadline=jobs[i].second;
            
            for(int j=currdeadline;j>=1;j--){
                if(slots[j]==-1){
                    cnt++;
                    slots[j]=1;
                    maxprofit+=currprofit;
                    
                    break;
                }
            }
        }
        return {cnt,maxprofit};
        
    }
};


doesnt give tle:
using pq:

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
       
        vector<pair<int,int>> vp;
        int n = deadline.size(), jobs = 0, maxProfit = 0;
        for(int i = 0; i < n; i++) vp.push_back({deadline[i], profit[i]});
        sort(vp.begin(),vp.end());
        priority_queue<int> pq;
        int index =  n - 1;
        for(int i = vp[n - 1].first; i >= 1; i--){
            while(index >= 0 && i == vp[index].first){
                pq.push(vp[index].second);
                index--;
            }
            if(!pq.empty()){
                jobs++;
                maxProfit += pq.top();
                pq.pop();
            }
        }
        return {jobs,maxProfit};
    }
