/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, int> m1;
        unordered_map<int, Node*> m2;
        int count=0;
        Node* temp = head;
        Node* new_head = nullptr;
        Node* tail = nullptr;
        while(temp){
            m1[temp]=count;
            
            Node* new_node = new Node(temp->val);
            m2[count]=new_node;
            
            if(new_head==nullptr){
                new_head=new_node;
            }
            else tail->next=new_node;
            tail=new_node;
            
         count++;
            temp=temp->next;
        }
        
        temp=new_head;
        Node* temp2=head;
        while(temp){
            if(temp2->random==nullptr) temp->random=nullptr;
            else temp->random = m2[m1[temp2->random]];
            
            temp2=temp2->next;
            temp=temp->next;
        }
        
       return new_head;
    }
};