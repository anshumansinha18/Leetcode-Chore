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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = new ListNode(-1);
        ListNode* right=head;
        left->next=head;
    
        while(n-- && right){
            right=right->next;
        }
        
        while(right){
            right=right->next;
            left=left->next;
        }
        
        ListNode *t = left->next;
        left->next = left->next->next;
        if(t==head) head=left->next;
        delete t;
        return head;
    }
};