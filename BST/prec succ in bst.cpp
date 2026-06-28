gfg


/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
void find(Node* root,int key , Node* &prec , Node* &succ){
    prec=nullptr;
    succ=nullptr;
    
    while(root){
        if(key< root->data){
            succ=root;
            root=root->left;
        }
        else if(key> root->data){
            prec=root;
            root=root->right;
        }
        else{
            //preceedor
            if(root->left){
                Node* temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                prec=temp;
            }
            
                if(root->right){
                    Node* temp=root->right;
                    while(temp->left){
                        temp=temp->left;
                    }
                    succ=temp;
                }
            break;
        }
    }
}
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* prec ;
        Node* succ;
        find(root,key,prec,succ);
        return {prec,succ};
    }
};
