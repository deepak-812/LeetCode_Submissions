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
private:
    void dfs(TreeNode* root,long long &result,long long num){
        if(!root)return;
        num=num*10+1LL*root->val;
        if(root->left==root->right){
            result+=num;
            return;
        }
        dfs(root->left,result,num);
        dfs(root->right,result,num);
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        long long result=0 , num=0;
        dfs(root,result,num);
        return result;
    }
};