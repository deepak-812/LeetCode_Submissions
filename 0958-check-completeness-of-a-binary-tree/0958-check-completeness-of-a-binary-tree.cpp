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
    void dfs(TreeNode* root,int lvl,int &h){
        if(!root){
            return;
        }
        h=max(lvl,h);
        dfs(root->left,lvl+1,h);
        dfs(root->right,lvl+1,h);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)return false;
        queue<TreeNode*> q;
        stack<TreeNode*> stk;
        stk.push(root);
        q.push(root);
        int h=0,lvl=0;
        dfs(root,0,h);
        while(!q.empty()){
            int sze=q.size();
            if(lvl<h && sze<int(pow(2,lvl))){
                return false;
            }
            while(!stk.empty()){
                while(!stk.empty() && stk.top()->left==stk.top()->right){
                    stk.pop();
                }
                if(!stk.empty()){
                    if(stk.top()->left==NULL && stk.top()->right)return false;
                    stk.pop();
                }
                while(!stk.empty()){
                    if(stk.top()->left==NULL || stk.top()->right==NULL){
                        return false;
                    }
                    stk.pop();
                }
            }
            for(int i=0;i<sze;i++){
                TreeNode* curr=q.front();
                if(curr->left){
                    q.push(curr->left);
                    stk.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                    stk.push(curr->right);
                }
                q.pop();
            }
            lvl++;
        }
        
        return true;
    }
};