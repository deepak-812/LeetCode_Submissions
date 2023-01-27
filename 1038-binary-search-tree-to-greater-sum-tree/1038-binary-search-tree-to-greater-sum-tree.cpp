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
    TreeNode* bstToGst(TreeNode* root) {
        int currSum=0;
        dfs(root,currSum);
        return root;
    }
    void dfs(TreeNode* root,int &currSum){
        if(!root){
            return ;
        }
        if(root->right)dfs(root->right,currSum);
        currSum+=root->val;
        root->val=currSum;
        dfs(root->left,currSum);
    }
};