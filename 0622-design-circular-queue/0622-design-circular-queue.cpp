class Node{
  public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
    }
};

class MyCircularQueue {
    Node* head;
    Node* tail;
    int capacity;
    int size;
public:
    
    MyCircularQueue(int k) {
        size=0;
        this->capacity=k;
        head=nullptr;
        tail=nullptr;
    }
    
    bool enQueue(int value) {
       if(size<capacity){
           Node* new_node = new Node(value);
           if(head==nullptr){
               head=new_node;
               tail=new_node;
               head->next=head;
           }else{
               tail->next=new_node;
               tail=tail->next;
               tail->next=head;
           }
           size++;
           return true;
       }   else return false;
    }
    
    bool deQueue() {
        if(size==0){
            return false;
        }
        
        if(head==tail){
            delete head;
            head=nullptr;
            tail=nullptr;
        }else{
            Node* p = head;
            head=head->next;
            tail->next=head;
            delete p;
        }
        size--;
        return true;
    }
    
    int Front() {
        if(size==0) return -1;
        
        return head->val;
    }
    
    int Rear() {
        if(size==0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(size==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(size==capacity) return true;
        else return false;
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