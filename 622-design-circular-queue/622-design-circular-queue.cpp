class MyCircularQueue {
public:
    int size;
    int *arr;
    int front;
    int rear;
    MyCircularQueue(int k) {
        size=k;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    bool isEmpty() {
        if(front==-1 && rear==-1) return true;
        return false;
        
    }
    
    bool enQueue(int value) {
        if(isFull())
        {   //  cout<<(front-1)%(size-1);
         
            return false;
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
        }
        else rear=(rear+1)%size;
        
        arr[rear]=value;
        cout<<front<<rear;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else front=(front+1)%size;
        return true;
        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else return arr[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return arr[rear];
        
    }
    
    bool isFull() {
        if((rear+1)%size==front)
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