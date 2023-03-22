class Solution {
private:
    void dfs(int node,vector<pair<int,int>> adj[],vector<bool> &vis,int &ans){
        vis[node]=true;
        for(auto it:adj[node]){
            int child = it.first;
            int wt = it.second;
            ans=min(ans,wt);
            if(!vis[child]){
                dfs(child,adj,vis,ans);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        vector<bool> vis(n+1,false);
        int ans=INT_MAX;
        for(int i=0;i<roads.size();i++){
            int u,v,wt;
            u=roads[i][0] , v=roads[i][1] , wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        dfs(1,adj,vis,ans);
        return ans;
    }
};