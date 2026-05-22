gfg 

my code  
class Solution {
  public:
  
 int count(Node* curr , int cnt){
     if(curr->next==nullptr) return cnt;
     return count(curr->next,cnt+1);
       
 }
    int getCount(Node* head) {
        // Code here
        if(head==nullptr) return 0;
        Node* curr=head;
        int ans=count(curr,1);
        return ans;
    }
};

cleaner code :
class Solution {
  public:

    int getCount(Node* head) {

        if(head == nullptr)
            return 0;

        return 1 + getCount(head->next);
    }
};


