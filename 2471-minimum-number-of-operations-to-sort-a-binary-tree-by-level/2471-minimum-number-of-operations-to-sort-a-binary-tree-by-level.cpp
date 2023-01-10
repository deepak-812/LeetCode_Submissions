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
    int countSwaps(vector<int> &v){
        unordered_map<int,int> mp;
        vector<int> a;
        for(int i=0;i<v.size();i++){
            mp[v[i]]=i;
            a.push_back(v[i]);
        }
        sort(a.begin(),a.end());
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=v[i]){
                v[mp[a[i]]]=v[i];
                mp[v[i]]=mp[a[i]];
                mp[a[i]]=i;
                v[i]=a[i];
                cnt++;
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(q.empty()==false){
            int sze=q.size();
            vector<int> v;
            for(int i=0;i<sze;i++){
                TreeNode* curr=q.front();
                v.push_back(curr->val);
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans+=countSwaps(v);
        }
        return ans;
    }
};