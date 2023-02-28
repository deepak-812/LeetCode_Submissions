//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v) , adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        vector<int> dist(n,INT_MAX);
        queue<int> q;
        q.push(src);
        dist[src]=0;
        vis[src]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    dist[it]=dist[node]+1;
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends