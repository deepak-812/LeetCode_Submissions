class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &vis,int &edges,int &vertex){
        vertex++;
        vis[node]=true;
        for(auto it:adj[node]){
            edges++;
            if(!vis[it]){
                dfs(it,adj,vis,edges,vertex);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<bool> vis(n,false);
        for(int i=0;i<connections.size();i++){
            int u,v;
            u=connections[i][0] , v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int edges,cc=0,extras=0,vertex;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vertex=0 , edges=0;
                cc++ , dfs(i,adj,vis,edges,vertex);
                if(edges==0)continue;
                extras+=edges/2-vertex+1;
            }
        }
        if(cc==1)return 0;
        if(extras<cc-1)return -1;
        return cc-1;
    }
};