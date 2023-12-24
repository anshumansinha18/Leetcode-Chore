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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next=head;
        ListNode* curr = head;
        ListNode* next=head->next;
        ListNode* prev=dummy;
        
        while(curr){
            if(curr->val==val)
                prev->next=next;
            else{
                prev=curr;
            }
            curr=next;
            if(next) next=next->next; 
        }
        
        return dummy->next;
    }
};