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
    TreeNode* last;
    void flatten(TreeNode* root) {
        last=NULL;
        root=dfs(root);
    }
    TreeNode* dfs(TreeNode* root){
        if(!root){
            return root;
        }
        if(root->left==root->right){
            last=root;
        }
        TreeNode* lft=dfs(root->left);
        if(root->left && root->right){
            if(last){
                TreeNode* prvLeaf=last;
                prvLeaf->right=dfs(root->right);
            }
            root->right=lft;
        }
        else if(lft){
            root->right=lft;
        }
        else{
            root->right=dfs(root->right);
        }
        root->left=NULL;
        return root;
    }
};