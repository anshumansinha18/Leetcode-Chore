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
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> m;
        
        ListNode* pos=head;
        while(pos && m[pos]==0){
            m[pos]++;
            pos=pos->next;
        }
        
        if(pos==nullptr) return false;
        else return true;
    }
};