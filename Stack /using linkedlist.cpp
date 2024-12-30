 StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* newnode=new StackNode(x);
        newnode->next=top;
        top=newnode;
    }

    int pop() {
        // code here
        if(top==nullptr) return -1;
        int element=top->data;
        top=top->next;
        return element;
    }

    MyStack() { top = NULL; }
};
