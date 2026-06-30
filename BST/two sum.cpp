lc 653

brute force:
tc-o(n)
sc-o(n)

class Solution {
public:
void inorder(TreeNode* root , vector<int> &ans){
    if(root==nullptr) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int i=0 , j=ans.size()-1;
        while(i<j){
           int sum=ans[i]+ans[j];
           if(sum==k) return true;
           else if(sum<k){
            i++;
           }
           else j--;
        }
        return false;
    }
};

hashset

Time O(n)
Space O(n)
class Solution {
public:

    unordered_set<int> s;

    bool dfs(TreeNode* root,int k){

        if(root==NULL)
            return false;

        if(s.count(k-root->val))
            return true;

        s.insert(root->val);

        return dfs(root->left,k) || dfs(root->right,k);
    }

    bool findTarget(TreeNode* root,int k){

        return dfs(root,k);
    }
};



most optimised :
tc-o(n)
sc-o(h) + o(h)= o(h)
class BSTITERATOR {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTITERATOR(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);

            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (reverse)
            pushAll(node->left);
        else
            pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTITERATOR left(root, false); //smallest iterator
        BSTITERATOR right(root,true); //largest iterator

        int i=left.next();
        int j=right.next();
        while(i<j){
            int sum=i+j;
            if(sum==k) return true;
            if(sum<k){
                i=left.next();
            }
            else{
                j=right.next();
            }

        }
       return false;
    }
};
