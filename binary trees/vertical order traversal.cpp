lc 987
Time Complexity: O(N * log2N * log2N * log2N) where N represents the number of nodes in the Binary Tree.

Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
Multiset Operations to insert overlapping nodes at a specific vertical and 
horizontal level also takes O(log2N) complexity.
Map operations involve insertion and retrieval of nodes with their vertical and level as their keys.
  Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).
Space Complexity: O(N + N/2) where N represents the number of nodes in the Binary Tree.

The map for storing nodes based on their vertical and level information occupies an additional space complexity of O(N) 
as it stores all N nodes of the Binary Tree.
The queue for breadth first traversal occupies a space proportional to the maximum level of the tree which can be O(N/2)
in the worst case of a balanced tree.

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes; //vertical,level,nodes
        queue<pair<TreeNode* , pair<int,int>>> todo; //this is the queue we have to maintain
        todo.push({root,{0,0}}); //we will push root, 0th vertical , 0th level
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode*  node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }

            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    }
};
