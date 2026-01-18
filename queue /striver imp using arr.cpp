class myQueue {
    int* arr;
    int size;
    int front;
    int rear;

public:
    myQueue(int n) {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};
