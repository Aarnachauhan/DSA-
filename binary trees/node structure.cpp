struct node {
  int data;
  struct node *left;
  struct node *right;
};

Struct Definition: This defines a structure named node that represents a single node in a binary tree.
int data: This member variable holds the value of the node.
struct node *left: This is a pointer to the left child of the node.
It allows the node to point to another node structure that represents its left child.
struct node *right: This is a pointer to the right child of the node, similar to the left child.


struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node)); //malloc occupies the memeory for the new node

  node->data = data;

  node->left = NULL; //this allocates a pointer to null
  node->right = NULL; //same as above
  return (node);
}

Function to Create a New Node:
struct node *newNode(int data): This function takes an integer data as an argument and returns a pointer to a newly created node.
malloc(sizeof(struct node)): This allocates memory for a new node structure. malloc is a standard library function 
in C that allocates a specified number of bytes and returns a pointer to the allocated memory.
node->data = data;: This assigns the value passed to the function (data) to the data member of the newly created node.
node->left = NULL; and node->right = NULL;: These lines initialize the left and right child 
pointers to NULL, indicating that the new node does not have any children yet.

return (node);: Finally, the function returns a pointer to the newly created node

