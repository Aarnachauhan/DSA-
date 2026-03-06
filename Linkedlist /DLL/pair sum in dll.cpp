gfg
brute: hashing 
tc-o(nlogn) 
sc-o(N)
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        unordered_map<int, Node*> vis;
        Node *curr=head;
        while(curr!=nullptr){
            int x=target-curr->data;
            if(vis.find(x)!=vis.end()){
                ans.push_back({x,curr->data});
            }
            vis[curr->data]=curr;
            curr=curr->next;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

optimal : two pointers
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        Node *first=head;
        Node *second=head;
        
        //move second to the end
        while(second->next!=nullptr){
            second=second->next;
        }
        
        bool found=false;
        //second->next==first : crossed each other
        //first!=second : became same
        while(first!=second && second->next!=first){
            if((first->data + second->data)==target){
                found=true;
                ans.push_back({first->data , second->data});
                first=first->next;
                second=second->prev;
                
            }
            else if((first->data + second->data)<target){
                first=first->next;
            }
            else{
                second=second->prev;
            }
        }
     return ans;
    }
};
