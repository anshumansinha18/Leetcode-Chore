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
    
    void merge(ListNode* &low, ListNode* high){
        ListNode* i=low;
        ListNode* j=high;
        ListNode* dummy1=new ListNode(INT_MAX);
        ListNode* dummy2=new ListNode(INT_MIN);
        dummy1->next=low;
        dummy2->next=high;
        ListNode *pi=dummy1;
        ListNode* pj=dummy2;
        
        while(i && j){
           if(i->val>j->val){
               if(i==low) low=j;
               pi->next=j;
               j=j->next;
               pj->next->next=i;
               pj->next=j;
               pi=pi->next;
           } else{
               pi=i;
               i=i->next;
           }
        }
        
        if(j){
            pi->next=j;
        }
    }
    
    ListNode* calcMid(ListNode* h){
        ListNode* fast=h;
        ListNode* slow=h;
        
        if(fast->next->next==nullptr) return h;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
    
    void mergeSort(ListNode* &head){
        
        if(head==nullptr || head->next==nullptr) return;
        
        ListNode* mid = calcMid(head);
        ListNode* low=head;
        ListNode* high=mid->next;
        mid->next=nullptr;
        
        mergeSort(low);
        mergeSort(high);
        
        merge(low, high);
        head=low;
        
        
        
    }
    ListNode* sortList(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr) return head;
        
        mergeSort(head);
        return head;
    }
};