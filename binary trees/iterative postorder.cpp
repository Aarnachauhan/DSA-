gfg

note:
we are reversing as we pop the node from the stack and add it to the ans. before adding the right child. 
  we are adding root so the pattern was root-right-left.
  we reverse it to bring it to the order left-right-root
  
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*> s;
        vector<int> ans;
        s.push(node);
        
        while(!s.empty()){
            Node* temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            
            if(temp->left!=nullptr) s.push(temp->left);
            if(temp->right!=nullptr) s.push(temp->right);
        }
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};
