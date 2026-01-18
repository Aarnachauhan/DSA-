gfg
https://www.geeksforgeeks.org/problems/implement-stack-using-array/1


class myStack {
  public:
  int *arr;
  int front;
  int size;
  
    myStack(int n) {
        // Define Data Structures
        size=n;
        front=-1;
        arr=new int[n];
    }

    bool isEmpty() {
        // check if the stack is empty
        return front==-1;
    }

    bool isFull() {
        // check if the stack is full
        return front==size-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(front==size-1) return;
        else{
            front++;
            arr[front]=x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(front<0) return;
        else{
            front--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(front==-1) return -1;
        else{
            return arr[front];
        }
    }
};
