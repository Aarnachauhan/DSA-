gfg

idk how the code works

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
