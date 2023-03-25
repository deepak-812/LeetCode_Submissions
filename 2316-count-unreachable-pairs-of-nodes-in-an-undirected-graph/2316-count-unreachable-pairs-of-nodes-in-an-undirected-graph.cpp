class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &vis,int &nodes){
        vis[node]=true;
        nodes++;
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,adj,vis,nodes);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> vis(n,false);
        vector<int> v;
        for(int i=0;i<edges.size();i++){
            int u,v;
            u=edges[i][0] , v=edges[i][1];
            adj[u].push_back(v) , adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            int nodes=0;
            if(!vis[i]){
                dfs(i,adj,vis,nodes);
                v.push_back(nodes);
            }
        }
        vector<int> suffixSum(v.begin(),v.end());
        long long ans=0;
        for(int i=v.size()-2;i>=0;i--){
            ans+=1LL*suffixSum[i+1]*v[i];
            suffixSum[i]=v[i]+suffixSum[i+1];
        }
        return ans;
    }
};