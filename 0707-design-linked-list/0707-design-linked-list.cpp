class Node{
    public:
    int val;
    Node* next;
    
    Node(int val){
        this->next = nullptr;
        this->val = val;
    }
};

class MyLinkedList {
    
    Node* head;
public:
    MyLinkedList() {
        head=nullptr;
    }
    
    int get(int index) {
        if(head==nullptr) return -1;
        int count=0;
        Node* pos=head;
        while(pos->next && count<index){
            count++;
            pos=pos->next;
        }
        
        if(count<index) return -1;
        
        return pos->val;
        
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val);
        new_node->next=head;
        head=new_node;
    }
    
    void addAtTail(int val) {
        Node* new_node = new Node(val);
        if(head==nullptr){
            head=new_node;
            return;
        }
        Node* pos=head;
        while(pos->next){
            pos=pos->next;
        }
   
           pos->next=new_node;   
    }
    
    void addAtIndex(int index, int val) {
        if(head==nullptr && index>0) return;
       if(head==nullptr || index==0){
           addAtHead(val);
           return;
       }
        
       if(head->next==nullptr && index==1){
           addAtTail(val);
           return;
        }
        if(head->next==nullptr && index>1){
            return;
        }
        
        int count=0;
        Node* pos = head;
        while(count<index-1 && pos->next){
            count++;
            pos=pos->next;
        }
        
        if(count<index-1) return;
        Node* new_node = new Node(val);
        new_node->next=pos->next;
        pos->next=new_node;
        
    }
    
    void deleteAtIndex(int index) {
        if(head==nullptr) return;
        if((head->next==nullptr && index==0) || index==0){
            Node *p = head;
            head=head->next;
            delete p;
            return;
        }
        if(head->next==nullptr && index>0) return;
        
        int count=0;
        Node* pos=head;
        while(pos->next->next && count<index-1){
            count++;
            pos=pos->next;
        }
        
        if(count<index-1) return;
        Node* p = pos->next;
        pos->next=pos->next->next;
        delete p;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */