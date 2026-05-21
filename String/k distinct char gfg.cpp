gfg https://www.geeksforgeeks.org/dsa/count-number-of-substrings-with-exactly-k-distinct-characters/
brute 
class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<bool>map(26,false);
            int dist=0;
            
            for(int j=i;j<n;j++){
                if(map[s[j]-'a']==false){
                    map[s[j]-'a']=true;
                    dist++;
                }
                if(dist==k) ans++;
            }
            
        }
        return ans;
    }
};
