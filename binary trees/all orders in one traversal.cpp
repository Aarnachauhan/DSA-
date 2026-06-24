codechef compiler


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

vector<vector<int>> allTraversals(TreeNode *root) {

    vector<int> pre, in, post;

    if (root == NULL)
        return {pre, in, post};

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {

        auto it = st.top();
        st.pop();

        if (it.second == 1) {

            pre.push_back(it.first->val);

            it.second++;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2) {

            in.push_back(it.first->val);

            it.second++;
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else {

            post.push_back(it.first->val);
        }
    }

    return {pre, in, post};
}

int main() {

    /*
            1
          /   \
         2     3
        / \
       4   5
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> ans = allTraversals(root);

    cout << "Preorder: ";
    for (int x : ans[0])
        cout << x << " ";
    cout << "\n";

    cout << "Inorder: ";
    for (int x : ans[1])
        cout << x << " ";
    cout << "\n";

    cout << "Postorder: ";
    for (int x : ans[2])
        cout << x << " ";
    cout << "\n";

    return 0;
}
