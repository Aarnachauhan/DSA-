Intuition
we need a variable to store minimum element. but comparison will be done at the time of push and pop.

Approach
we will take long long as the values can be very large.
PUSH OPERATION
if the stack is empty we can directly push the value and update the mini.
if the stack is not empty then we have to first check if the value is lesser than or greater than mini.

lesser than mini.
in this case we will we will modify the value by the formula .
Intuition behind the formula:
value-mini<0
add value to both the sides
2value-mini<value , push the modified value
then mini will be updated to original value, not modified.

greater than mini
push it into the stack

POP OPERATION
if the stack is empty , return;
else , store the top value of the stack.and pop.
if the value is lesser than mini then it is modified value and we need update the mini to second smallest number.

TOP OPERATION
store top value in x . if the x is smaller than mini, then return mini as it is the top value.

else, return x;

LONG-LONG KI KAHANI
long long val2=(long long ) val; 
as the values can be very large. we have to convert it from INT to LONG LONG

   st.push(long(2*val2*1LL)-mini);
here mini is long long and val2 also, we need multiplied value to be same
1LL will use 64 bit operations.

as 2val2-mini will be small, we can make it long instead of long long.

source code:
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
