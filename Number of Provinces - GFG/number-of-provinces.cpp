//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=true;
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,vis,adj);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> grid, int v) {
        // code here
        vector<int> adj[v+1];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(grid[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int ans=0;
        // vector<vector<bool>> vis(v,vector<bool>(n,false));
        vector<int> vis(v+1,false);
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                dfs(i,vis,adj) , ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends