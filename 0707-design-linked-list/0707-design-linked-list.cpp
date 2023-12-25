class Node{
     public: 
     
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=nullptr;
    }
};

class MyLinkedList {
public:
    
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        Node* newNode = new Node(-1);
        head=newNode;
        Node* lastNode = new Node(-1);
        head->next=lastNode;
        tail=lastNode;
        size=0;
    }
    
    void print(Node* curr){
        while(curr){
            cout<<curr->val<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    
    int get(int index) {
        
        Node* curr=head;
     
        for(int i=0;i<index && curr;i++){
            curr=curr->next;
        }
        
        if(curr->next==nullptr || curr==nullptr) return -1;
        return curr->next->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
        // print(head);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
        // print(head);
    }
    
    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        Node* curr=head;
        for(int i=0;i<index && curr;i++){
            curr=curr->next;
        }
  
        if(curr==tail || curr==nullptr) return;
        
        Node* next=curr->next;
        curr->next=newNode;
        newNode->next=next;
        size++;
        // print(head);
    }
    
    void deleteAtIndex(int index) {
        Node* curr=head;
        for(int i=0;i<index && curr;i++){
            curr=curr->next;
        }
        
        if(curr==nullptr || curr->next==tail || curr==tail) return;
        
        curr->next=curr->next->next;
        size--;
        // print(head);
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