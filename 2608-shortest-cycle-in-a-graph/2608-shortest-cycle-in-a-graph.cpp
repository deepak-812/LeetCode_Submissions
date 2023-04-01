class Solution {
public:
    void dfs(int node,int d,int par,unordered_map<int,int> &mp,vector<int> adj[],vector<bool> &vis,int &ans){
        vis[node]=true;
        mp[node]=d;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,d+1,node,mp,adj,vis,ans);
            }
            else if(mp.count(it) && it!=par){
                ans=min(ans,abs(d-mp[it])+1);
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int u,v;
            u=edges[i][0] , v=edges[i][1];
            adj[u].push_back(v) , adj[v].push_back(u);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            unordered_map<int,int> mp;
            dfs(i,0,-1,mp,adj,vis,ans);
        }
        return ans==INT_MAX?-1:ans;
    }
};