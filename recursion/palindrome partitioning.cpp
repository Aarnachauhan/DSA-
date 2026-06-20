lc 131
tc-o(n*2^n)


class Solution {
public:
bool ispalind(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s==s2;
}
void f(vector<vector<string>>&ans , vector<string> &partitions , string s){
   if(s.size()==0){
    ans.push_back(partitions);
    return;
   }

   for(int i=0;i<s.size();i++){
      string part=s.substr(0,i+1);

      if(ispalind(part)){
        partitions.push_back(part);
        f(ans,partitions,s.substr(i+1));
        partitions.pop_back();
      }
   }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> partitions;
        f(ans,partitions, s);
        return ans;
    }
};
