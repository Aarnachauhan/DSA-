naukri.com
problem name : path in a tree



bool path(TreeNode<int> *root , vector<int> &arr, int x){
	if(!root){
		return false;
	}
	arr.push_back(root->data);
	if(root->data==x) return true;

	if(path(root->left , arr, x) || path(root->right,arr,x)) return true;

	arr.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> arr;
	if(root==nullptr) return arr;
	path(root,arr,x);
}
