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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(q.empty()==false){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                TreeNode* curr=q.front().first;
                pair<int,int> p=q.front().second;
                int x=p.first;
                int y=p.second;
                mp[x][y].emplace(curr->val);
                if(curr->left){
                    q.push({curr->left,{x-1,y+1}});
                }
                if(curr->right){
                    q.push({curr->right,{x+1,y+1}});
                }
                q.pop();
            }
        }
        for(auto it:mp){
            vector<int> v;
            for(auto it2:it.second){
                for(auto c:it2.second){
                    v.push_back(c);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};