coding ninja- naukri.com
tc-o(h) + o(h) + o(n)=o(n)
//height for left , height for right, normal traversal
sc-o(n)

 bool isLeaf(TreeNode<int> *root) {
        return !root->left && !root->right;
    }
//left boundary
void leftboundary(TreeNode<int> *root, vector<int> &res){
  TreeNode<int> *cur=root->left;
 while(cur){
     if(!isLeaf(cur)) res.push_back(cur->data);
     if(cur->left) cur=cur->left; // go to left and then add its value to ds
     else cur=cur->right; //if there is no left and it is not a leaf node then go to right
 }
}
//right boundary
void rightboundary(TreeNode<int> *root,vector<int> &res){
     TreeNode<int> *cur=root->right;
     vector<int> temp;
 while(cur){
     if(!isLeaf(cur)) temp.push_back(cur->data);
     if(cur->right) cur=cur->right; // go to left and then add its value to ds
     else cur=cur->left; //if there is no left and it is not a leaf node then go to right
 }
 for(int i=temp.size()-1;i>=0;i--){ //adding temp reverse krke
     res.push_back(temp[i]);

 }
}

//add leaves
void leaves(TreeNode<int> *root,vector<int> &res){
    if(isLeaf(root)){ //inorder traversal
    res.push_back(root->data);
    return;
    }
    if(root->left) leaves(root->left,res);
    if(root->right) leaves(root->right,res);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data); //if root is not leaf node then add
    leftboundary(root,res);
    leaves(root,res);
    rightboundary(root,res);
    return res;
  
}
