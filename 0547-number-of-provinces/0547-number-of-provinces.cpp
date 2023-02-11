class Solution {
protected:
    void dfs(int node,vector<bool> &vis,vector<int> adj[]){
        vis[node]=true;
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n+1];
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};