//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        // detect cycle using BFS (toposort)
        int inDegree[v]={0};
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<v;i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(!inDegree[it]){
                    q.push(it);
                }
            }
        }
        return topo.size()!=v;
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