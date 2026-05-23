https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475?leftPanelTabValue=PROBLEM

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    //Write your code here
     Node* top=nullptr;
     int size=0;
public:
    Stack()
    {
        //Write your code here
    }

    int getSize()
    {
        //Write your code here
        return size;
    }

    bool isEmpty()
    {
        //Write your code here
        return size==0 ? true: false;
    }

    void push(int data)
    {
        //Write your code here
        Node* temp=new Node(data);
        temp->next=top;
        top=temp;
        size++;
    }

    void pop()
    {
        //Write your code here
        if(isEmpty()) return;
        Node* temp=top;
        top=top->next;
        delete temp;
        size--;
    }

    int getTop()
    {
        //Write your code here
        if(isEmpty()) return -1;
        return top->data;
    }
};
