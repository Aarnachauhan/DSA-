class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(n>m) return "";

        unordered_map<char,int> mp;
        //we are storing the characters of t in map
        for(char &ch:t){
          mp[ch]++;
        }

        int count=n;
        int i=0,j=0;

        int min_size=INT_MAX;
        int start_i=0;

        while(j<m){
            char ch=s[j];
            if(mp[ch]>0){ //we need this one in our window 
                count--;
            }
            mp[ch]--; //even if we need or not need , we will decrement.
            while(count==0){
                int current_windowsize=j-i+1;
                if(min_size>current_windowsize){
                    min_size=current_windowsize;
                    start_i=i;
                }
                mp[s[i]]++; //jab i aage jayega toh +1 krna hai 
                if(mp[s[i]]>0){ //we removed it and now we want it
                    count++;
                }
                i++;

            }
            j++;
        }

       return min_size==INT_MAX ?  "" : s.substr(start_i,min_size);
    }
};
