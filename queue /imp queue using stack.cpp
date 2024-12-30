void MyQueue:: push(int x)
{
        // Your Code
        if(front==nullptr){ //queue is empty
            QueueNode *newnode=new QueueNode(x);
            front=newnode;
            rear=newnode;
        }else{
            QueueNode *newnode=new QueueNode(x);
            rear->next=newnode;
            rear=newnode;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code   
        if(front==nullptr){ //queue is empty
            return -1;
        }else{
            QueueNode *ptr=front;
            front=front->next;
            int ele=ptr->data;
            delete ptr;
            return ele;
        }
}
