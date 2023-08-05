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
            ListNode* ahead = curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        head=prev;
        return head;
    }
    
    int findLength(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        
        return count;
    }
    
    ListNode* findPoint(ListNode* head, int k){
        ListNode* L = head;
        ListNode* R = head;
        
        int x=0;
        while(R->next){
            if(x>=k){
                L=L->next;
            }
            R=R->next;
            x++;
        }
        
        return L;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int length = findLength(head);
        
        k=k%length;
        
        ListNode* breakPoint = findPoint(head, k);
        
        ListNode* lhead=head;
        ListNode* rhead=breakPoint->next;
        
        breakPoint->next=nullptr;
        
        ListNode* reversedLHead= reverseList(lhead);
        ListNode* reversedRHead = reverseList(rhead);
        
        lhead->next = reversedRHead;
        
        
        return reverseList(reversedLHead);
        
    }
};