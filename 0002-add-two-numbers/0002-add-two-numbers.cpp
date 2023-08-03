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
    
    void addAtTail(ListNode* &head, int val){
        ListNode* new_node = new ListNode(val);
        if(head==nullptr){
            head=new_node;
            return;
        }
        ListNode* pos = head;
        while(pos->next){
            pos=pos->next;
        }
        pos->next=new_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pos1=l1;
        ListNode* pos2 = l2;
        ListNode* head=nullptr;
        int carry=0;
        while(pos1 && pos2){
            int sum=pos1->val+pos2->val;
            cout<<sum<<" ";
            if((sum+carry)/10==0){
                addAtTail(head,sum+carry);
                carry=0;
            }else{
                addAtTail(head, (sum+carry)%10);
                carry=1;
            }
            pos1=pos1->next;
            pos2=pos2->next;
        }
        
        while(pos1){
            int sum=pos1->val;
            
            if((sum+carry)/10==0){
                addAtTail(head, sum+carry);
                carry=0;
            }else{
                addAtTail(head, (sum+carry)%10);
                carry=1;
            }
            pos1=pos1->next;
        }
        
        while(pos2){
            int sum=pos2->val;
            
            if((sum+carry)/10==0){
                addAtTail(head, sum+carry);
                carry=0;
            }else{
                addAtTail(head, (sum+carry)%10);
                carry=1;
            }
            pos2=pos2->next;
        }
        
        if(carry==1){
            addAtTail(head, carry);
        }
        
        return head;
    }
};