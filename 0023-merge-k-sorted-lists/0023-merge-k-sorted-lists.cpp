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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        
        ListNode* x= dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                x->next=l1;
                l1=l1->next;
            }else{
                x->next=l2;
                l2=l2->next;
            }
            x=x->next;
        }
        
        while(l1){
            x->next=l1;
            l1=l1->next;
            x=x->next;
        }
        
        while(l2){
            x->next=l2;
            l2=l2->next;
            x=x->next;
        }
        
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        int n = lists.size();
        if(n==0) return nullptr;    
        while(n>1){
            
            for(int i=0;i< (n/2);i++){
                lists[i]=mergeTwoLists(lists[i], lists[n-i-1]);
            }
            
            n=(n+1)/2;
        }
        
        return lists[0];
        
    }
};