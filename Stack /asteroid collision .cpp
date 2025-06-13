
leetcode 
using stack - o(2n) sc 
tc- o(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int &a: asteroids){
            //collision condition : a is -ve and st.top is +ve
            while(!st.empty() && a<0 && st.top()>0){
                int sum=a+ st.top();

                if(sum<0){ //+ve will explode 
                    st.pop();
                }
                else if(sum>0){ //+ve will explode 
                    a=0; //to break the while loop
                }
                else{ //sum=0
                    st.pop(); 
                    a=0;
                }
 
            }
            if(a!=0){
                st.push(a);
            }
        }
        int s=st.size();
        vector<int> ans(s);
        int i=s-1;
        while(!st.empty()){
            ans[i]=st.top();
            st.pop();
            i--;
        }
        return ans;


    }
};


using vector :
tc- o(n)
  sc-o(n)
