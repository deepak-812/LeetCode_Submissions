//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int node,vector<int> adj[],vector<bool> &currPath,vector<bool> &vis){
        vis[node]=true , currPath[node]=true;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,adj,currPath,vis))return true;
            }
            else if(currPath[child]){
                return true;
            }
        }
        currPath[node]=false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool> currPath(v,false) , vis(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(i,adj,currPath,vis))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends