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
    int maxLevelSum(TreeNode* root) {
        int minLvl,currLvl=0;
        long long sum=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            currLvl++;
            int sze=q.size();
            int currSum=0;
            for(int i=0;i<sze;i++){
                currSum+=q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(currSum>sum){
                minLvl=currLvl;
                sum=currSum;
            }
        }
        return minLvl;
    }
};