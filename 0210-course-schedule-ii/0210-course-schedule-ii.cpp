class Solution {   
public:
    vector<int> findOrder(int n, vector<vector<int>>& nums) {
        // kahn's algorithm based solution (BFS with topological sort)
       vector<int> adj[n];
        for(int i=0;i<nums.size();i++){
            adj[nums[i][0]].push_back(nums[i][1]);
        }
        stack<int> stk;
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            stk.push(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        vector<int> ans;
        if(stk.size()<n){
            return ans;
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};