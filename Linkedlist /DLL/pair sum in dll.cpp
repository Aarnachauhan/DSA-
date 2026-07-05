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
tc-o(n)
sc-o(1)
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        if(head==nullptr) return ans;
        Node* left=head;
        Node* right=head;
        
        while(right->next!=nullptr){
            right=right->next;
        }
        
        while(left!=right && right->next!=left){
            int sum=left->data + right->data;
            if(sum==target){
                ans.push_back({left->data , right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum>target){
                right=right->prev;
            }
            else left=left->next;
        }
        return ans;
    }
};
