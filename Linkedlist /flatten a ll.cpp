gfg
Time Complexity  → O(N²) worst case
Space Complexity → O(N) recursion stack

class Solution {
  public:
 Node* merge(Node * list1 , Node* list2){
     if(list1==nullptr) return list2;
     if(list2==nullptr) return list1;
     
     if(list1->data < list2->data){
         list1->bottom = merge(list1->bottom , list2);
         return list1;
     }
     else{
         list2->bottom=merge(list2->bottom, list1);
         return list2;
     }
 }
    Node *flatten(Node *root) {
        // code here
        if(root==nullptr || root->next==nullptr) return root;
        
        Node* mergedhead=flatten(root->next);
        
        return merge(root,mergedhead);
    }
};
