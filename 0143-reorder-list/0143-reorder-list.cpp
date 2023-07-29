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
        
          ListNode* p=nullptr, *t=nullptr, *c=head;
        while(c->next!=t){
            p=c;
            c=c->next;
            ListNode* x=p;
            while(x->next!=t)
                x=x->next;
            t=x;
            p->next=t;
            t->next=c;
        }
        c->next=nullptr;
    }
};