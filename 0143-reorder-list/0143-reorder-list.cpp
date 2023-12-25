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
    
    ListNode* reverse(ListNode* head){
        if(head==nullptr && head->next==nullptr) return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* mid=slow->next;
        slow->next=nullptr;
        
        ListNode* second = reverse(mid);
        ListNode* i=head,*j=second;
        while(i&&j){
            ListNode* iNext=i->next;
            ListNode* jNext=j->next;
            
            j->next=iNext;
            i->next=j;
            
            i=iNext;
            j=jNext;
        }
        
        
    }
};