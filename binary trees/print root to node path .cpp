naukri.com
problem name : path in a tree


bool solve(TreeNode<int> *root, int x, vector<int> &path){
	if(root==nullptr) return false;
	path.push_back(root->data);

	if(root->data==x) return true;
    if(solve(root->left,x,path)) return true;
	if(solve(root->right,x,path)) return true;

	path.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> path;
	solve(root,x,path);
	return path;
}
