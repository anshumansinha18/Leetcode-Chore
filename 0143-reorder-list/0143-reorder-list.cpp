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
    void reorderList(ListNode* head) {
          if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
              return;
        
         stack<ListNode*> st;
        
         ListNode *it = head;
         while(it!=nullptr){
             st.push(it);
             it=it->next;
         }
          
          ListNode *next = head->next;
          ListNode *curr= head;
          while(curr->next->next!=curr){
            
              curr->next=st.top();
              curr=next;
              st.top()->next = curr;
              next=next->next;
              st.pop();
          }
        
       curr->next=nullptr;
        
        
    }
};