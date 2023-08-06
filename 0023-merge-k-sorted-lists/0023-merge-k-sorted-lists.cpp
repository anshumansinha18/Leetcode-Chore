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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode();
        ListNode* x=dummy;
        while(true){
            ListNode* smallest = nullptr;
            int small=INT_MAX;
            int n=lists.size();
            for(int i=0;i<n;i++){
                if(lists[i] && lists[i]->val<small){
                    small=lists[i]->val;
                    smallest=lists[i];
                }
            }
            
            if(smallest==nullptr) break;
            x->next=smallest;
            x=x->next;
            
            for(int j=0;j<n;j++){
                if(lists[j]==smallest){
                    lists[j]=lists[j]->next;
                    break;
                }
            }
        }
        return dummy->next;
    }
};