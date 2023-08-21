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
    
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        int right=solve(root->right);
        int diff = abs(left-right);
        if(answer && diff>1) answer=false;
        return max(right,left)+1;
        
    }
    bool isBalanced(TreeNode* root) {
           solve(root);
        return answer;
           
    }
};