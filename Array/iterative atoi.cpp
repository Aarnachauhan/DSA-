gfg 
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i=0;
        int sign=1;
        long ans=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='+' || s[i]=='-'){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        while(s[i]>='0' && s[i]<='9'){
        ans=ans*10+ (s[i]-'0'); // this converts s[i] from string to int
        if(sign*ans>=INT_MAX) return INT_MAX;
         if(sign*ans<=INT_MIN) return INT_MIN;      
           i++; 
        }
        return (int)sign*ans;
        
    }
};
