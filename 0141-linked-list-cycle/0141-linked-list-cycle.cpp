/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       
        if(head==nullptr) return false;
        if(head->next==nullptr) return false;
        
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        
        
        while(fast && fast->next && slow && fast!=slow){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return fast==slow;
          
    }
};