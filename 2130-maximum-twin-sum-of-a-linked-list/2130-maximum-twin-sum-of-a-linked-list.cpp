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
    
    ListNode* calcMid(ListNode* head){
        ListNode* fast=head, *slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = calcMid(head);
        ListNode* it=mid;
        cout<<mid->val;
        int res=0;
        stack<ListNode*> st;
        
        while(it!=nullptr){
            st.push(it);
            it=it->next;
        }
        
        it=head;
        while(!st.empty()&& it!=mid){
            res=max(it->val+st.top()->val, res);
            it=it->next;
            st.pop();
        }
        
        return res;
        
    }
};