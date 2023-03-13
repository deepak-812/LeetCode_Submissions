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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int sze=q.size();
            if(sze%2!=0 && lvl>0)return false;
            vector<int> v;
            for(int i=0;i<sze;i++){
                TreeNode* curr=q.front();
                if(curr->left){
                    q.push(curr->left);
                    v.push_back(curr->left->val);
                }
                else{
                    v.push_back(-1000);
                }
                if(curr->right){
                    q.push(curr->right);
                    v.push_back(curr->right->val);
                }
                 else{
                    v.push_back(-1000);
                }
                q.pop();
            }
            for(int i=0,j=v.size()-1;i<j;i++,j--){
                if(v[i]!=v[j])return false;
            }
            lvl++;
        }
        return true;
    }
};