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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* tail=head;
        ListNode* dummy=new ListNode();
        ListNode* prev=dummy;
        int count=1;
        while(head && tail){
           
            tail=tail->next;
            count++;
            
            if(count==k && tail){
                ListNode* next=tail->next;
                tail->next=nullptr;
                reverseList(head);
                prev->next=tail;
                head->next=next;
                prev=head;
                head=next;
                tail=next;
                count=1;
            }
            
        }
        return dummy->next;
    }
};