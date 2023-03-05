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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)return -1;
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> lvlSum;
        while(!q.empty()){
            int sze=q.size();
            long long sum=0;
            for(int i=0;i<sze;i++){
                sum+=q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            lvlSum.push_back(sum);
        }
        if(k>lvlSum.size()){
            return -1;
        }
        sort(lvlSum.begin(),lvlSum.end(),greater<>());
        return lvlSum[k-1];
    }
};