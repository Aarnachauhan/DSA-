
leetcode 
using stack - o(2n) sc 
tc- o(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int x : asteroids) {

            bool alive = true;

            while (alive && !st.empty() && st.top() > 0 && x < 0) {

                if (st.top() < -x) {
                    st.pop();               // stack asteroid dies
                }
                else if (st.top() == -x) {
                    st.pop();               // both die
                    alive = false;
                }
                else {
                    alive = false;          // current dies
                }
            }

            if (alive)
                st.push(x);
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};



using vector :
tc- o(n)
  sc-o(n)
    class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int &a: asteroids){
            //collision condition : a is -ve and last element of the vector is +ve
            while(!st.empty() && a<0 && st.back()>0){
                int sum=a+ st.back();

                if(sum<0){ //+ve will explode 
                    st.pop_back();
                }
                else if(sum>0){ //+ve will explode 
                    a=0; //to break the while loop
                }
                else{ //sum=0
                    st.pop_back(); 
                    a=0;
                }
 
            }
            if(a!=0){
                st.push_back(a);
            }
        }

       return st;
    }
};
