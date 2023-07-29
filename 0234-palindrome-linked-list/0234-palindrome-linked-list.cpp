/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void insertAtHead(ListNode* &head, int data){
        ListNode* new_node = new ListNode(data);
        new_node->next=head;
        head=new_node;
    }
    
    ListNode* reverseList(ListNode* head){
        
        ListNode* newList = nullptr;
        while(head!=nullptr){
            insertAtHead(newList, head->val);
            head=head->next;
        }
        
        return newList;
    }
    
   
    bool isPalindrome(ListNode* head) {
        
        ListNode* revHead = reverseList(head);
        
        
        while(head!=nullptr){
            cout<<head->val<<" "<<revHead->val<<endl;
            if(head->val!=revHead->val)
                return false;
            head=head->next;
            revHead=revHead->next;
        }
        
        return true;
    }
};