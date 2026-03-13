gfg
i was using hashmap and it failed at 1110/1117

  
class Solution {
  public:
  int atmost(string s, int k){
      if(k<0) return 0;
      vector<int> freq(26,0);
      int left=0, count=0, dis=0;
      
      for(int right=0;right<s.size();right++){
          if(freq[s[right]-'a']==0) dis++;
          freq[s[right]-'a']++;
          
          while(dis>k){
              freq[s[left]-'a']--;
              if(freq[s[left]-'a']==0) dis--;
              left++;
          }
          count+=right-left+1;
      }
      return count;
  }
    int countSubstr(string& s, int k) {
        // code here
        return atmost(s,k) - atmost(s,k-1);
    }
};
