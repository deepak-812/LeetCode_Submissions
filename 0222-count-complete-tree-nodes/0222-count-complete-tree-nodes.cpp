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
    int countNodes(TreeNode* root) {
        int ans=0;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                TreeNode* curr=q.front();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                ans++ , q.pop();
            }
        }
        return ans;
    }
};