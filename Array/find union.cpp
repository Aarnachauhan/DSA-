gfg
//here. no of unique is asked.

 int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> freq;
        for(int i:a){
            freq[i]++;
        }
        for(int j:b){
            freq[j]++;
        }
        return freq.size();
    }
    
