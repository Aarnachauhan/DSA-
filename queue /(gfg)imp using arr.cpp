// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    
    // Your Code
    if(rear==100005){
        return;
    }else{
        arr[rear]=x;
        rear++;
    }
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    // Your Code
    if(front==rear){
        return -1;
    }else{
        int ans=arr[front];
        arr[front]=-1;
        front++;
        if(front==rear){ //matlab ek hi element hai 
            front=0;
            rear=0;
        }
        return ans; 
    }
}
