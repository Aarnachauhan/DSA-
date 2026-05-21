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

optimal
class Solution {
  public:
 int count(string & s , int k){
     int n=s.length();
     int ans=0;
     vector<int> freq(26,0);
     int dist=0;
     int i=0;
     for(int j=0;j<n;j++){
         freq[s[j]-'a']++;
         if(freq[s[j]-'a']==1) dist++;
         
         while(dist>k){
             freq[s[i]-'a']--;
             if(freq[s[i]-'a']==0) dist--;;
             i++;
         }
         
         ans+=j-i+1;
     }
     return ans;
 }
    int countSubstr(string& s, int k) {
        // code here
        int n=s.length();
        int ans=0;
        ans=count(s,k)-count(s,k-1);
        return ans;
    }
};
