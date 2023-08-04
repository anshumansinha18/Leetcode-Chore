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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        
        ListNode* curr=head;
        ListNode* prev=dummy;
        ListNode* next;
        
        while(curr && curr->next){
            next=curr->next;
            if(curr==head) head=next;
            curr->next=next->next;
            prev->next=next;
            next->next=curr;
            prev=curr;
            curr=curr->next;
        }
        
        return head;
    }
};