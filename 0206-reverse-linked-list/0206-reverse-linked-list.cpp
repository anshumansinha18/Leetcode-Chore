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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        if(head->next->next==nullptr){
            ListNode* temp = head->next;
            head->next->next=head;
            head->next=nullptr;
            return temp;
        }
        
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=head->next->next;
        while(next!=nullptr){
            if(prev==head) prev->next=nullptr;
            curr->next = prev;
            
            prev=curr;
            curr=next;
            next=next->next;
        }
        
        curr->next=prev;
        return curr;
        
    }
};