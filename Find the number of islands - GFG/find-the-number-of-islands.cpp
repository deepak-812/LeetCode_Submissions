//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int m,n;
    bool isValid(int x,int y,vector<vector<char>> &grid,vector<vector<bool>> &vis){
        if(x<0 || x>=n || y<0 || y>=m)return false;
        if(vis[x][y] || grid[x][y]=='0')return false;
        return true;
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n=grid.size() , m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        vector<int> drX={-1,0,1,0,1,-1,-1,1};
        vector<int> drY={0,-1,0,1,-1,-1,1,1};
        int cc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cc++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=true;
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int a=0;a<8;a++){
                            if(isValid(x+drX[a],y+drY[a],grid,vis)){
                                vis[x+drX[a]][y+drY[a]]=true;
                                q.push({x+drX[a],y+drY[a]});
                            }
                        }
                    }
                }
            }
        }
        return cc;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends