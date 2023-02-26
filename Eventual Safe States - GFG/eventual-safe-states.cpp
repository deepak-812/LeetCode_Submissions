//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfs(int node,vector<bool> &vis,vector<bool> &pathVis,vector<int> adj[],vector<bool> &check){
        vis[node]=true , pathVis[node]=true;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,vis,pathVis,adj,check))return true;
            }
            else if(pathVis[child]){
                return true;
            }
        }
        pathVis[node]=false , check[node]=true;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<bool> check(v,false);
        vector<bool> vis(v,false) , pathVis(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,adj,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<v;i++){
            if(check[i]){
                ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends