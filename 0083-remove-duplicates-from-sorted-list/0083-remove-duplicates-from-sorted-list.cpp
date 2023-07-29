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
        if(head==nullptr || head->next==nullptr) return head;
        
        //add dummy node:
        ListNode *new_node = new ListNode(-101);
        new_node->next=head;
        head=new_node;
        
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=nullptr){
            if(curr->val==prev->val){
                ListNode* t=curr;
                prev->next=curr->next;
                curr=curr->next;
                delete t;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        
        return head->next;
        
    }
};