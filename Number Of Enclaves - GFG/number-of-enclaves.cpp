//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
      int row,col;
      bool isValid(int r,int c,vector<vector<bool>> &vis,vector<vector<int>> &grid){
          if(r<0 || c<0 || r>=row || c>=col || vis[r][c] || !grid[r][c])return false;
          return true;
      }
      void dfs(int r,int c,vector<vector<bool>> &vis,vector<vector<int>> &grid){
          vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
          vis[r][c]=true;
          for(int i=0;i<4;i++){
              if(isValid(r+dy[i],c+dx[i],vis,grid)){
                  dfs(r+dy[i],c+dx[i],vis,grid);
              }
          }
      }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        row=grid.size() , col=grid[0].size();
        vector<vector<bool>> vis(row,vector<bool> (col,false));
        for(int j=0;j<col;j++){
            if(!vis[0][j] && grid[0][j]){
                dfs(0,j,vis,grid);
            }
            if(!vis[row-1][j] && grid[row-1][j]){
                dfs(row-1,j,vis,grid);
            }
        }
        for(int i=0;i<row;i++){
            if(!vis[i][0] && grid[i][0]){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][col-1] && grid[i][col-1]){
                dfs(i,col-1,vis,grid);
            }
        }
        int ans=0;
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(!vis[i][j] && grid[i][j]){
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends