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
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    int calc(TreeNode* root){
        int l = height(root->left);
        int r = height(root->right);
        return l+r;
        
    }
    void inorder(TreeNode* root){
        if(!root) return;
        
        diameterOfBinaryTree(root->left);
        maxim = max(maxim, calc(root));
        diameterOfBinaryTree(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        inorder(root);
        return maxim;
    }
};