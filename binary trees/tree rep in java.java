Understanding ArrayList and get()
ArrayList:

An ArrayList in Java is a resizable array implementation of the List interface. It allows you to store a dynamic list of elements, which can be accessed by their index.
The indices in an ArrayList are zero-based, meaning that the first element is at index 0, the second element is at index 1, and so on.
The get(int index) Method:

The get(int index) method is used to retrieve the element at the specified index from the ArrayList.
For example:
v.get(0) retrieves the first element.
v.get(1) retrieves the second element.
v.get(2) retrieves the third element, and so forth.

//User function Template for Java
// class Node{
//     int data;
//     Node left,right;
//     Node(int n){
//         data=n;
//         left=right=null;
//     }
// }
class Solution{
    public static void createTree(Node root, ArrayList<Integer> v ){
        //root= new Node(v.get(0));
        root.left= new Node(v.get(1));
        root.right= new Node(v.get(2));
        root.left.left= new Node(v.get(3));
        root.left.right= new Node(v.get(4));
        root.right.left= new Node(v.get(5));
        root.right.right= new Node(v.get(6));
    }
}
