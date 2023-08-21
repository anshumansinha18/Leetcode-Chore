/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool answer=true;
    void inorder(TreeNode* p, TreeNode* q){
        if(p && q){
            inorder(p->left, q->left);
            if(p->val != q->val){
                answer=false;
            }
            inorder(p->right, q->right);
        }
        else if(p && !q){
            answer=false;
            return;
        }else if(q && !p){
            answer=false;
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
         inorder(p, q);
        return answer;
    }
};