lc 450

recursive:
class Solution {
public:

    TreeNode* findMin(TreeNode* root){
        while(root->left)
            root = root->left;

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr)
            return nullptr;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }

        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }

        else{

            // Case 1 & 2
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3
            TreeNode* successor = findMin(root->right);

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};

iterative:
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) return helper(root);

        TreeNode* dummy = root;
        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
     TreeNode* helper(TreeNode* root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (!root->right) return root;
        return findLastRight(root->right);
    }
};
