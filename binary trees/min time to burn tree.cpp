gfg

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  map<Node* , Node*> parentmapping(Node* root){
      map<Node* , Node*> mp;
      mp[root]=nullptr;
      queue<Node*> q;
      q.push(root);
      while(!q.empty()){
          Node* node=q.front();
          q.pop();
          
          if(node->left){
              mp[node->left]=node;
              q.push(node->left);
          }
          if(node->right){
              mp[node->right]=node;
              q.push(node->right);
          }
      }
      return mp;
  }
  Node* getTarget(Node* root, int target){
      if(!root) return nullptr;
      if(root->data== target) return root;
      
      Node* l = getTarget(root->left,target);
      if(l) return l;
      Node* r=getTarget(root->right,target);
      if(r) return r;
      
      return nullptr;
  }
  
  int burnTree(Node* root , Node* tnode, map<Node* , Node*> mp){
      map<Node* , bool> burned;
      queue<Node*> q;
      q.push(tnode);
      burned[tnode] = true;  
      int tm=0;
      while(!q.empty()){
          int size=q.size();
          bool flag=false;
          while(size--){
              Node* node= q.front();
              q.pop();
              
             
              if(mp[node] and !burned[mp[node]]){
                  q.push(mp[node]);
                 burned[mp[node]]=true;
                flag = true;
                 
              }
              if(node->left and !burned[node->left]){
                  q.push(node->left);
                  burned[node->left] = true;
                  flag=true;
              }
              if(node->right and !burned[node->right]){
                  q.push(node->right);
                  burned[node->right] = true;
                  flag=true;
              }
          }
        if(flag) tm++;
      }
      return tm;
  }
    int minTime(Node* root, int target) {
        // code here
        Node* tnode=getTarget(root,target);
        map<Node*,Node*> mp=parentmapping(root);
        return burnTree(root,tnode,mp);
    }
};
