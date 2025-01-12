void insert_correct_position(int x, stack<int> &s){
 if(s.size()==0  || s.top()<x ){
     s.push(x);
 } else{
     int a=s.top();
     s.pop();
     insert_correct_position(x,s);
     s.push(a);
 }   
}
void reverse(stack <int> &s){
if(s.size()>0){
    int x=s.top();
    s.pop();
    reverse(s);
    insert_correct_position(x,s);
}

}

void SortedStack :: sort()
{
   //Your code here
   reverse(s);
}
