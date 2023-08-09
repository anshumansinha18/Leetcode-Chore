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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        map<TreeNode*, int> visited;
        vector<int> res;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                visited[root]=1;
                st.push(root->right);
                root=root->left;
            }
          else{
                root=st.top();
                st.pop();
              if(visited[root]){
                  res.push_back(root->val);
                  root=nullptr;
              }
            }
        }
        
        return res;
    }
};