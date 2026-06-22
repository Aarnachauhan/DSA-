lc 846
better solution using heap
tc-o(n+klogk)
sc-O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        unordered_map<int,int> freq;

        for(int x : hand)
            freq[x]++;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it : freq)
            pq.push(it.first);

        while(!pq.empty()) {

            while(!pq.empty() && freq[pq.top()] == 0)
                pq.pop();

            if(pq.empty())
                break;

            int start = pq.top();

            for(int i = 0; i < groupSize; i++) {

                int card = start + i;

                if(freq[card] == 0)
                    return false;

                freq[card]--;
            }
        }

        return true;
    }
};

optimal solution using map
tc-o(nlogn)
sc-o(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        map<int,int> mpp;
        for(int card:hand){
            mpp[card]++;
        } 
        while(!mpp.empty()){
            int start=mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                int card=start+i;

                if(mpp.find(card)==mpp.end()) return false;
                mpp[card]--;

                if(mpp[card]==0) mpp.erase(card);

            }
        }
        return true;
    }
};
