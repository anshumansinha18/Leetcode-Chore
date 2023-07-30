class Node{
public:
    int data;
    int value;
    Node* prev;
    Node* next;

    Node(int data, int value){
        this->data = data;
        this->value=value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


class LRUCache {
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> m;
    int curr_size;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head=nullptr;
        this->tail=nullptr;
        curr_size=0;
    }

    int get(int key) {

        if(m.find(key)==m.end()){
            return -1;
        }
        // cout<<"x1";

        Node *p = m[key];
        int result=p->data;
        int val = p->value;
        deleteNode(head, tail, p);
        insertAtHead(head, tail, result, val);
        m[key]=head;
        return val;
    }

    void put(int key, int value) {
        if(curr_size<capacity){
            if(m.find(key)!=m.end()){
                deleteNode(head, tail, m[key]);
            }
            else curr_size++;
        }else{
             if(m.find(key)!=m.end()){
                deleteNode(head, tail, m[key]);
            }else{
            m.erase(tail->data);
            deleteNode(head, tail, tail);
             }

        }
        insertAtHead(head, tail, key, value);
        m[key] = head;
    }

    void insertAtHead(Node* &head,Node* &tail, int data, int value){
        Node* new_node = new Node(data, value);
        new_node->next=head;
        if(head) head->prev=new_node;
        head=new_node;
        if(tail== nullptr) tail=head;
    }
    void deleteNode(Node* &head, Node* &tail, Node* p){
        if(p== nullptr) return;

        Node* x = p->prev;
        Node* y = p->next;
        if(p==head) head=head->next;
        if(p==tail) tail=tail->prev;
        if(x) x->next=y;
        if(y) y->prev=x;
        delete p;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */