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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* dummy = new ListNode(-101);
        dummy->next= head;
        
        ListNode* curr=head;
        ListNode* prev=dummy;
        ListNode* next=head->next;
        
        while(curr){
            if(curr->val==prev->val){
                prev->next=next;
            }else{
                prev=curr;
            }
            curr=next;
            if(next) next=next->next;
            
        }
        
        return dummy->next;
    }
};