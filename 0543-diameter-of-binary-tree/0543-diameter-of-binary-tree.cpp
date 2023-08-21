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
    int maxim=0;
    int calc(TreeNode* root){
        if(!root) return 0;
        
        int l=calc(root->left);
        int r = calc(root->right);
        maxim = max(maxim, l+r);
        return max(l, r)+1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        calc(root);
        return maxim;
    }
};