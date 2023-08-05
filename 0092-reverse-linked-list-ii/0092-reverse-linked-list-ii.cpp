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
    ListNode* reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr){
            ListNode* ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        head=prev;
        return head;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy=new ListNode();
        dummy->next=head;
        
        ListNode* l=head;
        ListNode* r=head;
        int count=1;
        while(r && count<right){
            if(count<left)
                l=l->next;
            if(count<right)
                r=r->next;
            count++;
        }
        
        ListNode* prev=dummy;
        while(prev->next!=l)
            prev=prev->next;
        ListNode* right_next=r->next;
        
        r->next=nullptr;
        ListNode* reversedHead= reverseList(l);    
        
        if(prev->next==head){
            head=reversedHead;
        }
        prev->next=reversedHead;
   
        l->next = right_next;
        return head;
    }
};