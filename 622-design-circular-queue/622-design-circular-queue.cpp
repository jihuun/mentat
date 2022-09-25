class MyCircularQueue {
    vector<int> arr;
    int size;
    int front;
    int rear;
    
public:
    MyCircularQueue(int k) {
        size = k + 1;
        arr = vector<int>(size, 0);
        front = 0;
        rear = 0;
    }
    
    /*
    f
    o o 2 5
          r     
    */
    bool enQueue(int value) {
        if (isFull())
            return false;
        /* insert it after increasing rear */
        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return arr[(front + 1) % size];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
    
    /*
    f  // empty f == r
    o o o o
    r
    */
    bool isEmpty() {
        if (front == rear)
            return true;
        return false;
    }
    
    /*  full: f == (r+1) % size
      f
    o 2 5 3
    r     
    */
    bool isFull() {
        if (front == (rear + 1) % size)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */