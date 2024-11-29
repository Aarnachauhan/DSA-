//on leetcode we dont have to remove leading zeros
class Solution {
public:
    string addBinary(string a, string b) {
        int count1s=0;
        int i=a.size()-1;
        int j=b.size()-1;
        string ans="";
        int carry=0;
        while (i>=0 || j>=0){
           int count1s=0;
           if(i>=0 && a[i]=='1') count1s++;
           if(j>=0 && b[j]=='1') count1s++;

           if(count1s+carry==0){
            ans+='0';
            carry=0;
           }
           else if(count1s+carry==1){
            ans+='1';
            carry=0;
           }
           else if(count1s+carry==2){
            ans+='0';
            carry=1;
           }
          else if(count1s+carry==3){
            ans+='1';
            carry=1;
           }
           i--;
           j--;
        }
         if(carry==1){ //if carry =1 is left then simply put it in ans
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
       
      //to remove the leading 0s
         //i=0; 
        //while(ans[i]=='0'){
          //  ans.erase(0,1); 
            //(0,1) 0 is the index and 1 is the length of element to be removed
       // }
        
        return ans;

    }
};
