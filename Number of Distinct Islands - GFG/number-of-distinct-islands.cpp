//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
  private:
    int row,col;
    set<vector<pair<int,int>>> st;
    bool isValid(int r,int c,vector<vector<bool>> &vis,vector<vector<int>> &grid){
        if(r<0 || c<0 || r>=row || c>=col || vis[r][c] || !grid[r][c])return false;
        return true; 
    }
    void dfs(int r,int c,int baser,int basec,vector<pair<int,int>> &v,vector<vector<bool>> &vis,vector<vector<int>> &grid){
    vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
    vis[r][c]=true;
    pair<int,int> pr={r-baser,c-basec};
    v.push_back(pr);
    for(int i=0;i<4;i++){
        if(isValid(r+dy[i],c+dx[i],vis,grid)){
            dfs(r+dy[i],c+dx[i],baser,basec,v,vis,grid);
        }
    }
  }
  public:
    int countDistinctIslands(vector<vector<int>> &grid){
    row=grid.size() , col=grid[0].size();
    vector<vector<bool>> vis(row,vector<bool>(col,false));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!vis[i][j] && grid[i][j]){
                vector<pair<int,int>> v;
                dfs(i,j,i,j,v,vis,grid);
                st.emplace(v);
            }
        }
    }
    return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends