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
    
    ListNode *findMid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        while(head){
            ListNode* ahead=head->next;
            head->next=prev;
            prev=head;
            head=ahead;
        }
        head=prev;
        return head;
    }
    int pairSum(ListNode* head) {
           ListNode* mid=findMid(head);
        int res=0;
        ListNode* end = reverseList(mid);
        ListNode* start=head;
        
        while(end){
            res=max(start->val+end->val, res);
            start=start->next;
            end=end->next;
        }
        return res;
        
    }
};