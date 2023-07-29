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
    
    void deleteHead(ListNode* &head, ListNode* &temp){
        if(head==nullptr) return;
        ListNode* t = head;
        head=head->next;
        delete t;
        temp=head;
    }
    
    void deleteEnd(ListNode* &head, ListNode* &prev){
        if(head==nullptr) return;
        delete prev->next;
        prev->next=nullptr;
    }
    void deleteMiddle(ListNode* &head, ListNode* &prev, ListNode* &temp){
        ListNode* t=prev->next;
        prev->next=prev->next->next;
        delete t;
        temp=prev->next;
    }
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp!=nullptr){
            if(temp->val==val){
                //if val is present at head
                // prev=temp;
                if(head==temp){
                    deleteHead(head, temp);
                }else if(temp->next==nullptr){
                    deleteEnd(head, prev);
                    temp=nullptr;
                }else{
                    deleteMiddle(head, prev, temp);
                }
            }
            else{
                 prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};