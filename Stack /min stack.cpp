lc 155
tc- O(1)
class MinStack {
public:
        stack<long long >st;
        long long mini;
    MinStack() {
      
    }
    
    void push(int val) {
        long long val2=(long long ) val;
        if(st.empty()){
            mini=val2;
            st.push(val2);
        }else{
            if(val2>mini){
                st.push(val2);
            }else{ //val 2 chota hai mini se toh hum real value nhi push karenge
                st.push(long(2*val2*1LL)-mini);
                mini=val2;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long x=st.top();
        st.pop();
        if(x<mini){ // that means x is not a real value, its modified
         mini=(2*mini)-x; //new mini 
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long x=st.top();
        if(mini<x){
            return x;
        }else{
            return mini;
        }
        
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
