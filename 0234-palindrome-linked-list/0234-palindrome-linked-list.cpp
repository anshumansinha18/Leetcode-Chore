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
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=head->next;
        
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next) next=next->next;
        }
        
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* rev=reverse(slow);
        
        while(head && rev){
            if(head->val!=rev->val) return false;
            head=head->next;
            rev=rev->next;
        }
      
        return true;
    }
};