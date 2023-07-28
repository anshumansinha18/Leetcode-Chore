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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head=nullptr;
        
        if(list1==nullptr && list2==nullptr)
            return head;
        else if(list1==nullptr && list2!=nullptr)
            return list2;
        else if(list1!=nullptr && list2==nullptr)
            return list1;
        
        if(list1->val<list2->val){
            head=list1;
            list1=list1->next;
        }
        else{ head=list2; list2=list2->next;}
        
        
        ListNode* k = head;
        
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                k->next=list1;
                list1 =list1->next;
            }else{
                k->next=list2;
                list2=list2->next;
            }
            k=k->next;
        }
        
        while(list1!=nullptr){
            k->next=list1;
            list1=list1->next;
            k=k->next;
        }
        
        while(list2!=nullptr){
            k->next=list2;
            list2=list2->next;
            k=k->next;
        }
        return head;
    }
};