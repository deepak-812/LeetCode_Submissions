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
    int ans,lvl;
    int deepestLeavesSum(TreeNode* root) {
        ans=0,lvl=-1;
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode* root,int l){
        if(!root){
            return;
        }
        if(root->left==root->right){
            if(l>lvl){
                ans=root->val;
                lvl=l;
            }
            else if(l==lvl)ans+=root->val;
        }
        dfs(root->left,l+1);
        dfs(root->right,l+1);
    }
};