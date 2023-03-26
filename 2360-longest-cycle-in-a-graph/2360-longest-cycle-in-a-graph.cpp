class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &vis,int &ans,int cn,int p){
        vis[node]=true;
        cn++;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ans,cn,p);
            }
            else if(vis[it] && it==p){
                ans=max(cn,ans);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> vis(n,false);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[edges[i]].push_back(i);
            }
        }
        int ans=-1;
        int cycleNodes=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,ans,cycleNodes,i);
            }
        }
        return ans;
    }
};