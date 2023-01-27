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
    int currSum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return root;
        }
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        if(root->right)dfs(root->right);
        currSum+=root->val;
        root->val=currSum;
        dfs(root->left);
    }
};