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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *p = head;
        int left = k;
        int n=0;
        while(p!= NULL)
        {
            n++;
            p=p->next;
        }
        p=head;
        cout<<n<<endl;
        while(p!=NULL && --left)
        {
            p=p->next;
        }
    
        
        ListNode* x = head;
        int right = n-k+1;
        while(x!=NULL && --right)
        {
            x=x->next;
        }
    
     
        swap(x->val, p->val);
        return head;
    }
};