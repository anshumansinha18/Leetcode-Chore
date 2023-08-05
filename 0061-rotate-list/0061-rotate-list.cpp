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
       int findLength(ListNode* &tail){
        int count=1;
        while(tail->next){
            count++;
           tail=tail->next;
        }

        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        
           ListNode* tail=head;
        int length=findLength(tail);
        k=k%length;
        if(k==0) return head;
        int count=1;
        ListNode* curr=head;
        while(count<length-k){
            curr=curr->next;
            count++;
        }
     
        ListNode* newHead=curr->next;
        curr->next=nullptr;
        tail->next=head;
        return newHead;
        
    }
};