//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  void dfs(int node,vector<pair<int,int>> adj[],vector<bool> &vis,vector<int> &sortPath){
      vis[node]=true;
      for(auto child:adj[node]){
          int ff=child.first;
          int ss=child.second;
          sortPath[ff]=min(sortPath[node]+ss,sortPath[ff]);
          dfs(ff,adj,vis,sortPath);
      }
  }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int> sortPath(n,INT_MAX);
        vector<bool> vis(n,false);
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n,0);
        sortPath[0]=0;
        dfs(0,adj,vis,sortPath);
        for(int i=0;i<n;i++){
            if(sortPath[i]==INT_MAX){
                sortPath[i]=-1;
            }
        }
        return sortPath;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends