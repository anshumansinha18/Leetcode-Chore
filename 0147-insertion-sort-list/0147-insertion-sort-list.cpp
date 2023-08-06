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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        
        ListNode* p=head->next;
        ListNode* tail=head;
        while(p){
          
           ListNode* curr=dummy->next;
           ListNode* prev=dummy;
        
           while(curr->val<p->val){
               prev=curr;
               curr=curr->next;
           } 
            
           if(p==curr){
               tail=p;
               p=p->next;
               continue;
           }
           
           tail->next=p->next;
           prev->next=p;
           p->next=curr;
           p=tail->next;
            
        }
        
        return dummy->next;
    }
};