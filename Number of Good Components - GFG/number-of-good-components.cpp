//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool bfs(int node,vector<vector<int>> &adj,vector<bool> &vis){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        bool flag=true;
        int edges=adj[node].size();
        int nodes=0;
        while(!q.empty()){
            int nd=q.front();
            nodes++;
            q.pop();
            if(adj[nd].size()!=edges){
                flag=false;
            }
            for(auto child:adj[nd]){
                if(!vis[child]){
                    vis[child]=true;
                    q.push(child);
                }
            }
        }
        return edges==nodes-1 && flag;
    }
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int ans=0;
        vector<bool> vis(V+1,false);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends