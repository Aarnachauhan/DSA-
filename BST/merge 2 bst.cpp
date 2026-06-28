gfg

brute force: 
tc-O(m+n)
sc-o(n+m)

approach:
BST1 → vector

BST2 → vector

merge

class Solution {
  public:
 void inorder(Node *root, vector<int> &v){
     if(root==nullptr) return;
     inorder(root->left,v);
     v.push_back(root->data);
     inorder(root->right,v);
 }
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> a,b;
        inorder(root1,a);
        inorder(root2,b);
        
        
        vector<int> ans;
        int i=0, j=0;
        
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                ans.push_back(a[i++]);
            }
            else{
                ans.push_back(b[j++]);
            }
        }
        while(i<a.size()){
            ans.push_back(a[i++]);
        }
        while(j<b.size()){
            ans.push_back(b[j++]);
        }
        return ans;
    }
};


optimal:
tc-Time = O(m + n)
sc- O(logn + logm ) for bst
for skewed : o(m+n)
class Solution {
  public:
  
 void pushleft(Node* root, stack<Node*> &st){
     while(root){
         st.push(root);
         root=root->left;
     }
}
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> ans;
        
        stack<Node*> st1;
        stack<Node*> st2;
        
        //push all left nodes
        pushleft(root1,st1);
        pushleft(root2,st2);
        
        while(!st1.empty() || !st2.empty()){
            stack<Node*> st;
            if(st1.empty()){
                Node* curr=st2.top();
                st2.pop();
                ans.push_back(curr->data);
                pushleft(curr->right,st2);
            }
            else if(st2.empty()){
                Node* curr=st1.top();
                st1.pop();
                ans.push_back(curr->data);
                pushleft(curr->right,st1);
            }
            else{
                if(st1.top()-> data <=st2.top()->data){
                    Node* curr=st1.top();
                    st1.pop();
                    ans.push_back(curr->data);
                    pushleft(curr->right,st1);
                }
                else{
                    Node* curr=st2.top();
                    st2.pop();
                    ans.push_back(curr->data);
                    pushleft(curr->right,st2);
                }
            }
        }
        
        
       return ans; 
    }
};
