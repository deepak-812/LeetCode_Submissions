//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool> vis(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i]=true;
                while(!q.empty()){
                    int node=q.front().first;
                    int par=q.front().second;
                    q.pop();
                    for(auto child:adj[node]){
                        if(!vis[child]){
                            q.push({child,node});
                            vis[child]=true;
                        }
                        else if(par!=child){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends