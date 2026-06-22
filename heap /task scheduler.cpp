lc 621


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26,0);

        for(char i: tasks){ //frequency store
            mp[i-'A']++; 
        }

        for(int i=0;i<26;i++){
            if(mp[i]){
                pq.push(mp[i]);
            }
        }

        int time=0; //stores the total time taken
        while(!pq.empty()){
            vector<int> remain;
            int cycle=n+1;

            while(cycle && !pq.empty()){
                int maxfreq=pq.top(); //task at the top should be assigned first
                pq.pop();
                if(maxfreq>1){
                    remain.push_back(maxfreq-1);
                }
                time++;
                cycle--;

            }

            for(int count:remain){
                pq.push(count);
            }
            if(pq.empty()) break; //nothing in pq.
            else time+=cycle; //calculates idle time.
        }
        return time;
    }
};
