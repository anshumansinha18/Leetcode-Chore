/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                
        ListNode* x=headA;
        ListNode* y=headB;
        bool xDir=false;
        bool yDir=true;
        while(x!=y){
           if(x->next==nullptr){
               x= xDir ? headA: headB;
               xDir=!xDir;
           }else x=x->next;
            
            if(y->next==nullptr){
                y=yDir ? headA:headB;
                yDir=!yDir;
            }else y=y->next;
            
            if(x==headA && y==headB) return 0;
        }
        
        return x;
    }
};