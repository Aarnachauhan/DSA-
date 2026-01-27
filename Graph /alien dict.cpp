gfg
class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        unordered_map<char,vector<char>> ad;
        unordered_map<char,int> ind;
        for(auto & w:words){ //suppose we have baa
            for(char &ch:w){ //ch=b
                ind[ch]=0;
            }
        }
        for(int i=1;i<n;i++){
            string &w1=words[i-1]; //using & means both referes to same memory location , no new string is created . changes in words[i-1] will lead to change in w1 
            string &w2=words[i];
            int l=0, r=0;
            
            while(l<w1.size() && r<w2.size()){
                if(w1[l]!=w2[r]){
                    ad[w1[l]].push_back(w2[r]);
                    ind[w2[r]]++;
                    break;
                }
                l++;
                r++;
            }
           if(l<w1.size() && r==w2.size()){
               return "";
           }
        }
        queue<char> q;
        for(auto & it:ind){
            if(it.second==0){
                q.push(it.first);
            }
        }
        
        string s="";
        while(!q.empty()){
            char node = q.front();
            s+=node;
            q.pop();
            for(auto& it:ad[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(s.size()!=ind.size()){
            return "";
        }
        return s;

    }
};
