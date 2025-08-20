gfg
class Solution {
  public:
  void insert(int x , stack<int> &St){
      if(St.size()==0){
          St.push(x);
          
      }else{
          int a=St.top();
          St.pop();
          insert(x,St);
          St.push(a);
      }
  }
    void reverse(stack<int> &St) {
        // code here
        if(St.size()>0){
            int x=St.top();
            St.pop();
            reverse(St);
            insert(x,St);
        }
    }
};
